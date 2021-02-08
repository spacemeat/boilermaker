def genDeserializers(self):
    if (not self.dIs('computeEnums') or
        not self.dIs('deserializeFromHumon')):
        return ''

    self._addInclude('mainHeaderIncludes', 'enumHeader')
    for enumName, enum in self.everyEnum():
        self.gen_enums._genDeserializer(self, enumName, enum)


def _genDeserializer(self, enumName, enum):
    it = self.indent()

    self._addInclude('enumHeaderIncludes', '<humon/humon.hpp>')
    self.gen_enums._addEnumSourceIncludes(self, enum)

    enumType = self.makeNative(enumName)

    # write inline bits
    src = f'''

{it}template <>
{it}struct hu::val<{enumType}>
{it}{{
{it}{it}static inline {enumType} extract(hu::Node node) noexcept;
{it}}};'''
    self._appendToSection('enumDeserializerDecls', src)

    # write source bits

    self._addInclude('enumHeaderIncludes', '<cstring>')
    src = f'''

template <>
struct hu::val<{enumType}>
{{
{it}static inline {enumType} extract(hu::Node node) noexcept
{it}{{'''
    if enum.flags:
        src += f'''
{it}{it}using enumIntType = std::underlying_type<{enumType}>::type;
{it}{it}enumIntType e = 0;
{it}{it}bool fromList = node.kind() == hu::NodeKind::list;
{it}{it}if (fromList)
{it}{it}{it}{{ node = node.firstChild(); }}
{it}{it}while(node)
{it}{it}{{
{it}{it}{it}auto nodeVal = node.value().str().data();'''
    else:
        src += f'''
{it}{it}auto nodeVal = node.value().str().data();'''

    firstTime = True
    for modName, (declName, numericValue) in enum.enumVals.items():
        if firstTime:
            doElse = ''
            spaces = '     '
            firstTime = False
        else:
            doElse = 'else '
            spaces = ''

        if enum.flags:
            src += f'''
{it}{it}{it}{doElse}if {spaces}(std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ e |= static_cast<enumIntType>({declName}); }}'''
        else:
            src += f'''
{it}{it}if (std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ return {declName}; }}'''

    if enum.flags:
        src += f'''
{it}{it}{it}node = node.nextSibling();
{it}{it}}}
{it}{it}return static_cast<{enumType}>(e);'''
    else:
        src += f'''
{it}{it}return {{}};'''

    # TODO: define and extract a default value
    src += f'''
{it}}}
}};'''
    self._appendToSection('enumDeserializerDefs', src)


def genSerializers(self):
    if (not self.dIs('computeEnums') or
        not self.dIs('serializeToHumon')):
        return ''

    self._addInclude('mainHeaderIncludes', 'enumHeader')

    # because deserializeFromHumon includes humon, which already surfaces std::ostream.
    if not self.dIs('deserializeFromHumon'):
        src = f'''
class std::ostream;'''
        self._appendToSection('enumHeaderForwardDecls', src)

    for enumName, enum in self.everyEnum():
        self.gen_enums._genSerializer(self, enumName, enum)


def _genSerializer(self, enumName, enum):
    it = self.indent()

    enumType = enumName.replace('.', '::')

    self._addInclude('enumSourceIncludes', '<iostream>')
    self._addInclude('enumSourceIncludes', 'enumHeader')
    self.gen_enums._addEnumSourceIncludes(self, enum)

    # defs
    src = f'''
{it}inline std::ostream & operator <<(std::ostream & out, {enumType} obj);'''

    self._appendToSection('enumSerializerDecls', src)

    # decls
    src = f'''


{it}inline std::ostream & operator <<(std::ostream & out, {enumType} obj)
{it}{{
{it}{it}using enumIntType = std::underlying_type<{enumType}>::type;'''
    if enum.flags:
        src += f'''
{it}{it}enumIntType bits = static_cast<enumIntType>(obj);
{it}{it}out << "[";'''
    else:
        src += f'''
{it}{it}switch (obj)
{it}{it}{{'''
    seenVals = set()
    for modName, (declName, numericValue) in enum.enumVals.items():
        if numericValue in seenVals:
            continue
        seenVals.add(numericValue)

        # TODO: is this always correct? no
        prefix = enumType
        if not enum.isScoped:
            scopePos = prefix.rfind('::')
            if scopePos >= 0:
                prefix = prefix[:scopePos]
        
        if enum.flags:
            src += f'''
{it}{it}if (bits & static_cast<enumIntType>({prefix}::{declName}))
{it}{it}{{
{it}{it}{it}out << " {modName}";
{it}{it}{it}bits &= ~static_cast<enumIntType>({prefix}::{declName});
{it}{it}{it}if (! bits)
{it}{it}{it}{it}{{ goto done; }}
{it}{it}}}
'''
        else:
            src += f'''
{it}{it}case {prefix}::{declName}: out << "{modName}"; break;'''
    
    if enum.flags:
        src += f'''
{it}done:
{it}{it}out << " ]";
'''
    else:
        src += f'''
{it}{it}default: out << static_cast<enumIntType>(obj); break;
{it}{it}}}
'''
    src += f'''
{it}{it}return out;
{it}}}'''

    self._appendToSection('enumSerializerDefs', src)


def _addEnumSourceIncludes(self, enum):
    # include things found in the enums block.
    for includeFile in enum.enumsObject.sources:
        if includeFile.startswith('<') and includeFile.endswith('>'):
            self._addInclude('enumHeaderIncludes', includeFile)
        else:
            self._addInclude('enumHeaderIncludes', f'"{includeFile}"')

    # for header-only projects, enumHeader has a section for getting inline src.
    self._addInclude('enumHeaderIncludeInline', 'enumSource')
