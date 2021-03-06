def genAll(self):
    if not self.dIs('computeEnums'):
        return

    self.includeOutputFile('mainHeader|includes', 'enumHeader')
    # for header-only projects, enumHeader has a section for getting inline src.
    self.includeOutputFile('enumHeaderIncludeInline', 'enumSource', inPlace=True)
    # for compiled project, link cpp to hpp
    self.includeOutputFile('enumSource|includes', 'enumHeader')

    self.gen_enums.addEnumSourceIncludes(self)
    self.gen_enums.genDeserializers(self)
    self.gen_enums.genSerializers(self)


def addEnumSourceIncludes(self):
    for enumName, enum in self.everyEnum():
        # include things found in the enums block.
        for includeFile in enum.enumsObject.sources:
            if includeFile.startswith('<') and includeFile.endswith('>'):
                self.includeFile('commonHeader|includes', includeFile)
            else:
                self.includeFile('commonHeader|includes', f'"{includeFile}"')


def genDeserializers(self):
    fmts = self.d('deserializeFrom')
    if not fmts:
        return

    for fmt in fmts:
        if fmt.lower() == 'humon':
            for enumName, enum in self.everyEnum():
                self.gen_enums.genDeserializeFromHumon(self, enumName, enum)

        elif fmt.lower() == 'binary':
            for enumName, enum in self.everyEnum():
                self.gen_enums.genDeserializeFromBinary(self, enumName, enum)


def genDeserializeFromHumon(self, enumName, enum):
    if f'humon|{enumName}' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes[f'humon|{enumName}'] = None

    it = self.indent()
    enumDecl = self.makeNative(enumName)

    # write inline bits
    self.gen_containersDeserializeFromHumon.gen_includeHumon(self, 'humon|enumDeserializerDecls')
    self.includeOutputFile('humon|enumDeserializerDecls', 'commonHeader')
    self.includeFile('humon|enumDeserializerDecls', '<cstring>')

    src = f'''

{it}template <>
{it}struct val<{enumDecl}>
{it}{{
{it}{it}static inline {enumDecl} extract({self.const("Node")} & node) noexcept
{it}{it}{{'''
    if enum.flags:
        src += f'''
{it}{it}{it}using enumIntType = std::underlying_type<{enumDecl}>::type;
{it}{it}{it}enumIntType e = 0;
{it}{it}{it}bool fromList = node.kind() == hu::NodeKind::list;
{it}{it}{it}Node chNode = node;
{it}{it}{it}if (fromList)
{it}{it}{it}{it}{{ chNode = chNode.firstChild(); }}
{it}{it}{it}do
{it}{it}{it}{{
{it}{it}{it}{it}auto nodeVal = chNode.value().str().data();'''
    else:
        src += f'''
{it}{it}{it}auto nodeVal = node.value().str().data();'''

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
{it}{it}{it}{it}{doElse}if {spaces}(std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ e |= static_cast<enumIntType>({declName}); }}'''
        else:
            src += f'''
{it}{it}{it}if (std::strncmp(nodeVal, "{modName}", {len(modName)}) == 0) {{ return {declName}; }}'''

    if enum.flags:
        src += f'''
{it}{it}{it}{it}chNode = chNode.nextSibling();
{it}{it}{it}}}
{it}{it}{it}while(fromList && chNode);

{it}{it}{it}return static_cast<{enumDecl}>(e);'''
    else:
        src += f'''
{it}{it}{it}return {{}};'''

    # TODO: define and extract a default value
    src += f'''
{it}{it}}}
{it}}};'''
    self.appendSrc('humon|enumDeserializerDecls', src)


def genDeserializeFromBinary(self, enumName, enum):
    if 'binary|enum' in self.containersDeserializerTypes:
        return
    self.containersDeserializerTypes['binary|enum'] = None

    it = self.indent()
    src = f'''

