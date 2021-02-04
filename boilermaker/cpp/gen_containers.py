from .. import utilities


def genSerializers(self, t, memo):
    if (not self.dIs('computeTypes') or
        not self.dIs('serializeToHumon')):
        return ''

    for _, memberObj in t.members.items():
        self.gen_containers._genSerializer(self, t, memberObj, memo)


def _genSerializer(self, t, m, memo):
    print (f'$$$ gcs({t.name}, {m.name})')

    self._addInclude(f'containersInlineSource', '<iostream>', 'containersInlineSourceIncludes')

    def recurse(phase, memo, typeDict):
        memberDeclType = self.makeNativeMemberType(typeDict)
        print (memberDeclType)
        if memberDeclType not in memo:
            memo[memberDeclType] = {phase: None}
        elif phase not in memo[memberDeclType]:
            memo[memberDeclType][phase] = None
        else:
            return ''

        baseType = typeDict['type']

        if baseType == 'size_t':
            self._addInclude(f'containersInlineSource', '<cstddef>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'string':
            self._addInclude(f'containersInlineSource', '<string>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'string_view':
            self._addInclude(f'containersInlineSource', '<string_view>', f'{t.name}.typeInlineSourceIncludes')
        
        # #include the inl for a StructType
        elif baseType in self.types:
            self._addInclude(f'containersInlineSource', f'"{self.d("typeInlineHeaderFile", {"type": baseType})}"', f'{t.name}.typeInlineSourceLocalIncludes')

        if baseType not in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return ''

        if baseType == 'array':
            self._addInclude(f'containersInlineSource', '<array>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'pair':
            self._addInclude(f'containersInlineSource', '<utility>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'tuple':
            self._addInclude(f'containersInlineSource', '<tuple>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'vector':
            self._addInclude(f'containersInlineSource', '<vector>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'set':
            self._addInclude(f'containersInlineSource', '<set>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'unordered_set':
            self._addInclude(f'containersInlineSource', '<unordered_set>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'map':
            self._addInclude(f'containersInlineSource', '<map>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'unordered_map':
            self._addInclude(f'containersInlineSource', '<unordered_map>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'optional':
            self._addInclude(f'containersInlineSource', '<optional>', f'{t.name}.typeInlineSourceIncludes')
        elif baseType == 'variant':
            self._addInclude(f'containersInlineSource', '<variant>', f'{t.name}.typeInlineSourceIncludes')

        print (f'$$$ --- gcs({typeDict})')

        src = ''
        it = self.indent()
        ofProps = typeDict.get('of')
        if ofProps:
            for prop in utilities.listify(ofProps):
                src += recurse(phase, memo, utilities.dictify(prop, 'type'))

        src += f'''
{it}inline std::ostream & operator <<(std::ostream & out, {memberDeclType} const & obj) noexcept'''
        if phase == 'classDecl':
            src += f';'
        elif phase == 'classDef':
            src += f'''
{it}{{{self.gen_containers._genCsBody(self, typeDict)}
{it}{it}return out;
{it}}}'''
        return src
    
    src = recurse('classDecl', memo, m.properties)
    self._appendToSection(f'containerSerializerDecl', src)

    src = recurse('classDef', memo, m.properties)
    self._appendToSection(f'containerSerializerDef', src)

    kind = f'{t.name}.typeInlineSource'
    self._addInclude(kind, f'"{self.d("containersInlineHeaderFile")}"', f'{t.name}.typeInlineSourceLocalIncludes')



def _genCsBody(self, typeDict):
    it = self.indent()

    src = ''

    baseType = typeDict['type']
    if baseType == 'array':
        src += f"""
{it}{it}out << '[';"""
        for i in range(0, int(typeDict['of'][1])):
            if i > 0:
                src += f"""
{it}{it}out << ' ';"""
            src += f"""
{it}{it}out << obj[{i}];"""
        src += f"""
{it}{it}out << ']';"""

    elif baseType == 'pair':
        src += f"""
{it}{it}out << '[';
{it}{it}out << std::get<0>(obj);
{it}{it}out << ' ';
{it}{it}out << std::get<1>(obj);
{it}{it}out << ']';"""

    elif baseType == 'tuple':
        mbtas = [self.makeNativeMemberType(ch) for ch in utilities.listify(typeDict['of'])]
        src += f"""
{it}{it}out << '[';"""
        first = True
        for i in range(0, len(mbtas)):
            mbtan = mbtas[i]
            if not first:
                src += f"""
{it}{it}out << ' ';"""
            else:
                first = False
            src += f"""
{it}{it}out << std::get<{i}>(obj);"""
        src += f"""
{it}{it}out << ']';"""

    elif baseType == 'vector' or baseType == 'set' or baseType == 'unordered_set':
        src += f"""
{it}{it}out << '[';
{it}{it}bool firstTime = true;
{it}{it}for (auto const & objmem : obj)
{it}{it}{{
{it}{it}{it}if (firstTime)
{it}{it}{it}{it}{{ firstTime = false; }}
{it}{it}{it}else
{it}{it}{it}{it}{{ out << ' '; }}
{it}{it}{it}out << objmem;
{it}{it}}}
{it}{it}out << ']';"""

    elif baseType == 'map' or baseType == 'unordered_map':
        if utilities.listify(typeDict['of'][0]) == 'optional':
            raise RuntimeError('a map or unordered_map key cannot be optional.')
        src += f"""
{it}{it}out << '{{';
{it}{it}bool firstTime = true;
{it}{it}for (auto & elem : obj)
{it}{it}{{
{it}{it}{it}if (firstTime)
{it}{it}{it}{it}{{ firstTime = false; }}
{it}{it}{it}else
{it}{it}{it}{it}{{ out << ' '; }}
{it}{it}{it}out << elem.first << ": " << elem.second;
{it}{it}}}
{it}{it}out << '}}';"""

    elif baseType == 'optional':
        src += f"""
{it}if (obj.has_value())
{it}{it}{{ out << * obj; }}
{it}else
{it}{it}{{ out << '_'; }}"""

    elif baseType == 'variant':
        subTypes = utilities.listify(typeDict['of'])
        firstTime = True
        for subType in subTypes:
            chDecl = self.makeNativeMemberType(utilities.dictify(subType, 'type'))
            chAlias = subType.get('alias')         
            if firstTime:
                firstTIme = False
                src += f'''
{it}{it}'''
            else:
                src += f'''
{it}{it}else '''
            src += f'''if (auto p = std::get_if<{chDecl}>(& obj); p) {{ out << *p << " @type: {chAlias}"; }}'''
    return src
