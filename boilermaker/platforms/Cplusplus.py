import os
from pathlib import Path

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums
from ..PlatformDef import PlatformDef




def reportEnums(enums):
    for name, values in enums.items():
        print (f"Enum found: {name}")
        for value in values:
            print (value)


def parseHeader(config, filename):
    # Find the location of the xml generator (castxml or gccxml)
    generator_path, generator_name = utils.find_xml_generator()

    # Configure the xml generator
    xml_generator_config = parser.xml_generator_configuration_t(
        xml_generator_path = generator_path,
        xml_generator = generator_name)

    # Parse the c++ file
    decls = parser.parse([filename], xml_generator_config)

    enums = {}

    # Get access to the global namespace
    global_namespace = declarations.get_global_namespace(decls)

    # Get access to the namespace
    ns = global_namespace.namespace("og")

    for decl in ns.declarations:
        if hasattr(decl, "elaborated_type_specifier"):
            if decl.elaborated_type_specifier == "enum":
                enumName = decl.partial_decl_string.replace('::', '.')[1:]
                enums[enumName] = decl.values

    for decl in ns.declarations:
        if hasattr(decl, "decl_type"):
            typedefName = decl.partial_decl_string.replace('::', '.')[1:]
            declType = decl.decl_type.decl_string.replace('::', '.')[1:]
            if declType in enums:
                enums[typedefName] = enums[declType]

    return enums


