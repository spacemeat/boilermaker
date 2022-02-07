from .. import utilities


def genAll(self):
    if not self.dIs('computeTypes'):
        return ''

    deserializeMemo = {}
    serializersMemo = {}
    for typeName, t in self.types.items():
        self.gen_types.genAllForType(self, typeName, t, deserializeMemo, serializersMemo)


def genAllForType(self, typeName, t, deserializeMemo, serializersMemo):
    self.defsData['type'] = typeName
    self.gen_types.genIncludesInline(self, t)
    self.gen_types.genIsLessStructs(self, t)
    self.gen_types.genVariantTypeNamesForType(self, t)
    self.gen_types.genClassBegin(self, t)
    self.gen_types.genDefaultConstructor(self, t)
    self.gen_types.genMemberwiseConstructor(self, t)
    self.gen_types.genCopyConstructor(self, t)
    self.gen_types.genMoveConstructor(self, t)
    self.gen_types.genCopyAssignment(self, t)
    self.gen_types.genMoveAssignment(self, t)
    self.gen_types.genDestructor(self, t)
    self.gen_types.genSwap(self, t)
    self.gen_types.genGetters(self, t)
    self.gen_types.genSetters(self, t)
    self.gen_types.genDeserializers(self, t)
    self.gen_types.genSerializers(self, t)
    self.gen_types.genComparator(self, t)
    self.gen_diffs.genTypeDiffer(self, t)
    self.gen_types.genMembers(self, t)
    self.gen_types.genClassEnd(self, t)
    del self.defsData['type']


def fwdDeclareAllTypes(section, self):
    for typeName, t in self.types.items():
        self.gen_types.fwdDeclareType(self, t)


def fwdDeclareType(self, section, t):
    for memberName, m in t.members.items():
        self.gen_types.fwdDeclareSubtype(self, section, t, m.properties)


def fwdDeclareSubtype(self, section, t, typeDict):
    baseType = typeDict['type']
    it = self.indent()

    decl = None

    src = ''
    namespace = 'std'
    if baseType == 'size_t':
        decl = f'''
{it}class size_t;'''
    elif baseType == 'string':
        decl = f'''
{it}class string;'''
        self.gen_types.includeForSubtype(self, section, t, typeDict)
    elif baseType == 'string_view':
        self.gen_types.includeForSubtype(self, section, t, typeDict)
    elif baseType == 'array':
        decl = f'''
{it}template <class T, size_t N> class array;'''
    elif baseType == 'pair':
        decl = f'''
{it}template <class T1, class T2> class pair;'''
    elif baseType == 'tuple':
        decl = f'''
{it}template <class... Types> class tuple;'''
    elif baseType == 'vector':
        decl = f'''
{it}template <class T, class Allocator = std::allocator<T>> class vector;'''
    elif baseType == 'set':
         decl = f'''
{it}template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;'''
    elif baseType == 'unordered_set':
        decl = f'''
{it}template <class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_set;'''
    elif baseType == 'map':
        decl = f'''
{it}template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class map;'''
    elif baseType == 'unordered_map':
        decl = f'''
{it}template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_map;'''
    elif baseType == 'optional':
        decl = f'''
{it}template <class T> class optional;'''
    elif baseType == 'variant':
        decl = f'''
{it}template <class... Types> class variant;'''
    elif baseType in self.types.keys():
        namespace = self.d('namespace')
        decl = f'''
{it}class {baseType};'''

    if decl:
        self.forwardDeclareType(section, baseType, decl, namespace)

    if typeDict.get('of'):
        for subType in typeDict['of']:
            self.gen_types.fwdDeclareSubtype(self, section, t, subType)


def includeForAllTypes(self, section):
    for typeName, t in self.types.items():
        self.gen_types.includeForType(self, t)


def includeForType(self, section, t):
    for memberName, m in t.members.items():
        self.gen_types.includeForSubtype(self, section, t, m.properties)


