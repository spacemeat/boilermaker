from .. import utilities


def genAll(self):
    if not self.dIs('computeTypes'):
        return ''
    
    self.gen_types.genAllTypeForwardDecls(self)

    deserializeMemo = {}
    serializersMemo = {}
    for typeName, t in self.types.items():
        self.defsData['type'] = typeName
        self.gen_types.genIncludesInline(self, t)
        self.gen_types.genForwardClassDecl(self, t)
        self.gen_types.genClassBegin(self, t)
        self.gen_types.genClassEnd(self, t)
        self.gen_containers.genDeserializers(self, t, deserializeMemo)
        self.gen_containers.genSerializers(self, t, serializersMemo)
        self.gen_types.genDeserializer(self, t)
        self.gen_types.genSerializer(self, t)
        self.gen_types.genMembers(self, t)
        self.defsData['type'] = None


def genIncludesInline(self, t):
    it = self.indent()
    self._addInclude(f'{t.name}|typeHeaderIncludeInline', f'{t.name}|typeSource')
    self._addInclude(f'{t.name}|typeSourceLocalIncludes', f'{t.name}|typeHeader')
    #self._addInclude(f'{t.name}|typeSourceLocalIncludes', 'containersSource')


#### this may go away
def genAllTypeForwardDecls(self):
    it = self.indent()    
    for typeName, t in self.types.items():
        memo = {}

        # because deserializeFromHumon includes humon, which already surfaces std::ostream.
        if not self.dIs('deserializeFromHumon'):
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}class ostream;''')

        #for memberName, m in t.members.items():
        #    self.gen_types._acquireForwards(self, t, m.properties, memo)
#### end of this may go away


def genForwardClassDecl(self, t):
    if (not self.dIs('computeTypes') or
        (not self.dIs('serializeToHumon') and
         not self.dIs('comparable'))):
        return ''

    it = self.indent()    

    src = f'''
{it}class {t.name};'''

    self._appendToSection(f'{t.name}|forwardClassDecl', src)


def genClassBegin(self, t):
    if (not self.dIs('computeTypes')):
        return ''

    self._addInclude('mainHeaderIncludes', f'{t.name}|typeHeader')
    #self._addInclude('containersHeaderLocalIncludes', f'{t.name}|typeHeader')

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''

{it}class {typeDecl}
{it}{{
{it}public:'''

    self._appendToSection(f'{t.name}|classBegin', src)


def genDeserializer(self, t):
    if (not self.dIs('computeTypes') or
        not self.dIs('deserializeFromHumon')):
        return

    self._addInclude(f'{t.name}|typeHeaderIncludes', '<humon/humon.hpp>')

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}{it}{t.name}(hu::Node node) noexcept'''

    self._appendToSection(f'{t.name}|humonCtrDecl', src + ';')

    src = f'''

{it}{t.name}::{t.name}(hu::Node node) noexcept
'''
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
{it}{{
{it}}}'''
# TODO: {it}{self.cavePerson(f'{self.getNamespaceScope()}{podNode.key}::ctr from humon')}

    self._appendToSection(f'{t.name}|humonCtrDef', src)

    typeDecl = self.makeNative(t.name, True)

    src = f'''
{it}template<>
{it}struct hu::val<{typeDecl}>
{it}{{
{it}{it}static inline {typeDecl} extract(hu::Node const & node) noexcept;
{it}}};'''

    self._appendToSection(f'{t.name}|typeDeserializerDecl', src)

    src = f'''
template<>
struct hu::val<{typeDecl}>
{{
{it}inline {typeDecl} extract(hu::Node const & node) noexcept
{it}{{
{it}{it}return {typeDecl}(node);
{it}}}
}};'''

    self._appendToSection(f'{t.name}|typeDeserializerDef', src)


