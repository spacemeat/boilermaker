import os
from pathlib import Path, PurePath

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


def processHeader(filename):
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


def makeRelativePath(sourceDir, destinationPath):
    common = os.path.commonpath([sourceDir, destinationPath])
    relativePath = ''
    while str(sourceDir) != str(common):
        sourceDir = str(PurePath(sourceDir).parent)
        relativePath += '../'
    return os.path.join(relativePath, str(PurePath(destinationPath).relative_to(common)))


class CplusplusDef(PlatformDef):
    def __init__(self, node, defPath, backupDef=None):
        super().__init__(node, defPath, backupDef)
        self.seenTypes = []
        self.enums = {}


    def getIncludeFiles(self):
        configIncFiles = self.node['includeFiles'].objectify()  # TODO: don't objectify here
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
        elif typeName in self.pods:
            namespace = self.getSetting('namespace')
            return f'{namespace}::{typeName}' if namespace else typeName
        return typeName.replace('.', '::')


    def const(self, typee):
        eastConst = self.getSetting('const') == 'east'
        if eastConst:
            return f'{typee} const'
        else:
            return f'const {typee}'


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
                builtType += ', '.join([f'{self.getRecursiveType(chNode)}' for chNode in ofNode])
            elif ofNode.kind == humonEnums.NodeKind.DICT:
                builtType = f"{builtType}{self.getRecursiveType(ofNode)}"
            else:
                builtType = f"{builtType}{self.fixupScope(ofNode.value)}"
                self.recordUseOfType(ofNode.value)
            builtType = f"{builtType}>"

        return builtType


    def preprocess(self, podsNode):
        self.pods = {}
        for podNode in podsNode:
            podName = podNode.key
            self.pods[podName] = {}
            for memberNode in podNode:
                memberType = self.getRecursiveType(memberNode)
                self.pods[podName][memberNode.key] = memberType
        
        for incFile in self.getIncludeFiles():
            self.enums = {*self.enums, *processHeader(os.path.join(os.path.dirname(self.defPath), incFile[0]))}


    def genCtorSignature(self, podName, pod):
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        scope = f'{namespace}::' if usingNamespace else ''

        src = f'{podName}('
        for memberName, memberType in pod.items():
            src += f'{self.const(memberType)} & {memberName}{", " if memberName != list(pod.keys())[-1] else ""}'
        src += ')'
        return src


    def generateHeader(self):
        headerOnly = self.getSetting('headerOnly') == 'true'

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

        if self.getFeature('deserialize') == 'true':
                src += '#include <humon/humon.hpp>\n'

        incFiles = self.getIncludeFiles()
        if incFiles:
            for incFile, isSystemInclude in incFiles:
                if isSystemInclude:
                    src += f'#include <{incFile}>\n'
                else:
                    headerDir = os.path.dirname(self.getOutputPath('header'))
                    includePath = os.path.join(os.path.dirname(self.defPath), incFile)
                    relativeIncPath = makeRelativePath(headerDir, includePath)
                    src += f'#include "{relativeIncPath}"\n'
        src += '\n'

        if usingNamespace:
            src += f'{nsIndent}namespace {namespace}\n{nsIndent}{{\n'
            indent += 1

        for podName, pod in self.pods.items():
            src += f'''
{clIndent}class {podName}
{clIndent}{{
{clIndent}public:
{memberIndent}{self.genCtorSignature(podName, pod)}{noexceptStr};
'''
            if self.getFeature('defaultConstructible') == 'true':
                src += f'{memberIndent}{podName}(){noexceptStr};\n'

            if self.getFeature('deserialize') == 'true':
                src += f'{memberIndent}{podName}(hu::Node node){noexceptStr};\n'

            needSwap = False

            # copy ctr, copy assignment
            if not self.getFeature('copyable') == 'true':
                src += f'{memberIndent}{podName}({self.const(podName)} & rhs) = delete;\n'
                src += f'{memberIndent}{podName} & operator =({self.const(podName)} & rhs) = delete;\n'
            else:
                src += f'{memberIndent}{podName}({self.const(podName)} & rhs){noexceptStr};\n'
                src += f'{memberIndent}{podName} & operator =({podName} rhs){noexceptStr};\n'
                needSwap = True

            # move ctr, move assignment
            if not self.getFeature('movable') == 'true':
                src += f'{memberIndent}{podName}({podName} && rhs) = delete;\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs) = delete;\n'
            else:
                src += f'{memberIndent}{podName}({podName} && rhs){noexceptStr};\n'
                src += f'{memberIndent}{podName} & operator =({podName} && rhs){noexceptStr};\n'
                needSwap = True

            # dtr
            src += f'{memberIndent}{"virtual " if self.getFeature("virtualDestructor") == "true" else ""}~{podName}();\n'

            if needSwap:
                endl = '\n'
                src += f'''
{memberIndent}friend void swap({podName} & lhs, {podName} & rhs){noexceptStr}
{memberIndent}{{
{memberIndent}    using std::swap;
{"".join([f"{memberIndent}    swap(lhs.{v}, rhs.{v});{endl}" for v in pod.keys()])}{memberIndent}}}

'''

            # member getters
            for memberName, memberType in pod.items():
                if self.getFeature('getters') == 'true':
                    src += f'{memberIndent}{self.const(memberType)} & get_{memberName}() const{noexceptStr};\n'
                    src += f'{memberIndent}{memberType} &       get_{memberName}(){noexceptStr};\n'
            src += '\n'

            # member setters
            for memberName, memberType in pod.items():
                if self.getFeature('setters') == 'true':
                    src += f'{memberIndent}void set_{memberName}({self.const(memberType)} & newVal) noexcept;\n'
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
            if headerOnly:
                src += f'#include "inl/_{podName}.inl.hpp"\n'

        if usingNamespace:
            src += f'{nsIndent}}}\n'
            indent -= 1

        return src


    def generateHeaderFile(self):
        src = self.generateHeader()

        #outputPath = self.getOutputPath('header')
        headerPath = self.getOutputPath('header')
        Path(os.path.dirname(headerPath)).mkdir(parents=True, exist_ok=True)

        print (f"Building header: {headerPath}")
        f = open(f"{headerPath}", 'wt')
        print(src, file = f)
        f.close()


    def cavePerson(self, msg):
        if self.getSetting('cavepersonCtrs') == 'true':
            return f'std::cout << "{msg}\\n";\n'
        else:
            return ''


    def generateSrc(self, podName, pod):
        headerOnly = self.getSetting('headerOnly') == 'true'

        indentChars = self.getIndent()
        ind1 =     indentChars * 1
        ind____2 = indentChars * 2

        eastConst = self.getSetting('const') == 'east'
        noexcept = self.getSetting('noexcept') == 'true'
        noexceptStr = ' noexcept' if noexcept else ''
        namespace = self.getSetting('namespace')
        usingNamespace = namespace != ''
        if usingNamespace:
            scope = namespace + '::'

        src = ''
        if self.getSetting('cavepersonCtrs') == 'true':
            src += '#include <iostream>\n'

        if not headerOnly:
            headerPath = self.getOutputPath('header')
            headerFile = os.path.basename(headerPath)
            src += f'#include "../inc/{headerFile}"\n'

        # constructor
        src += f'''
{scope}{podName}::{self.genCtorSignature(podName, pod)}{noexceptStr}
: {', '.join([f"{v}({v})" for v in pod.keys()])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::ctr')}
}}
'''

        if self.getFeature('defaultConstructible') == 'true':
            src += f'''
{scope}{podName}::{podName}(){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::default ctr')}
}}
'''

        dq = '"'
        if self.getFeature('deserialize') == 'true':
            src += f'''
{scope}{podName}::{podName}(hu::Node node){noexceptStr}
: {', '.join([f"{v}(node / {dq}{v}{dq})" for v in pod.keys()])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::ctr from humon')}
}}
'''

        needSwap = False

        if self.getFeature('copyable') == 'true':
            src += f'''
{scope}{podName}::{podName}({self.const(podName)} & rhs){noexceptStr}
: {', '.join([f"{v}(rhs.{v})" for v in pod.keys()])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::copy ctr')}
}}
'''
            src += f'''
{scope}{podName} & {scope}{podName}::operator =({scope}{podName} rhs){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::copy assign')}
{ind1}swap(*this, rhs);
{ind1}return *this;
}}
'''
            needSwap = True

        if self.getFeature('movable') == 'true':
            src += f'''
{scope}{podName}::{podName}({scope}{podName} && rhs){noexceptStr}
: {', '.join([f"{v}(std::move(rhs.{v}))" for v in pod.keys()])}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::move ctr')}
}}
'''
            src += f'''
{scope}{podName} & {scope}{podName}::operator =({scope}{podName} && rhs){noexceptStr}
{{
{ind1}{self.cavePerson(f'{scope}{podName}::move assign')}
{ind1}swap(*this, rhs);
{ind1}return *this;
}}
'''
            needSwap = True

        # dtr
        src += f'''
{"virtual " if self.getFeature("virtualDestructor" == "true") else ""}{scope}{podName}::~{podName}()
{{
{ind1}{self.cavePerson(f'{scope}{podName}::dtr')}
}}
'''

        # member getters
        for memberName, memberType in pod.items():
            if self.getFeature('getters') == 'true':
                src += f'''
{self.const(memberType)} & {scope}{podName}::get_{memberName}() const{noexceptStr}
{{
{ind1}return {memberName};
}}
'''
                src += f'''
{memberType} & {scope}{podName}::get_{memberName}(){noexceptStr}
{{
{ind1}return {memberName};
}}
'''
        src += '\n'

        # member setters
        for memberName, memberType in pod.items():
            if self.getFeature('setters') == 'true':
                src += f'''
void {scope}{podName}::set_{memberName}({self.const(memberType)} & newVal) noexcept
{{
{ind1}{memberName} = newVal;
}}
'''
        src += '\n'

        return src


    def generateSrcFiles(self):
        srcType = 'source'
        if self.getSetting('headerOnly') == 'true':
            srcType = 'inline'

        for podName, pod in self.pods.items():
            src = self.generateSrc(podName, pod)

            srcPath = self.getOutputPath(srcType, podName)
            Path(os.path.dirname(srcPath)).mkdir(parents=True, exist_ok=True)

            print (f"Building source: {srcPath}")
            f = open(f"{srcPath}", 'wt')
            print(src, file = f)
            f.close()


    def generateArtifacts(self):
        self.generateHeaderFile()
        self.generateSrcFiles()