{it}template <class T>
{it}struct BinaryReader<T, typename std::enable_if_t<std::is_enum_v<T>>>
{it}{{
{it}{it}static inline T extract(std::istream & in)
{it}{it}{{'''

    dbgs = self.d('caveperson')
    if dbgs and 'serializeBinary' in dbgs:
        caveStream = self.d('caveStream') or 'cout'
        src += f'''
{it}{it}std::{caveStream} << "Reading {enumName}:\\n";'''

    src += f'''
{it}{it}{it}T t;
{it}{it}{it}in.read(reinterpret_cast<char *>(& t), sizeof(T));
{it}{it}{it}return t;
{it}{it}}}
{it}}};'''
    self.appendSrc('binary|enumDeserializerDecls', src)


def genSerializers(self):
    fmts = self.d('serializeTo')
    if (not fmts):
        return

    self.includeOutputFile('enumSerializerDecls', 'commonHeader')

    for fmt in fmts:
        if fmt.lower() == 'humon':
            for enumName, enum in self.everyEnum():
                self.gen_enums.genSerializerToHumon(self, enumName, enum)
        elif fmt.lower() == 'binary':
            for enumName, enum in self.everyEnum():
                self.gen_enums.genSerializerToBinary(self, enumName, enum)


def genSerializerToHumon(self, enumName, enum):
    it = self.indent()
    enumDecl = self.makeNative(enumName)

    # defs
    # Only forward-declare ostream if we're not getting it from humon.hpp.
    # This system could be improvd.
    fmts = self.d('deserializeFrom')
    if not fmts or 'humon' not in fmts:
        self.forwardDeclareType('enumSerializerDecls', 'ostream', f'namespace std {{ class ostream; }}')

    src = f'''
{it}std::ostream & operator <<(std::ostream & out, {self.const(f'HumonFormat<{enumDecl}>')} & obj);'''
    self.appendSrc('enumSerializerDecls', src)

    # decls

    self.includeForType('enumSerializerDefs', 'ostream', '#include <iostream>')

    src = f'''

{it}std::ostream & operator <<(std::ostream & out, {self.const(f'HumonFormat<{enumDecl}>')} & obj)
{it}{{
{it}{it}using enumIntType = std::underlying_type<{enumDecl}>::type;'''
    if enum.flags:
        src += f'''
{it}{it}enumIntType bits = static_cast<enumIntType>(* obj);
{it}{it}out << "[";'''
    else:
        src += f'''
{it}{it}switch (* obj)
{it}{it}{{'''
    seenVals = set()
    for modName, (declName, numericValue) in enum.enumVals.items():
        if numericValue in seenVals:
            continue
        seenVals.add(numericValue)

        # TODO: is this always correct? no
        prefix = enumDecl
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
{it}{it}default: out << static_cast<enumIntType>(* obj); break;
{it}{it}}}
'''
    src += f'''
{it}{it}return out;
{it}}}'''

    self.appendSrc('enumSerializerDefs', src)


def genSerializerToBinary(self, enumName, enum):
    it = self.indent()
    enumDecl = self.makeNative(enumName)

    # we actually only need one
    if 'binary|enum' in self.containersSerializerTypes:
        return
    self.containersSerializerTypes['binary|enum'] = None

    #decl

    self.includeFile('binary|serializersDecl', "<type_traits>")
    self.includeForType('binary|serializersDecl', 'ostream', '#include <iostream>')

    fmts = self.d('serializeTo')
    if not fmts or 'binary' not in fmts:
        self.forwardDeclareType('binary|serializersDecl', 'ostream', 'class std::ostream;')

    src = f'''

{it}template <class T, std::enable_if_t<std::is_enum_v<T>, bool> = true>
{it}std::ostream & operator <<(std::ostream & out, {self.const('BinaryFormat<T>')} & obj)
{it}{{'''

    dbgs = self.d('caveperson')
    if dbgs and 'serializeBinary' in dbgs:
        caveStream = self.d('caveStream') or 'cout'
        src += f'''
{it}{it}std::{caveStream} << "Writing {enumName}:\\n";'''

    src += f'''
{it}{it}using enumIntType = std::underlying_type<{enumDecl}>::type;
{it}{it}out << BinaryFormat(static_cast<enumIntType>(* obj));

{it}{it}return out;
{it}}}'''
    self.appendSrc('binary|serializersDecl', src)