def genSerializer(self, t):
    if (not self.dIs('computeTypes') or
        not self.dIs('serializeToHumon')):
        return ''

    it = self.indent()

    src = f'''
{it}std::ostream & operator <<(std::ostream & out, {t.name} const & obj) noexcept;'''
    self._appendToSection(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend std::ostream & operator <<(std::ostream & out, {t.name} const & obj) noexcept;'''
    self._appendToSection(f'{t.name}|serialzierDecl', src)

    src = f'''

{it}std::ostream & operator <<(std::ostream & out, {t.name} const & obj) noexcept
{it}{{
{it}{it}out << '{{';'''
    for memberName, memberObj in t.members.items():
        typeDecl = self.makeNativeMemberType(memberObj.properties)
        if memberObj.properties['type'] == 'optional':
            src += f'''
{it}{it}if (obj.{memberName}.has_value()) {{ out << " {memberName}: " << obj.{memberName}; }}'''
        else:
            src += f'''
{it}{it}out << " {memberName}: " << obj.{memberName};'''
    src += f'''
{it}{it}out << '}}';
{it}{it}return out;
{it}}}'''

    self._appendToSection(f'{t.name}|serialzierDef', src)


def genMembers(self, t):
    if (not self.dIs('computeTypes')):
        return ''

    it = self.indent()
    src = ''

    if self.dIs('privateMembers'):
        src += f'''
{it}private:'''

    for memberName, m in t.members.items():
        self.gen_types._acquireIncludes(self, t, m.properties)
        typeDecl = self.makeNativeMemberType(m.properties)
        src += f'''
{it}{it}{typeDecl} {memberName};'''

    self._appendToSection(f'{t.name}|serialzierDecl', src)


#### This may die
def _acquireForwards(self, t, typeDict, memo):
    baseType = typeDict['type']
    it = self.indent()

    if baseType not in memo:
        memo[baseType] = None
        
        if baseType == 'size_t':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}class size_t;''')
        elif baseType == 'string':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}class string;''')
        elif baseType == 'string_view':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}class string_view;''')
        if baseType == 'array':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class T, size_t N> class array;''')
        elif baseType == 'pair':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class T1, class T2> class pair;''')
        elif baseType == 'tuple':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class... Types> class tuple;''')
        elif baseType == 'vector':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class T, class Allocator = std::allocator<T>> class vector;''')
        elif baseType == 'set':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;''')
        elif baseType == 'unordered_set':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_set;''')
        elif baseType == 'map':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class map;''')
        elif baseType == 'unordered_map':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_map;''')
        elif baseType == 'optional':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class T> class optional;''')
        elif baseType == 'variant':
            self._appendToSection(f'{t.name}|stdForwardDecls', f'''
{it}template <class... Types> class variant;''')

    if typeDict.get('of'):
        for subType in utilities.listify(typeDict['of']):
            self.gen_types._acquireForwards(self, t, utilities.dictify(subType, 'type'), memo)
#### end of this may die


def _acquireIncludes(self, t, typeDict):
    baseType = typeDict['type']
    
    if baseType == 'size_t':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<cstddef>')
    elif baseType == 'string':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<string>')
    elif baseType == 'string_view':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<string_view>')
    
    # #include the inl for a StructType
    elif baseType in self.types:
        self._addInclude(f'{t.name}|typeHeaderLocalIncludes', f'{baseType}|typeHeader')

    if baseType == 'array':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<array>')
    elif baseType == 'pair':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<utility>')
    elif baseType == 'tuple':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<tuple>')
    elif baseType == 'vector':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<vector>')
    elif baseType == 'set':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<set>')
    elif baseType == 'unordered_set':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<unordered_set>')
    elif baseType == 'map':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<map>')
    elif baseType == 'unordered_map':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<unordered_map>')
    elif baseType == 'optional':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<optional>')
    elif baseType == 'variant':
        self._addInclude(f'{t.name}|typeHeaderIncludes', '<variant>')

    if typeDict.get('of'):
        for subType in utilities.listify(typeDict['of']):
            self.gen_types._acquireIncludes(self, t, utilities.dictify(subType, 'type'))
    

def genClassEnd(self, t):
    if (not self.dIs('computeTypes')):
        return ''
    
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}}}; // end class {typeDecl}
'''

    self._appendToSection(f'{t.name}|classEnd', src)