class CplusplusDef(PlatformDef):
    def __init__(self, node, backupDef=None):
        super().__init__(node, backupDef)
        self.seenTypes = []


    def getIncludeFiles(self):
        #configIncFiles = self.getValue(f'includeFiles')
        configIncFiles = self.node['includeFiles'].objectify()
        incFiles = []
        for inc in configIncFiles:
            if type(inc) == 'dict':
                incFiles.append((inc['file'], inc['system'] == 'true'))
            else:
                incFiles.append((inc, False))
        return incFiles


    def fixupScope(self, typeName):
        if typeName in ['vector', 'string', 'pair', 'array', 'optional', 'variant']:
            return 'std::' + typeName
        return typeName.replace('.', '::')


    def recordUseOfType(self, typeName):
        if typeName not in self.seenTypes:
            self.seenTypes.append(typeName)


    def getRecursiveType(self, typeNode):
        if typeNode.kind == humonEnums.NodeKind.VALUE:
            self.recordUseOfType(typeNode.value)
            return self.fixupScope(typeNode.value)

        typeTypeNode = typeNode['type']
        builtType = self.fixupScope(typeTypeNode.value)
        self.recordUseOfType(typeTypeNode.value)

        ofNode = typeNode['of']
        if ofNode:
            builtType = f"{builtType}<"
            if ofNode.kind == humonEnums.NodeKind.LIST:
                for i in range(0, len(ofNode)):
                    chNode = ofNode[i]
                    if i > 0:
                        builtType = f"{builtType}, "
                    builtType = f"{builtType}{self.getRecursiveType(chNode)}"
            elif ofNode.kind == humonEnums.NodeKind.DICT:
                builtType = f"{builtType}{self.getRecursiveType(ofNode)}"
            else:
                builtType = f"{builtType}{self.fixupScope(ofNode.value)}"
                self.recordUseOfType(ofNode.value)
            builtType = f"{builtType}>"

        return builtType


    def processPods(self, podsNode):
        pods = {}
        for i in range(0, podsNode.numChildren):
            podNode = podsNode[i]
            podName = podNode.key
            pods[podName] = {}
            for j in range(0, len(podNode)):
                memberNode = podNode[j]
                memberType = self.getRecursiveType(memberNode)
                pods[podName][memberNode.key] = memberType
        return pods


    def genCtorSignature(self, podName, pod):
        src = f'{podName}('
        for memberName, memberType in pod.items():
            if self.getSetting('const') == 'east':
                src += f'{memberType} const'
            else:
                src += f'const {memberType}'
            src += f' & {memberName}{", " if memberName != list(pod.keys())[-1] else ""}'
        src += ')'
        return src


    def generateHeader(self, pods):
        src = ''
        for typeName in self.seenTypes:
            if typeName == 'vector':
                src += '#include <vector>\n'
            elif typeName == 'string':
                src += '#include <string>\n'
            elif typeName == 'pair':
                src += '#include <utility>\n'
            elif typeName == 'array':
                src += '#include <array>\n'
            elif typeName == 'optional':
                src += '#include <optional>\n'
            elif typeName == 'variant':
                src += '#include <variant>\n'

        incFiles = self.getIncludeFiles()
        if incFiles:
            for incFile, isSystemInclude in incFiles:
                if isSystemInclude:
                    src += f'#include <{incFile}>\n'
                else:
                    src += f'#include "{incFile}"\n'
        src += '\n'

        indentChars = self.getIndent()
        indent = 0
        nsIndent = ''
        clIndent = indentChars * 1
        memberIndent = indentChars * 2

        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''

        if usingNamespace:
            src += f'{nsIndent}namespace {namespace}\n{nsIndent}{{\n'
            indent += 1

        for podName, pod in pods.items():
            src += f'''
{clIndent}class {podName}
{clIndent}{{
{clIndent}public:
{memberIndent}{self.genCtorSignature(podName, pod)}{noexceptStr};\n'''

            # copy ctr, copy assignment
            if not self.getFeature('copyable') == 'true':
                src += f'{memberIndent}{podName}('
                if eastConst:
                    src += f'{podName} const '
                else:
                    src += f'const {podName} '
                src += '& rhs) = delete;\n'

                src += f'{memberIndent}{podName} & operator =('
                if eastConst:
                    src += f'{podName} const '
                else:
                    src += f'const {podName} '
                src += '& rhs) = delete;\n'
            elif noexcept:
                src += f'{memberIndent}{podName}('
                if eastConst:
                    src += f'{podName} const '
                else:
                    src += f'const {podName} '
                src += '& rhs) noexcept;\n'

                src += f'{memberIndent}{podName} & operator =('
                if eastConst:
                    src += f'{podName} const '
                else:
                    src += f'const {podName} '
                src += '& rhs) noexcept;\n'

            # move ctr, move assignment
            if not self.getFeature('movable') == 'true':
                src += f'{memberIndent}{podName}({podName} && rhs) = delete;\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs) = delete;\n'
            elif noexcept:
                src += f'{memberIndent}{podName}({podName} && rhs){noexceptStr};\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs){noexceptStr};\n'

            # dtr
            src += f'{memberIndent}~{podName}();\n\n'

            # member getters
            for memberName, memberType in pod.items():
                if self.getFeature('getters') == 'true':
                    if eastConst:
                        src += f'{memberIndent}{memberType} const '
                    else:
                        src += f'{memberIndent}const {memberType} '
                    src += f'& get_{memberName}() const{noexceptStr};\n'
                    src += f'{memberIndent}{memberType} &       get_{memberName}(){noexceptStr};\n'
            src += '\n'

            # member setters
            for memberName, memberType in pod.items():
                if self.getFeature('setters') == 'true':
                    src += f'{memberIndent}void set_{memberName}('
                    if eastConst:
                        src += f'{memberType} const '
                    else:
                        src += f'const {memberType} '
                    src += f'& newVal) noexcept;\n'
            src += '\n'

            # TODO: other features here

            # members
            if self.getFeature('privateMembers') == 'true':
                src += f'{clIndent}private:\n'

            for memberName, memberType in pod.items():
                src += f'{memberIndent}{memberType} {memberName};\n'

            # end of class def
            src += f'{clIndent}}};\n\n'
            
            # TODO: Use computed path from defs file
            if self.getSetting('headerOnly') == 'true':
                src += f'#include "inl/_{podName}.inl.hpp"\n'

        if usingNamespace:
            src += f'{nsIndent}}}\n'
            indent -= 1

        return src


    def generateHeaderFile(self, pods):
        src = self.generateHeader(pods)

        outputPath = self.getOutputPath('header')
        Path(os.path.dirname(outputPath)).mkdir(parents=True, exist_ok=True)

        print (f"Building header: {outputPath}")
        f = open(f"{outputPath}", 'wt')
        print(src, file = f)
        f.close()


    def generateSrc(self, podName, pod):
        return '// just you wait, this is gonna be SO $$$$\n'


    def generateSrcFiles(self, pods):
        srcType = 'source'
        if self.getSetting('headerOnly'):
            srcType = 'inline'

        for podName, pod in pods.items():
            src = self.generateSrc(podName, pod)

            outputPath = self.getOutputPath(srcType, podName)
            Path(os.path.dirname(outputPath)).mkdir(parents=True, exist_ok=True)

            print (f"Building source: {outputPath}")
            f = open(f"{outputPath}", 'wt')
            print(src, file = f)
            f.close()


    def generateArtifacts(self, podsNode):
        pods = self.processPods(podsNode)
        self.generateHeaderFile(pods)
        self.generateSrcFiles(pods)