def includeForSubtype(self, section, t, typeDict):
    baseType = typeDict['type']
    removeSizetTypedef = False
    if baseType == 'size_t':
        decl = '#include <cstddef>'
    elif baseType == 'string':
        decl = '#include <string>'
        removeSizetTypedef = True
    elif baseType == 'string_view':
        decl = '#include <string_view>'
        removeSizetTypedef = True
    elif baseType == 'array':
        decl = '#include <array>'
        removeSizetTypedef = True
    elif baseType == 'pair':
        decl = '#include <utility>'
        removeSizetTypedef = True
    elif baseType == 'tuple':
        decl = '#include <tuple>'
        removeSizetTypedef = True
    elif baseType == 'vector':
        decl = '#include <vector>'
        removeSizetTypedef = True
    elif baseType == 'set':
        decl = '#include <set>'
        removeSizetTypedef = True
    elif baseType == 'unordered_set':
        decl = '#include <unordered_set>'
        removeSizetTypedef = True
    elif baseType == 'map':
        decl = '#include <map>'
        removeSizetTypedef = True
    elif baseType == 'unordered_map':
        decl = '#include <unordered_map>'
        removeSizetTypedef = True
    elif baseType == 'optional':
        decl = '#include <optional>'
        removeSizetTypedef = True
    elif baseType == 'variant':
        decl = '#include <variant>'
        removeSizetTypedef = True
    elif baseType in self.types.keys():
        self.includeOutputFile(section, f'{baseType}|typeHeader')
        decl = None
    else:
        decl = None

    if decl:
        self.includeForType(section, baseType, decl)

    if removeSizetTypedef:
        # promotes size_t from typedef to #include, using the same
        # decl as above to make the typedef effectively disappear
        self.includeForType(section, 'size_t', decl)

    if typeDict.get('of'):
        for subType in typeDict['of']:
            self.gen_types.includeForSubtype(self, section, t, subType)


def genIncludesInline(self, t):
    it = self.indent()
    self.includeOutputFile(f'{t.name}|typeHeader|includes', 'commonHeader')
    self.includeOutputFile(f'mainHeader|includes', f'{t.name}|typeHeader')
    self.includeOutputFile(f'{t.name}|typeSource|includes', f'{t.name}|typeHeader')
    self.includeOutputFile(f'{t.name}|typeSource|includes', 'enumHeader')


def genIsLessStructs(self, t):
    def visit(properties):
        name = properties['fullName']

        for ofo in properties.get('of', []):
            visit(ofo)

        lessCode = properties.get('isLess')
        if lessCode:
            self.gen_types._genIsLessStruct(self, t, name, properties)


    for memberName, m in t.members.items():
        visit(m.properties)


def _genIsLessStruct(self, t, name, properties):

    it = self.indent()
    lessCode = properties.get('isLess')
    subtypeDecl = ''
    stype = properties.get('type')
    if stype == 'set' or stype == 'map':
        subtypeDecl = self.makeNativeSubtype(properties['of'][0])

    self.gen_types.fwdDeclareSubtype(self, 'isLessDecl', t, properties)

    src = f'''

{it}struct IsLess_{name}
{it}{{
{it}{it}bool operator()({self.const(subtypeDecl)} & lhs, {self.const(subtypeDecl)} & rhs) const;
{it}}};'''
    self.appendSrc('isLessDecl', src)

    self.gen_types.includeForSubtype(self, 'isLessDef', t, properties)
    src = f'''

{it}bool IsLess_{name}::operator()({self.const(subtypeDecl)} & lhs, {self.const(subtypeDecl)} & rhs) const
{it}{{
{it}{it}{lessCode}
{it}}}'''
    self.appendSrc('isLessDef', src)


def genVariantTypeNamesForType(self, t):
    self.gen_types.fwdDeclareType(self, 'variantTypeNames', t)
    for memberName, m in t.members.items():
        self.gen_types.genVariantTypeNamesForSubtype(self, m.properties)


def genVariantTypeNamesForSubtype(self, typeDict):
    if typeDict['type'] == 'variant':
        typeDecl = self.makeNativeSubtype(typeDict)
        if typeDecl in self.containersVariantTypeNames:
            return

        if len(self.containersVariantTypeNames) == 0:
            self.gen_types.genVariantTypeNamesTemplate(self)

        self.containersVariantTypeNames[typeDecl] = None

        it = self.indent()
        subTypes = []
        for subDict in typeDict.get('of', []):
            subType = subDict.get('alias')
            if not subType:
                subType = subDict['type']
            subTypes.append(subType)

        src = f'''

{it}template <>
{it}struct VariantTypeNames<{typeDecl}>
{it}{{
{it}{it}static constexpr char const * names[] = {{ {', '.join([f'"{st}"' for st in subTypes])} }};
{it}{it}static constexpr std::size_t size = {len(subTypes)};
{it}}};'''
        self.appendSrc(f'variantTypeNames', src)

    if typeDict.get('of'):
        for chDict in typeDict['of']:
            self.gen_types.genVariantTypeNamesForSubtype(self, chDict)


def genVariantTypeNamesTemplate(self):
    it = self.indent()
    src = f'''

{it}template <class T>
{it}struct VariantTypeNames
{it}{{
{it}{it}static constexpr char const * names[] = {{ }};
{it}{it}static constexpr std::size_t size = 0;
{it}}};'''
    self.appendSrc(f'variantTypeNames', src)


