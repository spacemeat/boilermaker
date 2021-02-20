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
        self.gen_containers.genDeserializers(self, t, deserializeMemo)
        self.gen_containers.genSerializers(self, t, serializersMemo)
        self.gen_containers.genIsLessStructs(self, t)
        self.gen_types.genDefaultConstructor(self, t)
        self.gen_types.genMemberwiseConstructor(self, t)
        self.gen_types.genCopyConstructor(self, t)
        self.gen_types.genMoveConstructor(self, t)
        self.gen_types.genCopyAssignment(self, t)
        self.gen_types.genMoveAssignment(self, t)
        self.gen_types.genVirtualDestructor(self, t)
        self.gen_types.genSwap(self, t)
        self.gen_types.genGetters(self, t)
        self.gen_types.genSetters(self, t)
        self.gen_types.genDeserializer(self, t)
        self.gen_types.genSerializer(self, t)
        self.gen_types.genComparator(self, t)
        self.gen_diffs.genTypeDiffer(self, t)
        self.gen_types.genMembers(self, t)
        self.gen_types.genClassEnd(self, t)
        self.defsData['type'] = None


def genIncludesInline(self, t):
    it = self.indent()
    self._addInclude(f'{t.name}|typeHeaderIncludeInline', f'{t.name}|typeSource')
    if self.d('outputForm') == 'headerOnly':
        self._addInclude(f'{t.name}|typeSourceLocalIncludes', f'{t.name}|typeHeader')
    else:
        # Source files include main header instead of their own type header. This allows
        # the bits defined in one type depend on those in another type, preserving dependency
        # order for those things memoized and defined only in one place.
        self._addInclude(f'{t.name}|typeSourceLocalIncludes', f'mainHeader')


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
    if (not self.dIs('serializeToHumon') and
        not self.dIs('comparable')):
        return ''

    it = self.indent()    

    src = f'''
{it}class {t.name};'''

    self._appendToSection(f'{t.name}|forwardClassDecl', src)


def genClassBegin(self, t):
    self._addInclude('mainHeaderIncludes', f'{t.name}|typeHeader')
    #self._addInclude('containersHeaderLocalIncludes', f'{t.name}|typeHeader')

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''

