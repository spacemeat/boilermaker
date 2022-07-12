from ...plugin import Provider, PluginCollection
from ...props import Scribe, Props, PropertyBag
from ...enums import BomaEnumType
from ...grokCpp.grokCpp import GrokCpp
from pathlib import Path
import os
import re


arrayRef = re.compile('(.*)-(\d+)$')

class ChainStruct:
    def __init__(self, structName, providerName, sType):
        self.structName = structName
        self.providerName = providerName
        self.sType = sType


class StructureChain:
    def __init__(self, name, mainStructName, mainStructStype, baseProviderName, baseProviderStructName, baseProviderMemberName, hasSetters, chainStructs):
        self.name = name
        self.mainStructName = mainStructName
        self.mainStructStype = mainStructStype
        self.baseProviderName = baseProviderName
        self.baseProviderStructName = baseProviderStructName
        self.baseProviderMemberName = baseProviderMemberName
        self.hasSetters = hasSetters
        self.chainStructs = chainStructs

    def getChainStructs(self):
        for struc in self.chainStructs:
            yield struc


class vulkanProvider(Provider):
    def start(self, runDefs, props):
        print (f'starting vulkanProvider')
        self.runDefs = runDefs
        self.props = props
        self.parsedEnums = {}
        self.parsedChainStructEnums = {}
        self.parsedChainStructs = {}

    def do(self, op, seq):
        print (f'vulkanProvider doing op {op} at sequence {seq}')
        if op == 'parseSources':
            self.parseSources()
        elif op == 'makeEnums':
            self.makeEnums()
        elif op == 'makeChainStructs':
            self.makeChainStructs()

    def stop(self):
        print (f'stopping vulkanProvider')

    def parseSources(self):
        s = Scribe(self.props)
        projectDir = Path(s.getXProp('projectDir'))

        # namespace to file system
        def nsToFs(string):
            return string.replace('.', '/')
        self.props.setProp('nsToFs', nsToFs)

        # namespace to code
        def nsToCode(string):
            return string.replace('.', '::')
        self.props.setProp('nsToCode', nsToCode)

        # provider member to code
        # can turn 'limits_maxComputeWorkGroupCount_0' to 'limits.maxComputeWorkGroupCount[0]'
        def toReference(providerMember):
            #if 'limits' in providerMember:
            #    breakpoint()
            string = providerMember
            if match := arrayRef.match(string):
                string = match[1] + '[' + match[2] + ']'
            string = string.replace('-', '.')
            return string
        self.props.setProp('toReference', toReference)

        def toMemberName(providerMember):
            string = providerMember.replace('-', '_')
            return string
        self.props.setProp('toMemberName', toMemberName)


        # relative paths for local #includes
        # TODO: Retire these for more precise relpath using utility fn
        self.props.setProp('headerToInl',    os.path.relpath(s.X('$inlineDir'), s.X('$headerDir')))
        self.props.setProp('srcToHeader',    os.path.relpath(s.X('$headerDir'), s.X('$sourceDir')))
        self.props.setProp('srcToInl',       os.path.relpath(s.X('$inlineDir'), s.X('$sourceDir')))

        sources = self.runDefs['sources']
        if type(sources) is str:
            sources = [sources]
            self.runDefs['sources'] = sources

        for source in sources:
            grok = GrokCpp(self.runDefs, self.props)

            parsedEnums, parsedChainStructEnums, parsedChainStructs = grok.processSource(
                source)

            self.parsedEnums.update(parsedEnums)
            self.parsedChainStructEnums.update(parsedChainStructEnums)
            self.parsedChainStructs.update(parsedChainStructs)

    def makeEnums(self):
        props = self.props
        anchors = self.props.getProp('anchors')
        if anchors and 'anchors' in anchors:
            anch = props['anchors']
            if 'vulkanEnums' in anch:
                props = anch['vulkanEnums']

        enums = {}
        #breakpoint()
        enums.update({k: self.makeEnum(v, props, True) for k, v in self.parsedEnums.items()})
        enums.update({k: self.makeEnum(v, props, False) for k, v in self.parsedChainStructEnums.items()})

        # update the boma enums dict with the new enums
        bomaEnums = self.props.getProp('bomaEnums')
        bomaEnums.update(enums)

    def makeEnum(self, grokkedEnum, props, alreadyDefined):
        propBag = props.props
        newBag = PropertyBag({
            'enumIsScoped': grokkedEnum.isScoped,
            'enumFlags': grokkedEnum.isFlags,
            'enumCodeCase': '',
            'enumCodePrefix': '',
            'enumCodeSuffix': ''
        })
        newBag.inherit(propBag)
        props = Props(newBag)   # every enum gets its own props

        et = BomaEnumType(grokkedEnum, props)

        return et

    def makeChainStructs(self):
        headers = self.runDefs['sources']

        structureChains = {}
        for rdcsName, rdcs in self.runDefs['structureChains'].items():
            sc = StructureChain(rdcs['structureChainName'], rdcs['mainStructName'], rdcs['mainStructStype'],
                rdcs['baseProviderName'], rdcs['baseProviderStructName'], rdcs['baseProviderMemberName'],
                rdcs['hasSetters'] == 'true',
                [ChainStruct(rdscm['structName'], rdscm['providerName'], rdscm['sType']) for rdscm in rdcs['chainStructs']])
            structureChains[rdcsName] = sc

        self.props.setProp('structureChainsHeaders', headers)
        self.props.setProp('structureChains', structureChains)

        def enumVals(providerStructEnum):
            grokkedEnum = self.parsedChainStructEnums.get(providerStructEnum + '_members')
            if grokkedEnum:
                for value in grokkedEnum.values:
                    yield value.name

        self.props.setProp('enumVals', enumVals)

        #self.removeAllFiles()
        s = Scribe(self.props)
        scribePath = PluginCollection(s.getXProp('pluginsDir')).locateScribe(self.runDefs['plugin'], self.runDefs['output'])
        print (s.X(f'$<in "{scribePath}">'))
