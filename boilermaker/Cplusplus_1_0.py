import os
from pathlib import Path

from pygccxml import utils
from pygccxml import declarations
from pygccxml import parser

from humon import humon, enums as humonEnums


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


def processCplusplus_1_0(languageConfig, langNode):
    languageConfig['includeFiles'] = []
    includeNode = langNode['includeFiles']
    if includeNode:
        for i in range(0, len(includeNode)):
            fileNode = includeNode[i]
            if fileNode.kind == humonEnums.NodeKind.DICT:
                fileFileNode = fileNode['file']
                systemNode = fileNode['system']
                # TODO: the preprocessor thing
                enums = parseHeader(languageConfig, fileFileNode.value)
                reportEnums(enums)
                languageConfig['includeFiles'].append((
                    fileFileNode.value, 
                    systemNode and systemNode.value.lower == "true", enums))
            else:
                # TODO: the preprocessor thing
                enums = parseHeader(languageConfig, fileNode.value)
                reportEnums(enums)
                languageConfig['includeFiles'].append((fileNode.value, False, enums))


def getIndent(languageConfig):
    indent = languageConfig['indent']
    if not indent:
        return '    '
    if 'type' in indent:
        if indent['type'].lower() == 'space':
            num = 4
            if 'num' in indent:
                num = int(indent['num'])
            return ' ' * int(indent['num'])
        elif indent['type'].lower() == 'tab':
            return '\t'


def fixupScope(typeName):
    if typeName in ['vector', 'string', 'pair', 'array', 'optional', 'variant']:
        return 'std::' + typeName
    return typeName.replace('.', '::')


def recordUseOfType(defEntry, typeName):
    if typeName not in defEntry['seenTypes']['c++']:
        defEntry['seenTypes']['c++'].append(typeName)


def getCplusplusRecursiveType(defEntry, typeNode):
    if typeNode.kind == humonEnums.NodeKind.VALUE:
        recordUseOfType(defEntry, typeNode.value)
        return fixupScope(typeNode.value)

    typeTypeNode = typeNode['type']
    builtType = fixupScope(typeTypeNode.value)
    recordUseOfType(defEntry, typeTypeNode.value)

    ofNode = typeNode['of']
    if ofNode:
        builtType = f"{builtType}<"
        if ofNode.kind == humonEnums.NodeKind.LIST:
            for i in range(0, len(ofNode)):
                chNode = ofNode[i]
                if i > 0:
                    builtType = f"{builtType}, "
                builtType = f"{builtType}{getCplusplusRecursiveType(defEntry, chNode)}"
        elif ofNode.kind == humonEnums.NodeKind.DICT:
            builtType = f"{builtType}{getCplusplusRecursiveType(defEntry, ofNode)}"
        else:
            builtType = f"{builtType}{fixupScope(ofNode.value)}"
            recordUseOfType(defEntry, ofNode.value)
        builtType = f"{builtType}>"

    return builtType


def processCplusplusTypes_1_0(defEntry, typesNode):
    cppPodEntry = defEntry['pods']['c++']
    for i in range(0, len(typesNode)):
        podNode = typesNode[i]
        podName = podNode.key
        print(f"{podNode.key}")
        cppPodEntry[podName] = {}
        for j in range(0, len(podNode)):
            memberNode = podNode[j]
            memberType = getCplusplusRecursiveType(defEntry, memberNode)
            print(f"    {memberNode.key} : {memberType}")
            cppPodEntry[podName][memberNode.key] = memberType


def genCtorSignature(podName, pod, languageConfig):
    src = f'{podName}('
    for memberName, memberType in pod.items():
        if 'const' in languageConfig and languageConfig['const'] == 'east':
            src += f'{memberType} const'
        else:
            src += f'const {memberType}'
        src += f' & {memberName}{", " if memberName != list(pod.keys())[-1] else ""}'
    src += ')'
    return src


def usingFeature(languageConfig, feature):
    return ('features' in languageConfig and 
            feature in languageConfig['features'] and
            languageConfig['features'][feature] == "true")


def generateCplusplusHeader(defs, defFile, languageConfig):
    defEntry = defs[defFile]

    src = ''
    for typeName in defEntry['seenTypes']['c++']:
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

    if languageConfig['includeFiles']:
        for incFile, isSystemInclude, _ in languageConfig['includeFiles']:
            if isSystemInclude:
                src += f'#include <{incFile}>\n'
            else:
                src += f'#include "{incFile}"\n'
    src += '\n'

    indentChars = getIndent(languageConfig)
    indent = 0
    if languageConfig['namespace']:
        src += f'namespace {languageConfig["namespace"]}\n{{\n'
        indent += 1

    for podName, pod in defEntry['pods']['c++'].items():
        src += f'''
{indentChars * indent}class {podName}
{indentChars * indent}{{
{indentChars * indent}public:
{indentChars * (indent + 1)}{genCtorSignature(podName, pod, languageConfig)};\n'''

        if not usingFeature(languageConfig, 'copyable'):
            src += f'{indentChars * (indent + 1)}{podName}('
            if 'const' in languageConfig and languageConfig['const'] == 'east':
                src += f'{podName} const '
            else:
                src += f'const {podName} '
            src += '& rhs) = delete;\n'

            src += f'{indentChars * (indent + 1)}{podName} & operator =('
            if 'const' in languageConfig and languageConfig['const'] == 'east':
                src += f'{podName} const '
            else:
                src += f'const {podName} '
            src += '& rhs) = delete;\n'

        if not usingFeature(languageConfig, 'movable'):
            src += f'{indentChars * (indent + 1)}{podName}({podName} && rhs) = delete;\n'

            src += f'{indentChars * (indent + 1)}{podName} & operator =({podName} && rhs) = delete;\n'

        src += f'{indentChars * (indent + 1)}~{podName}();\n'
        src += f'{indentChars * indent}}};\n\n'

        # TODO NEXT: Checking features to splat out fn sigs


    if languageConfig['namespace']:
        src += f'}}\n'
        indent -= 1

    return src


def generateCplusplusHeaderFile(defs, defFile, languageConfig):
    header = generateCplusplusHeader(defs, defFile, languageConfig)

    outputDir = '.'
    if 'outputDirs' in languageConfig and 'header' in languageConfig['outputDirs']:
        outputDir = languageConfig['outputDirs']['header']
    
    outputFile = 'gen-defs.h'
    if 'outputFiles' in languageConfig and 'header' in languageConfig['outputFiles']:
        outputFile = languageConfig['outputFiles']['header']
    
    Path(outputDir).mkdir(parents=True, exist_ok=True)

    print (f"Building header {outputDir}/{outputFile}")
    f = open(f"{outputDir}/{outputFile}", 'wt')
    print(header, file = f)
    f.close()


def generateCplusplusArtifacts(defs, defFile, languageConfig):
    generateCplusplusHeaderFile(defs, defFile, languageConfig)