{it}class {typeDecl}
{it}{{
{it}public:'''

    self._appendToSection(f'{t.name}|classBegin', src)


def genSerializerFormatWrappers(self, format):
    '''format looks like 'Binary' or 'Humon'. It just names the selector template.'''

    if len(self.serializerFormatWrappers) == 0:
        src = f'''
{it}template <class T>
{it}struct SFS
{it}{{
{it}SFS(T const & t) : obj(t)  {{ }}
{it}T const & operator *() const {{ return obj; }}
{it}T const * operator ->() const {{ return & obj; }}
{it}T const & obj;
{it}}};'''
        self._appendToSection('serializerFormatWrappers', src)

    src = f'''

{it}template <class T>
{it}struct {format} : public SFS<T>
{it}{{
{it}{it}{format}(T const & t) : SFS<T>(t)  {{ }}
{it}}};'''
    self._appendToSection('serializerFormatWrappers', src)


def genDeserializer(self, t):
    if (not self.dIs('deserializeFromHumon')):
        return

    self._addInclude(f'{t.name}|typeHeaderIncludes', '<humon/humon.hpp>')

    
    #---
    if len(self.deserializerFormats) == 0:

    self.deserializerFormats.append()
    #---


    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}{it}{t.name}(hu::Node node)'''

    self._appendToSection(f'{t.name}|humonCtrDecl', src + ';')

    src = f'''

{it}{t.name}::{t.name}(hu::Node node)
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
{it}{it}static inline {typeDecl} extract(hu::Node const & node);
{it}}};'''

    self._appendToSection(f'{t.name}|typeDeserializerDecl', src)

    src = f'''
template<>
struct hu::val<{typeDecl}>
{{
{it}static inline {typeDecl} extract(hu::Node const & node)
{it}{{
{it}{it}return {typeDecl}(node);
{it}}}
}};'''

    self._appendToSection(f'{t.name}|typeDeserializerDef', src)


def genSerializer(self, t):
    fmts = self.d('serializeTo')
    if (not fmts):
        return

    for fmt in fmts:
        if fmt.tolower() == 'humon':
            genSerializerToHumon(self, t):
        elif fmt.tolower() == 'binary':
            genSerializerToHumon(self, t):


def genSerializerToHumon(self, t):
    it = self.indent()

    src = f'''
{it}std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj);'''
    self._appendToSection(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj);'''
    self._appendToSection(f'{t.name}|serializerDecl', src)

    src = f'''

{it}std::ostream & operator <<(std::ostream & out, HumonFormat<{t.name}> const & obj)
{it}{{
{it}{it}out << '{{';'''
    for memberName, memberObj in t.members.items():
        typeDecl = self.makeNativeMemberType(memberObj.properties)
        if memberObj.properties['type'] == 'optional':
            src += f'''
{it}{it}if (obj.{memberName}.has_value()) {{ out << " HumonFormat({memberName}): " << obj.{memberName}; }}'''
        else:
            src += f'''
{it}{it}out << " {memberName}: " << HumonFormat(obj.{memberName});'''
    src += f'''
{it}{it}out << '}}';
{it}{it}return out;
{it}}}'''

    self._appendToSection(f'{t.name}|serialzierDef', src)


def genDefaultConstructor(self, t):
    if not self.dIs('defaultConstructible'):
        return

    it = self.indent()

    src = f'''
{it}{it}{t.name}();'''
    self._appendToSection(f'{t.name}|defaultCtrDecl', src)

    src = f'''

{it}{t.name}::{t.name}()
{it}{{ }}'''
    self._appendToSection(f'{t.name}|defaultCtrDef', src)


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
    self._appendToSection(f'{t.name}|memberwiseCtrDecl', src)

    src = f'''

{it}{t.name}::{t.name}({signature})
{it} : {memberConstructors}
{it}{{ }}'''
    self._appendToSection(f'{t.name}|memberwiseCtrDef', src)


def genCopyConstructor(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    defaultOrDelete = 'default' if self.dIs('copyable') else 'delete'
    src = f'''
{it}{it}{t.name}({self.const(typeDecl)} & rhs) = {defaultOrDelete};'''

    self._appendToSection(f'{t.name}|copyCtrDecl', src)


def genMoveConstructor(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    implOrDelete = ' noexcept;' if self.dIs('movable') else ' = delete;'

    src = f'''
{it}{it}{t.name}({typeDecl} && rhs){implOrDelete}'''

    self._appendToSection(f'{t.name}|moveCtrDecl', src)

    if self.dIs('movable'):

        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)
        
        memberConstructors = f'\n'.join([f'{it}{it}swap({mn}, rhs.{mn});' for mn, _ in foreachMemberName()])

        src = f'''

{it}{typeDecl}::{t.name}({typeDecl} && rhs) noexcept
{it}{{
{it}{it}using std::swap;
{memberConstructors}
{it}}}'''

        self._appendToSection(f'{t.name}|moveCtrDef', src)


def genCopyAssignment(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    defaultOrDelete = 'default' if self.dIs('copyable') else 'delete'
    src = f'''
{it}{it}{typeDecl} & operator =({self.const(typeDecl)} & rhs) = {defaultOrDelete};'''

    self._appendToSection(f'{t.name}|copyAssignDecl', src)


def genMoveAssignment(self, t):
    it = self.indent()
    typeDecl = self.makeNative(t.name)

    implOrDelete = ' noexcept;' if self.dIs('movable') else ' = delete;'

    src = f'''
{it}{it}{typeDecl} & operator =({typeDecl} && rhs){implOrDelete}'''

    self._appendToSection(f'{t.name}|moveAssignDecl', src)

    if self.dIs('movable'):
        def foreachMemberName():
            for memberName, m in t.members.items():
                memberDecl = self.makeNativeMemberType(m.properties)
                yield (memberName, memberDecl)
        
        memberConstructors = f'\n'.join([f'{it}{it}swap({mn}, rhs.{mn});' for mn, _ in foreachMemberName()])

        src = f'''

{it}{typeDecl} & {typeDecl}::operator =({typeDecl} && rhs) noexcept
{it}{{
{it}{it}using std::swap;
{memberConstructors}
{it}{it}return * this;
{it}}}'''

        self._appendToSection(f'{t.name}|moveAssignDef', src)


def genVirtualDestructor(self, t):
    if not self.dIs('virtualDestructor'):
        return
    
    it = self.indent()

    src = f'''
{it}{it}virtual ~{t.name}();'''
    self._appendToSection(f'{t.name}|destructorDecl', src)

    src = f'''

{it}{t.name}::~{t.name}()
{it}{{ }}'''
    self._appendToSection(f'{t.name}|destructorDef', src)
  

def genSwap(self, t):
    if not self.dIs('movable'):
        return

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}void swap({typeDecl} & lhs, {typeDecl} & rhs) noexcept;'''
    self._appendToSection(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend void swap({typeDecl} & lhs, {typeDecl} & rhs) noexcept;'''
    self._appendToSection(f'{t.name}|swapDecl', src)

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
    self._appendToSection(f'{t.name}|swapDef', src)


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
            
        self._appendToSection(f'{t.name}|memberGettersDecl', src)

        if not self.dIs('inlineGetters'):
            src = f'''

{it}{inline}{memberDecl}{' ' * declPad}         {typeDecl}::get_{memberName}() &&{' ' * namePad}      {{ return {memberName}; }}'''
            if self.dIs('constGetters'):
                src += f'''
{it}{inline}{self.const(memberDecl)}{' ' * declPad} & {typeDecl}::get_{memberName}() const &{' ' * namePad} {{ return {memberName}; }}'''
            if self.dIs('nonConstGetters'):
                src += f'''
{it}{inline}{memberDecl}{' ' * declPad}       & {typeDecl}::get_{memberName}() &{' ' * namePad}       {{ return {memberName}; }}'''

            self._appendToSection(f'{t.name}|memberGettersDef', src)


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

        self._appendToSection(f'{t.name}|memberSettersDecl', src)

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

            self._appendToSection(f'{t.name}|memberSettersDef', src)


def genComparator(self, t):
    if not self.dIs('comparable'):
        return ''

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}bool operator ==({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);
{it}bool operator !=({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);'''
    self._appendToSection(f'{t.name}|forwardDecls', src)

    src = f'''
{it}{it}friend bool operator ==({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);
{it}{it}friend bool operator !=({self.const(typeDecl)} & lhs, {self.const(typeDecl)} & rhs);'''
    self._appendToSection(f'{t.name}|comparatorDecl', src)

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
    self._appendToSection(f'{t.name}|comparatorDef', src)


def genMembers(self, t):
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

    self._appendToSection(f'{t.name}|members', src)


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
    it = self.indent()

    src = f'''
{it}}};
'''

    self._appendToSection(f'{t.name}|classEnd', src)
