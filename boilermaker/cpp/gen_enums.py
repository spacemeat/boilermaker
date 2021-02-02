def genEnumDeserializers(self):
    self._addInclude('mainHeader', '<humon/humon.hpp>')
    self._addInclude('mainHeader', 
        '/'.join([self.d('headerToInl'), self.d('enumInlineHeaderFile')])
           .join(['"', '"']))
    for enumName, enum in self.everyEnum():
        self.gen_enums.genEnumDeserializer(self, enumName, enum)


def genEnumDeserializer(self, enumName, enum):
    it = self.indent()

    self._addInclude('enumInlineSource', '<humon/humon.hpp>')

    for includeFile in enum.enumsObject.sources:
        if includeFile.startswith('<') and includeFile.endswith('>'):
            self._addInclude('enumInlineSource', includeFile)
        else:
            self._addInclude('enumInlineSource', includeFile.join(['"', '"']))

    enumType = enumName.replace('.', '::')

    # write inline bits
    src = f'''

template <>
struct hu::val<{enumType}>
{{
{it}static inline {enumType} extract(hu::Node node) noexcept;
}};'''
    #self._appendToFile(src, 'enumInlineSource', 'enumDeserializers')
    self._appendToSection('enumDeserializerDecls', src)

    # write source bits

    self._addInclude('enumSource', '<cstring>')
    src = f'''


inline {enumType} hu::val<{enumType}>::extract(hu::Node node) noexcept
{{
{it}auto nodeVal = node.value().str().data();'''
    if enum.flags:
        src += f'''
{it}using enumIntType = std::underlying_type<{enumType}>::type;
{it}enumIntType e = 0;
{it}bool fromList = node.kind() == hu::NodeKind::list;
{it}if (fromList)
{it}{it}{{ node = node.firstChild(); }}
{it}while(node)
{it}{{'''

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
{it}{it}{doElse}if {spaces}(std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ e |= static_cast<enumIntType>({declName}); }}'''
        else:
            src += f'''
{it}if (std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ return {declName}; }}'''

    if enum.flags:
        src += f'''
{it}{it}if (fromList)
{it}{it}{it}{{ node = node.nextSibling(); }}
{it}{it}else
{it}{it}{it}{{ break; }}
{it}}}
{it}return static_cast<{enumType}>(e);'''
    else:
        src += f'''
{it}return {{}};'''

    # TODO: define and extract a default value
    src += f'''
}}'''
    #self._appendToFile(src, 'enumSource', 'enumDeserializers')
    self._appendToSection('enumDeserializerDefs', src)


def genEnumStreamInserters(self):
    pass


def genEnumStreamInserter(self, enumName, enum, ind):
    it = self.indent()
    src = ''
    if not self.getFeature('serialize'):
        return src

    enumType = enumName.replace('.', '::')
    src += f'''


{it}inline std::ostream & operator <<(std::ostream & out, {enumType} obj)
{it}{{
{it}{it}using enumIntType = std::underlying_type<{enumType}>::type;'''
    if enum.hasAttrib('flags'):
        src += f'''
{it}{it}enumIntType bits = static_cast<enumIntType>(obj);
{it}{it}out << "[";'''
    else:
        src += f'''
{it}{it}switch (obj)
{it}{it}{{'''
    enumValues = enum.values
    if enum.hasAttrib('flags'):
        enumValues = reversed(enumValues)

    seenVals = set()
    for enumValName, enumValVal in enumValues:
        if enumValVal in seenVals:
            continue
        seenVals.add(enumValVal)

        prefix = enumType
        if enum.hasAttrib('cStyle'):
            scopePos = prefix.rfind('::')
            if scopePos >= 0:
                prefix = prefix[:scopePos + 1]
        
        modifiers = self.getModifiers(enumName)
        modName = enumValName
        modPrefix = modifiers.get('prefix')
        if modPrefix and len(modPrefix) > 0: # and modName.startswith(modPrefix):
            modName = modName[len(modPrefix):]
        postfix = modifiers.get('postfix')
        if postfix and len(postfix) > 0: # and modName.endswith(postfix):
            modName = modName[:len(modName) - len(postfix)]
        case = modifiers.get('case')
        if case == 'upper':
            modName = modName.lower()
        elif case == 'lower':
            modName = modName.upper()

        if enum.hasAttrib('flags'):
            src += f'''
{it}{it}if (bits & static_cast<enumIntType>({prefix}::{enumValName}))
{it}{it}{{
{it}{it}{it}out << " {modName}";
{it}{it}{it}bits &= ~static_cast<enumIntType>({prefix}::{enumValName});
{it}{it}{it}if (! bits)
{it}{it}{it}{it}{{ goto done; }}
{it}{it}}}
'''
        else:
            src += f'''
{it}{it}case {prefix}::{enumValName}:
{it}{it}{it}out << "{modName}";
{it}{it}{it}break;'''
    
    if enum.hasAttrib('flags'):
        src += f'''
{it}done:
{it}{it}out << " ]";
'''
    else:
        src += f'''
{it}{it}default:
{it}{it}{it}out << static_cast<enumIntType>(obj);
{it}{it}{it}break;
{it}{it}}}
'''
    src += f'''
{it}{it}return out;
{it}}}'''
    return src