def genClassBegin(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''

{it}class {typeDecl}
{it}{{
{it}public:'''

    self.appendSrc(f'{t.name}|classBegin', src)


def genDeserializers(self, t):
    fmts = self.d('deserializeFrom')
    if (not fmts):
        return

    for fmt in fmts:
        if fmt == 'humon':
            self.gen_types.genDeserializer_humon(self, t)
        elif fmt == 'binary':
            self.gen_types.genDeserializer_binary(self, t)
        else:
            raise RuntimeError(f'Unrecognized deserialization source "{fmt}".')


def genDeserializer_humon(self, t):
    self.gen_containersDeserializeFromHumon.gen_builtIn(self)

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    # ----- declaration

    self.forwardDeclareType(f'{t.name}|humonCtrDecl', 'Node', f'{it}class Node;', 'hu')

    src = f'''
{it}{it}{t.name}({self.const('hu::Node')} & node)'''
    self.appendSrc(f'{t.name}|humonCtrDecl', src + ';')

    # ----- definition

    self.includeForType(f'{t.name}|humonCtrDef', 'Node', '#include <humon/humon.hpp>')
    # ----- signature
    src = f'''

{it}{t.name}::{t.name}({self.const('hu::Node')} & node)
'''
    # ----- member constructors
    firstMember = True
    for memberName, m in t.members.items():
        memberDecl = self.makeNativeMemberType(m.properties)
        decl = f'{memberName}(node / "{memberName}" % hu::val<{memberDecl}>{{}})'
        if firstMember:
            firstMember = False
            src += f'{it}: '
        else:
            src += f', \n{it}  '
        src += decl
    src += f'''
{it}{{{self.cave('ctr', f'"Humon ctor: {t.name}"', f'{t.name}|humonCtrDef', 2)}
{it}}}'''

    self.appendSrc(f'{t.name}|humonCtrDef', src)

    self.forwardDeclareType(f'{t.name}|typeDeserializerDecl', 'Node', f'{it}class Node;', 'hu')
    typeDecl = self.makeNative(t.name, True)
    src = f'''
{it}template<>
{it}struct val<{typeDecl}>
{it}{{
{it}{it}static inline {typeDecl} extract(Node const & node);
{it}}};'''

    self.appendSrc(f'{t.name}|typeDeserializerDecl', src, 'hu')

    self.includeForType(f'{t.name}|typeDeserializerDef', 'Node', '#include <humon/humon.hpp>')
    src = f'''
{it}template<>
{it}struct val<{typeDecl}>
{it}{{
{it}{it}static inline {typeDecl} extract(Node const & node)
{it}{it}{{{self.cave('deserializeHumon', f'"Reading {t.name}"', f'{t.name}|typeDeserializerDef')}
{it}{it}{it}return {typeDecl}(node);
{it}{it}}}
{it}}};'''

    self.appendSrc(f'{t.name}|typeDeserializerDef', src, 'hu')

    # do container types
    for memberName, m in t.members.items():
        self.gen_types.genDeserializerSubtype_humon(self, m.properties)


def genDeserializerSubtype_humon(self, typeDict):
    baseType = typeDict['type']

    if baseType == 'array':
        self.gen_containersDeserializeFromHumon.gen_array(self)
    elif baseType == 'pair':
        self.gen_containersDeserializeFromHumon.gen_pair(self)
    elif baseType == 'tuple':
        self.gen_containersDeserializeFromHumon.gen_tuple(self)
    elif baseType == 'vector':
        self.gen_containersDeserializeFromHumon.gen_vector(self)
    elif baseType == 'set':
        self.gen_containersDeserializeFromHumon.gen_set(self)
    elif baseType == 'unordered_set':
        self.gen_containersDeserializeFromHumon.gen_unordered_set(self)
    elif baseType == 'map':
        self.gen_containersDeserializeFromHumon.gen_map(self)
    elif baseType == 'unordered_map':
        self.gen_containersDeserializeFromHumon.gen_unordered_map(self)
    elif baseType == 'optional':
        self.gen_containersDeserializeFromHumon.gen_optional(self)
    elif baseType == 'variant':
        self.gen_containersDeserializeFromHumon.gen_variant(self)

    if typeDict.get('of'):
        for chDict in typeDict['of']:
            self.gen_types.genDeserializerSubtype_humon(self, chDict)


def genDeserializer_binary(self, t):
    self.gen_containersDeserializeFromBinary.gen_builtIn(self)

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    # ----- declaration

    src = f'''
{it}{it}{t.name}({self.const('char')} *& buffer, std::size_t & size)'''
    self.appendSrc(f'{t.name}|binaryCtrDecl', src + ';')

    # ----- definition

    self.includeForType(f'{t.name}|binaryCtrDef', 'istream', '#include <iostream>')
    # ----- signature
    src = f'''

{it}{typeDecl}::{t.name}({self.const('char')} *& buffer, std::size_t & size)
'''
    # ----- member constructors
    firstMember = True
    for memberName, m in t.members.items():
        memberDecl = self.makeNativeMemberType(m.properties)
        decl = f'{memberName}(BinaryReader<{memberDecl}>::extract(buffer, size))'
        if firstMember:
            firstMember = False
            src += f'{it}: '
        else:
            src += f', \n{it}  '
        src += decl
    src += f'''
{it}{{{self.cave('ctr', f'"Binary ctr: {t.name}"', f'{t.name}|binaryCtrDef', 2)}
{it}}}'''
    self.appendSrc(f'{t.name}|binaryCtrDef', src)

    src = f'''

{it}template <>
{it}struct BinaryReader<{typeDecl}>
{it}{{
{it}{it}static inline {typeDecl} extract({self.const('char')} *& buffer, std::size_t & size)
{it}{it}{{{self.cave('deserializeBinary', f'"Reading {t.name}"', f'{t.name}|binaryExtractor')}
{it}{it}{it}return {typeDecl}(buffer, size);
{it}{it}}}
{it}}};
'''
    self.appendSrc(f'{t.name}|binaryExtractor', src)


    # do container types
    for memberName, m in t.members.items():
        self.gen_types.genDeserializerSubtype_binary(self, m.properties)


def genDeserializerSubtype_binary(self, typeDict):
    baseType = typeDict['type']

    if baseType == 'array':
        self.gen_containersDeserializeFromBinary.gen_array(self)
    elif baseType == 'pair':
        self.gen_containersDeserializeFromBinary.gen_pair(self)
    elif baseType == 'tuple':
        self.gen_containersDeserializeFromBinary.gen_tuple(self)
    elif baseType == 'vector':
        self.gen_containersDeserializeFromBinary.gen_vector(self)
    elif baseType == 'set':
        self.gen_containersDeserializeFromBinary.gen_set(self)
    elif baseType == 'unordered_set':
        self.gen_containersDeserializeFromBinary.gen_unordered_set(self)
    elif baseType == 'map':
        self.gen_containersDeserializeFromBinary.gen_map(self)
    elif baseType == 'unordered_map':
        self.gen_containersDeserializeFromBinary.gen_unordered_map(self)
    elif baseType == 'optional':
        self.gen_containersDeserializeFromBinary.gen_optional(self)
    elif baseType == 'variant':
        self.gen_containersDeserializeFromBinary.gen_variant(self)

    if typeDict.get('of'):
        for chDict in typeDict['of']:
            self.gen_types.genDeserializerSubtype_binary(self, chDict)


def genSerializers(self, t):
    fmts = self.d('serializeTo')
    if (not fmts):
        return

    self.gen_types.genSerializerFormatWrappers(self)

    for fmt in fmts:
        if fmt.lower() == 'humon':
            self.gen_types.genSerializer_humon(self, t)
        elif fmt.lower() == 'binary':
            self.gen_types.genSerializer_binary(self, t)


def genSerializerFormatWrappers(self):
    it = self.indent()
    src = f'''

{it}template <class T>
{it}struct SerializedFormat
{it}{{
{it}{it}SerializedFormat({self.const('T')} & obj)
{it}{it}: obj(obj)
{it}{it}{{ }}

{it}{it}T const & operator *() const
{it}{it}{it}{{ return obj; }}

{it}{it}T const * operator ->() const
{it}{it}{it}{{ return & obj; }}

{it}{it}{self.const('T')} & obj;
{it}}};'''
    self.setSrcIfEmpty('serializerFormatWrapperBase', src)


def genSerializer_humon(self, t):
    self.gen_containersSerializeToHumon.gen_builtIn(self)
    it = self.indent()

    fmts = self.d('deserializeFrom')
    if not fmts or 'humon' not in fmts:
        self.forwardDeclareType(f'{t.name}|forwardDecls', 'ostream', f'{it}class ostream;', 'std')
    src = f'''
{it}std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj);'''
    self.appendSrc(f'{t.name}|forwardDecls', src)

    fmts = self.d('deserializeFrom')
    if not fmts or 'humon' not in fmts:
        self.forwardDeclareType(f'{t.name}|serializerDecl', 'ostream', f'{it}class ostream;', 'std')
    src = f'''
{it}{it}friend std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj);'''
    self.appendSrc(f'{t.name}|serializerDecl', src)

    self.includeForType(f'{t.name}|serialzierDef', 'ostream', f'''#include <iostream>''')
    src = f'''

{it}std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj)
{it}{{
{it}{it}out << '{{';'''
    for memberName, memberObj in t.members.items():
        typeDecl = self.makeNativeMemberType(memberObj.properties)
        if memberObj.properties['type'] == 'optional':
            src += f'''
{it}{it}if (obj->{memberName}.has_value()) {{ out << " HumonFormat({memberName}): " << obj->{memberName}; }}'''
        else:
            src += f'''
{it}{it}out << " {memberName}: " << HumonFormat(obj->{memberName});'''
    src += f'''
{it}{it}out << " }}";
{it}{it}return out;
{it}}}'''

    self.appendSrc(f'{t.name}|serialzierDef', src)

    # do container types
    for memberName, m in t.members.items():
        self.gen_types.genSerializerSubtype_humon(self, m.properties)


def genSerializerSubtype_humon(self, typeDict):
    baseType = typeDict['type']

    if baseType == 'array':
        self.gen_containersSerializeToHumon.gen_array(self)
    elif baseType == 'pair':
        self.gen_containersSerializeToHumon.gen_pair(self)
    elif baseType == 'tuple':
        self.gen_containersSerializeToHumon.gen_tuple(self)
    elif baseType == 'vector':
        self.gen_containersSerializeToHumon.gen_vector(self)
    elif baseType == 'set':
        self.gen_containersSerializeToHumon.gen_set(self)
    elif baseType == 'unordered_set':
        self.gen_containersSerializeToHumon.gen_unordered_set(self)
    elif baseType == 'map':
        self.gen_containersSerializeToHumon.gen_map(self)
    elif baseType == 'unordered_map':
        self.gen_containersSerializeToHumon.gen_unordered_map(self)
    elif baseType == 'optional':
        self.gen_containersSerializeToHumon.gen_optional(self)
    elif baseType == 'variant':
        self.gen_containersSerializeToHumon.gen_variant(self)

    if typeDict.get('of'):
        for chDict in typeDict['of']:
            self.gen_types.genSerializerSubtype_humon(self, chDict)


def genSerializer_binary(self, t):
    self.gen_containersSerializeToBinary.gen_builtIn(self)
    it = self.indent()

    fmts = self.d('deserializeFrom')
    if not fmts or 'binary' not in fmts:
        self.forwardDeclareType(f'{t.name}|forwardDecls', 'ostream', f'{it}class ostream;', 'std')
    src = f'''
{it}std::ostream & operator <<(std::ostream & out, BinaryFormat<{t.name}> const & obj);'''
    self.appendSrc(f'{t.name}|forwardDecls', src)

    if not fmts or 'binary' not in fmts:
        self.forwardDeclareType(f'{t.name}|serializerDecl', 'ostream', f'{it}class ostream;', 'std')
    src = f'''
{it}{it}friend std::ostream & operator <<(std::ostream & out, BinaryFormat<{t.name}> const & obj);'''
    self.appendSrc(f'{t.name}|serializerDecl', src)

    self.includeForType(f'{t.name}|serialzierDef', 'ostream', f'''#include <iostream>''')
    src = f'''

{it}std::ostream & operator <<(std::ostream & out, BinaryFormat<{t.name}> const & obj)
{it}{{{self.cave('serializeBinary', f'"Writing {t.name}"', f'{t.name}|serialzierDef', 2)}'''

    for memberName, memberObj in t.members.items():
        src += f'''
{it}{it}out << BinaryFormat(obj->{memberName});'''
    src += f'''

{it}{it}return out;
{it}}}'''
    self.appendSrc(f'{t.name}|serialzierDef', src)

    # do container types
    for memberName, m in t.members.items():
        self.gen_types.genSerializerSubtype_binary(self, m.properties)


def genSerializerSubtype_binary(self, typeDict):
    baseType = typeDict['type']

    if baseType == 'array':
        self.gen_containersSerializeToBinary.gen_array(self)
    elif baseType == 'pair':
        self.gen_containersSerializeToBinary.gen_pair(self)
    elif baseType == 'tuple':
        self.gen_containersSerializeToBinary.gen_tuple(self)
    elif baseType == 'vector':
        self.gen_containersSerializeToBinary.gen_vector(self)
    elif baseType == 'set':
        self.gen_containersSerializeToBinary.gen_set(self)
    elif baseType == 'unordered_set':
        self.gen_containersSerializeToBinary.gen_unordered_set(self)
    elif baseType == 'map':
        self.gen_containersSerializeToBinary.gen_map(self)
    elif baseType == 'unordered_map':
        self.gen_containersSerializeToBinary.gen_unordered_map(self)
    elif baseType == 'optional':
        self.gen_containersSerializeToBinary.gen_optional(self)
    elif baseType == 'variant':
        self.gen_containersSerializeToBinary.gen_variant(self)

    if typeDict.get('of'):
        for chDict in typeDict['of']:
            self.gen_types.genSerializerSubtype_binary(self, chDict)


def genDefaultConstructor(self, t):
    if not self.dIs('defaultConstructible'):
        return

    it = self.indent()

    src = f'''
{it}{it}{t.name}();'''
    self.appendSrc(f'{t.name}|defaultCtrDecl', src)

    src = f'''

{it}{t.name}::{t.name}()
{it}{{{self.cave('ctr', f'"Default ctor: {t.name}"', f'{t.name}|defaultCtrDef', 2)}
{it}}}'''
    self.appendSrc(f'{t.name}|defaultCtrDef', src)


def genMemberwiseConstructor(self, t):
    if not self.dIs('memberwiseConstructible'):
        return

    if len(t.members) == 0:
        return

    it = self.indent()

    def foreachMemberName():
        for memberName, m in t.members.items():
            memberDecl = self.makeNativeMemberType(m.properties)
            yield (memberName, memberDecl)

    signature = ', '.join([f'{self.const(md)} & {mn}' for mn, md in foreachMemberName()])
    memberConstructors = ', '.join([f'{mn}({mn})' for mn, _ in foreachMemberName()])

    src = f'''
{it}{it}{t.name}({signature});'''
    self.appendSrc(f'{t.name}|memberwiseCtrDecl', src)

    src = f'''

{it}{t.name}::{t.name}({signature})
{it} : {memberConstructors}
{it}{{{self.cave('ctr', f'"Memberwise ctor: {t.name}"', f'{t.name}|memberwiseCtrDef', 2)}
{it}}}'''
    self.appendSrc(f'{t.name}|memberwiseCtrDef', src)


def genCopyConstructor(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    if self.dIs('copyable'):
        src = f'''
{it}{it}{t.name}({self.const(typeDecl)} & rhs);'''

        self.appendSrc(f'{t.name}|copyCtrDecl', src)

        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)

        memberConstructors = ', '.join([f'{mn}(rhs.{mn})' for mn, _ in foreachMemberName()])

        src = f'''

{it}{typeDecl}::{t.name}({self.const(typeDecl)} & rhs)
{it}: {memberConstructors}
{it}{{{self.cave('ctr', f'"Copy ctor: {t.name}"', f'{t.name}|copyCtrDef', 2)}
{it}}}'''

        self.appendSrc(f'{t.name}|copyCtrDef', src)

    else:
        defaultOrDelete = 'default' if self.dIs('copyable') else 'delete'
        src = f'''
{it}{it}{t.name}({self.const(typeDecl)} & rhs) = {defaultOrDelete};'''

        self.appendSrc(f'{t.name}|copyCtrDecl', src)


def genMoveConstructor(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    implOrDelete = ' noexcept;' if self.dIs('movable') else ' = delete;'

    src = f'''
{it}{it}{t.name}({typeDecl} && rhs){implOrDelete}'''

    self.appendSrc(f'{t.name}|moveCtrDecl', src)

    if self.dIs('movable'):

        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)

        memberConstructors = f'\n'.join([f'{it}{it}swap({mn}, rhs.{mn});' for mn, _ in foreachMemberName()])

        src = f'''

{it}{typeDecl}::{t.name}({typeDecl} && rhs) noexcept
{it}{{{self.cave('ctr', f'"Move ctor: {t.name}"', f'{t.name}|moveCtrDef', 2)}
{it}{it}using std::swap;
{memberConstructors}
{it}}}'''
    self.appendSrc(f'{t.name}|moveCtrDef', src)


def genCopyAssignment(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    if self.dIs('movable'):
        src = f'''
{it}{it}{typeDecl} & operator =({self.const(typeDecl)} & rhs);'''
        self.appendSrc(f'{t.name}|copyAssignDecl', src)

        src = f'''

{it}{typeDecl} & {typeDecl}::operator =({self.const(typeDecl)} & rhs)
{it}{{{self.cave('ass', f'"Copy assignment: {t.name}"', f'{t.name}|copyAssignDef', 2)}'''

        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)

        src += f''.join([f'\n{it}{it}{mn} = rhs.{mn};' for mn, _ in foreachMemberName()])

        src += f'''
{it}{it}return * this;
{it}}}'''
        self.appendSrc(f'{t.name}|copyAssignDef', src)

    else:
        defaultOrDelete = 'default' if self.dIs('copyable') else 'delete'
        src = f'''
{it}{it}{typeDecl} & operator =({self.const(typeDecl)} & rhs) = {defaultOrDelete};'''

        self.appendSrc(f'{t.name}|copyAssignDecl', src)


def genMoveAssignment(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    implOrDelete = ' noexcept;' if self.dIs('movable') else ' = delete;'

    src = f'''
{it}{it}{typeDecl} & operator =({typeDecl} && rhs){implOrDelete}'''

    self.appendSrc(f'{t.name}|moveAssignDecl', src)

    if self.dIs('movable'):
        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)

        memberConstructors = f'\n'.join([f'{it}{it}swap({mn}, rhs.{mn});' for mn, _ in foreachMemberName()])

        src = f'''

{it}{typeDecl} & {typeDecl}::operator =({typeDecl} && rhs) noexcept
{it}{{{self.cave('ass', f'"Move assignment: {t.name}"', f'{t.name}|moveAssignDef', 2)}
{it}{it}using std::swap;
{memberConstructors}
{it}{it}return * this;
{it}}}'''
    self.appendSrc(f'{t.name}|moveAssignDef', src)


def genDestructor(self, t):
    virtual = self.dIs('virtualDestructor')
    if virtual:
        virtual = 'virtual '
    else:
        virtual = ''

    it = self.indent()

    src = f'''
{it}{it}{virtual}~{t.name}();'''
    self.appendSrc(f'{t.name}|destructorDecl', src)

    src = f'''

{it}{t.name}::~{t.name}()
{it}{{{self.cave('dtr', f'"Destructor: {t.name}"', f'{t.name}|destructorDef', 2)}
{it}}}'''
    self.appendSrc(f'{t.name}|destructorDef', src)


def genSwap(self, t):
    if not self.dIs('movable'):
        return

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    self.forwardDeclareType(f'{t.name}|forwardClassDecl', t.name, f'''{it}class {t.name};''')

    src = f'''
{it}void swap({typeDecl} & lhs, {typeDecl} & rhs) noexcept;'''
    self.appendSrc(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend void swap({typeDecl} & lhs, {typeDecl} & rhs) noexcept;'''
    self.appendSrc(f'{t.name}|swapDecl', src)

    def foreachMemberName():
        for memberName, m in t.members.items():
            memberDecl = self.makeNativeMemberType(m.properties)
            yield (memberName, memberDecl)

    memberAssignments = '\n'.join([f'{it}{it}swap(lhs.{mn}, rhs.{mn});' for mn, _ in foreachMemberName()])

    src = f'''

{it}void swap({typeDecl} & lhs, {typeDecl} & rhs) noexcept
{it}{{
{it}{it}using std::swap;
{memberAssignments}
{it}}}'''
    self.appendSrc(f'{t.name}|swapDef', src)


def genGetters(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)
    inline = ''
    if self.d('outputForm') == 'headerOnly' and not self.dIs('inlineGetters'):
        inline = 'inline '

    def foreachMemberName():
        for memberName, m in t.members.items():
            memberDecl = self.makeNativeMemberType(m.properties)
            yield (memberName, memberDecl)

    maxMemberNameLen = 0
    maxMemberDeclLen = 0
    for memberName, memberDecl in foreachMemberName():
        maxMemberNameLen = max(len(memberName), maxMemberNameLen)
        maxMemberDeclLen = max(len(memberDecl), maxMemberDeclLen)

    for memberName, memberDecl in foreachMemberName():
        namePad = maxMemberNameLen - len(memberName)
        declPad = maxMemberDeclLen - len(memberDecl)
        if self.dIs('inlineGetters'):
            src = f'''
{it}{it}{inline}{memberDecl}{' ' * declPad}         get_{memberName}() &&{' ' * namePad}      {{ return {memberName}; }}'''
            if self.dIs('constGetters'):
                src += f'''
{it}{it}{inline}{self.const(memberDecl)}{' ' * declPad} & get_{memberName}() const &{' ' * namePad} {{ return {memberName}; }}'''
            if self.dIs('nonConstGetters'):
                src += f'''
{it}{it}{inline}{memberDecl}{' ' * declPad}       & get_{memberName}() &{' ' * namePad}       {{ return {memberName}; }}'''
        else:
            src = f'''
{it}{it}{inline}{memberDecl}{' ' * declPad}         get_{memberName}() &&;'''
            if self.dIs('constGetters'):
                src += f'''
{it}{it}{inline}{self.const(memberDecl)}{' ' * declPad} & get_{memberName}() const &;'''
            if self.dIs('nonConstGetters'):
                src += f'''
{it}{it}{inline}{memberDecl}{' ' * declPad}       & get_{memberName}() &;'''

        self.appendSrc(f'{t.name}|memberGettersDecl', src)

        if not self.dIs('inlineGetters'):
            src = f'''

{it}{inline}{memberDecl}{' ' * declPad}         {typeDecl}::get_{memberName}() &&{' ' * namePad}      {{ return {memberName}; }}'''
            if self.dIs('constGetters'):
                src += f'''
{it}{inline}{self.const(memberDecl)}{' ' * declPad} & {typeDecl}::get_{memberName}() const &{' ' * namePad} {{ return {memberName}; }}'''
            if self.dIs('nonConstGetters'):
                src += f'''
{it}{inline}{memberDecl}{' ' * declPad}       & {typeDecl}::get_{memberName}() &{' ' * namePad}       {{ return {memberName}; }}'''

            self.appendSrc(f'{t.name}|memberGettersDef', src)


def genSetters(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)
    inline = ''
    if self.d('outputForm') == 'headerOnly' and not self.dIs('inlineSetters'):
        inline = 'inline '

    def foreachMemberName():
        for memberName, m in t.members.items():
            memberDecl = self.makeNativeMemberType(m.properties)
            yield (memberName, memberDecl)

    maxMemberNameLen = 0
    maxMemberDeclLen = 0
    for memberName, memberDecl in foreachMemberName():
        maxMemberNameLen = max(len(memberName), maxMemberNameLen)
        maxMemberDeclLen = max(len(memberDecl), maxMemberDeclLen)

    for memberName, memberDecl in foreachMemberName():
        namePad = maxMemberNameLen - len(memberName)
        declPad = maxMemberDeclLen - len(memberDecl)
        src = ''
        if self.dIs('inlineSetters'):
            if self.dIs('setByCopy'):
                if self.dIs('movable'):
                    src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({memberDecl} new_{memberName}){' ' * (namePad + declPad)}    {{ using std::swap; swap({memberName}, new_{memberName}); }}'''
                else:
                    src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({self.const(memberDecl)} & new_{memberName}){' ' * (namePad + declPad)} {{ {memberName} = new_{memberName}; }}'''
            if self.dIs('setByMove'):
                src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({memberDecl} && new_{memberName}){' ' * (namePad + declPad)} {{ using std::swap; swap({memberName}, new_{memberName}); }}'''
        else:
            if self.dIs('setByCopy'):
                if self.dIs('movable'):
                    src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({memberDecl} new_{memberName});'''
                else:
                    src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({self.const(memberDecl)} & new_{memberName});'''
            if self.dIs('setByMove'):
                src += f'''
{it}{it}{inline}void {' ' * namePad}set_{memberName}({memberDecl} && new_{memberName});'''

        self.appendSrc(f'{t.name}|memberSettersDecl', src)

        src = '\n'
        if not self.dIs('inlineSetters'):
            if self.dIs('setByCopy'):
                if self.dIs('movable'):
                    src += f'''
{it}{inline}void {' ' * namePad}{t.name}::set_{memberName}({memberDecl} new_{memberName}){' ' * (namePad + declPad)}    {{ using std::swap; swap({memberName}, new_{memberName}); }}'''
                else:
                    src += f'''
{it}{inline}void {' ' * namePad}{t.name}::set_{memberName}({self.const(memberDecl)} & new_{memberName}){' ' * (namePad + declPad)} {{ {memberName} = new_{memberName}; }}'''
            if self.dIs('setByMove'):
                src += f'''
{it}{inline}void {' ' * namePad}{t.name}::set_{memberName}({memberDecl} && new_{memberName}){' ' * (namePad + declPad)} {{ using std::swap; swap({memberName}, new_{memberName}); }}'''

            self.appendSrc(f'{t.name}|memberSettersDef', src)


def genComparator(self, t):
    if not self.dIs('comparable'):
        return ''

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    self.forwardDeclareType(f'{t.name}|forwardClassDecl', t.name, f'''{it}class {t.name};''')

    src = f'''
{it}bool operator ==({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);
{it}bool operator !=({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);'''
    self.appendSrc(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend bool operator ==({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);
{it}{it}friend bool operator !=({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);'''
    self.appendSrc(f'{t.name}|comparatorDecl', src)

    src = f'''

{it}bool operator ==({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs)
{it}{{
{it}{it}return '''
    if len(t.members) > 0:
        src += f'''
{it}{it}    && '''.join([f'lhs.{mn} == rhs.{mn}' for mn in t.members.keys()])
    else:
        src += 'true'

    src += f''';
{it}}}

{it}bool operator !=({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs)
{it}{{
{it}{it}return !(lhs == rhs);
{it}}}'''
    self.appendSrc(f'{t.name}|comparatorDef', src)


def genTypeDiffer(self, t):
    if not self.dIs('diffable'):
        return

    self.gen_diffs.genTypeDiffer(self, t)


def genMembers(self, t):
    it = self.indent()
    src = ''

    self.gen_types.includeForType(self, f'{t.name}|members', t)

    if self.dIs('privateMembers'):
        src += f'''

{it}private:'''

    for memberName, m in t.members.items():
        typeDecl = self.makeNativeMemberType(m.properties)
        src += f'''
{it}{it}{typeDecl} {memberName};'''

    self.appendSrc(f'{t.name}|members', src)


def genClassEnd(self, t):
    it = self.indent()

    src = f'''
{it}}};
'''

    self.appendSrc(f'{t.name}|classEnd', src)
