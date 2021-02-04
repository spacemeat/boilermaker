from .. import utilities

def genForwardClassDecl(self, t):
    if (not self.dIs('computeTypes') or
        (not self.dIs('serializeToHumon') and
         not self.dIs('comparable'))):
        return ''

    it = self.indent()    

    src = f'''
{it}class {t.name};'''

    self._appendToSection(f'{t.name}.forwardClassDecl', src)


def genClassBegin(self, t):
    if (not self.dIs('computeTypes')):
        return ''

    self._addInclude('mainHeader', 
        '/'.join([self.d('headerToInl'), self.d('typeInlineHeaderFile')])
           .join(['"', '"']),
        'mainHeaderIncludes')
    
    breakpoint()
    self._addInclude('containersInlineSource',
        f'"{self.d(f"typeInlineHeaderFile")}"',
        'containersInlineSourceLocalIncludes')

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''

{it}class {typeDecl}
{it}{{'''

    self._appendToSection(f'{t.name}.classBegin', src)


def genSerializer(self, t):
    if (not self.dIs('computeTypes') or
        not self.dIs('serializeToHumon')):
        return ''
    
    it = self.indent()

    src = f'''
{it}std::ostream & operator <<(std::ostream & out, {t.name} const & obj) noexcept;'''
    self._appendToSection(f'{t.name}.forwardDecls', src)

    src = f'''
{it}{it}friend std::ostream & operator <<(std::ostream & out, {t.name} const & obj) noexcept;'''
    self._appendToSection(f'{t.name}.serialzierDecl', src)

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

    self._appendToSection(f'{t.name}.serialzierDef', src)


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

    self._appendToSection(f'{t.name}.serialzierDecl', src)


def _acquireIncludes(self, t, typeDict):
    baseType = typeDict['type']

    if baseType == 'size_t':
        self._addInclude(f'{t.name}.typeInlineSource', '<cstddef>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'string':
        self._addInclude(f'{t.name}.typeInlineSource', '<string>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'string_view':
        self._addInclude(f'{t.name}.typeInlineSource', '<string_view>', f'{t.name}.typeInlineSourceIncludes')
    
    # #include the inl for a StructType
    elif baseType in self.types:
        self._addInclude(f'{t.name}.typeInlineSource', f'"{self.d("typeInlineHeaderFile", {"type": baseType})}"', f'{t.name}.typeInlineSourceLocalIncludes')

    if baseType == 'array':
        self._addInclude(f'{t.name}.typeInlineSource', '<array>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'pair':
        self._addInclude(f'{t.name}.typeInlineSource', '<utility>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'tuple':
        self._addInclude(f'{t.name}.typeInlineSource', '<tuple>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'vector':
        self._addInclude(f'{t.name}.typeInlineSource', '<vector>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'set':
        self._addInclude(f'{t.name}.typeInlineSource', '<set>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'unordered_set':
        self._addInclude(f'{t.name}.typeInlineSource', '<unordered_set>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'map':
        self._addInclude(f'{t.name}.typeInlineSource', '<map>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'unordered_map':
        self._addInclude(f'{t.name}.typeInlineSource', '<unordered_map>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'optional':
        self._addInclude(f'{t.name}.typeInlineSource', '<optional>', f'{t.name}.typeInlineSourceIncludes')
    elif baseType == 'variant':
        self._addInclude(f'{t.name}.typeInlineSource', '<variant>', f'{t.name}.typeInlineSourceIncludes')

    if typeDict.get('of'):
        for subType in utilities.listify(typeDict['of']):
            self.gen_types._acquireIncludes(self, t, utilities.dictify(subType, 'type'))
    

def genClassEnd(self, t):
    if (not self.dIs('computeTypes')):
        return ''
    
    self._addInclude('mainHeader', 
        '/'.join([self.d('headerToInl'), self.d('typeInlineHeaderFile')])
           .join(['"', '"']),
           'mainHeaderIncludes')

    it = self.indent()
    typeDecl = self.makeNative(t.name)

    src = f'''
{it}}}; // end class {typeDecl}
'''

    self._appendToSection(f'{t.name}.classEnd', src)


