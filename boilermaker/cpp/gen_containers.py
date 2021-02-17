from .. import utilities


def genAll(self):
    if not self.dIs('computeTypes') :
        return ''

    # self._addInclude('mainHeaderIncludes', 'containersHeader')

    # self._addInclude('containersHeaderIncludeInline', 'containersSource')

    if not self.dIs('deserializeFromHumon'):
        it = self.indent()
        self._appendToSection('containersStdForwardDecls', f'''
{it}class ofstream;''')

    forwardDeclsMemo = {}
    deserializersMemo = {}
    serializersMemo = {}
    for typeName, t in self.types.items():
        self.defsData['type'] = typeName
        self.gen_containers.genAllForwardDecls(self, t, forwardDeclsMemo)
        #self.gen_containers.genDeserializers(self, t, deserializersMemo)
        #self.gen_containers.genSerializers(self, t, serializersMemo)
        self.defsData['type'] = None


def genAllForwardDecls(self, t, memo):
    for _, memberObj in t.members.items():
        self.gen_containers._genForwardDecls(self, t, memberObj, memo)


def _genForwardDecls(self, t, m, memo):
    it = self.indent()

    def recurse(memo, typeDict):
        baseType = typeDict['type']

        if baseType not in memo:
            memo[baseType] = None

            if baseType == 'size_t':
                self._appendToSection('containersStdForwardDecls', f'''
{it}class size_t;''')
            elif baseType == 'string':
                self._appendToSection('containersStdForwardDecls', f'''
{it}class string;''')
            elif baseType == 'string_view':
                self._appendToSection('containersStdForwardDecls', f'''
{it}class string_view;''')
            
            # #include the inl for a StructType
            elif baseType in self.types:
                pass # self._addInclude(f'containersSourceLocalIncludes', f'{baseType}|typeHeader')

            elif baseType == 'array':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class T, size_t N> class array;''')
            elif baseType == 'pair':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class T1, class T2> class pair;''')
            elif baseType == 'tuple':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class... Types> class tuple;''')
            elif baseType == 'vector':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class T, class Allocator = std::allocator<T>> class vector;''')
            elif baseType == 'set':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class set;''')
            elif baseType == 'unordered_set':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class Key, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_set;''')
            elif baseType == 'map':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<Key>> class map;''')
            elif baseType == 'unordered_map':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class Key, class T, class Hash = std::hash<Key>, class KeyEqual = std::equal_to<Key>, class Allocator = std::allocator<Key>> class unordered_map;''')
            elif baseType == 'optional':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class T> class optional;''')
            elif baseType == 'variant':
                self._appendToSection('containersStdForwardDecls', f'''
{it}template <class... Types> class variant;''')

        ofProps = typeDict.get('of')
        if ofProps:
            for prop in utilities.listify(ofProps):
                recurse(memo, utilities.dictify(prop, 'type'))
    
    recurse(memo, m.properties)


def genDeserializers(self, t, memo):
    if (not self.dIs('computeTypes') or
        not self.dIs('deserializeFromHumon')):
        return ''

    # self._addInclude('mainHeaderIncludes', 'containersHeader')
    # self._addInclude('containersHeaderIncludes', '<humon/humon.hpp>')
    for _, memberObj in t.members.items():
        src = self.gen_containers._genDeserializer(self, t, memberObj.properties, memo)


def _genDeserializer(self, t, mProps, memo):
    it = self.indent()
    endl = '\n'
    src = ''

    self._addInclude(f'{t.name}|typeHeaderIncludes', '<humon/humon.hpp>')

    declType = self.makeNativeMemberType(mProps, True) # mpt

    if declType in memo:
        return
    memo[declType] = None

    baseType = mProps['type'] # mbt
    if baseType in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
        typeArgs = [utilities.dictify(a, 'type') for a in utilities.listify(mProps['of'])]

        for arg in typeArgs:
            self.gen_containers._genDeserializer(self, t, arg, memo)
        
        src = f'''

template <>
struct hu::val<{declType}>
{{
{it}static inline {declType} extract(hu::Node const & node)
{it}{{'''
      
        if baseType == 'array':
            argDeclType = self.makeNativeMemberType(typeArgs[0], True)
            numElems = int(typeArgs[1]['type'])
            src += f'''
{it}{it}return {declType} {{
{f",{endl}".join([f'{it}{it}{it}node / {i} % hu::val<{argDeclType}> {{}}' for i in range(0, numElems)])}
{it}{it}}};'''

        elif baseType == 'pair':
            ept0 = self.makeNativeMemberType(typeArgs[0], True)
            ept1 = self.makeNativeMemberType(typeArgs[1], True)
            src += f'''
{it}{it}return {declType} {{
{it}{it}{it}node / 0 % hu::val<{ept0}> {{ }},
{it}{it}{it}node / 1 % hu::val<{ept1}> {{ }}
{it}{it}}};'''
            #{it}{it}{it}std::move(hu::val<{ept0}>::extract(node / 0)),
            #{it}{it}{it}std::move(hu::val<{ept1}>::extract(node / 1))

        elif baseType == 'tuple':
            epts = [self.makeNativeMemberType(typeArg, True) for typeArg in typeArgs]
            src += f'''
{it}{it}return {declType} {{
{f',{endl}'.join([f"{it}{it}{it}node / {i} % hu::val<{epts[i]}> {{ }}" for i in range(0, len(epts))])}
{it}{it}}};'''
            #{f',{endl}'.join([f"{it}{it}{it}std::move(hu::val<{epts[i]}>::extract(node / {i}))" for i in range(0, len(epts))])}

        elif baseType == 'vector' or baseType == 'set' or baseType == 'unordered_set':
            elemPlatformType = self.makeNativeMemberType(typeArgs[0], True)
            src += f'''
{it}{it}{declType} rv;
{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{{
{it}{it}{it}rv.emplace{'_back' if baseType == 'vector' else ''}(node / i % hu::val<{elemPlatformType}>{{}});
{it}{it}}}
{it}{it}return rv;'''
#{it}{it}{it}rv.emplace{'_back' if baseType == 'vector' else ''}(std::move(node / i % hu::val<{elemPlatformType}>{{}}));

        elif baseType == 'map' or baseType == 'unordered_map':
            eptkey = self.makeNativeMemberType(typeArgs[0], True)
            eptvalue = self.makeNativeMemberType(typeArgs[1], True)
            src += f'''
{it}{it}{declType} rv;
{it}{it}for (size_t i = 0; i < node.numChildren(); ++i)
{it}{it}{{
{it}{it}{it}hu::Node elemNode = node / i;
{it}{it}{it}rv.emplace(std::move(hu::val<{eptkey}>::extract(elemNode.key().str())),
{it}{it}{it}           std::move(elemNode % hu::val<{eptvalue}>{{}}));
{it}{it}}}
{it}{it}return rv;'''

        elif baseType == 'optional':
            ept = self.makeNativeMemberType(typeArgs[0], True)
            src += f'''
{it}{it}if (! node)
{it}{it}{it}{{ return {{}}; }}
{it}{it}else if (node.kind() == NodeKind::value && node.value().str() == "_")
{it}{it}{it}{{ return {{}}; }}
{it}{it}else
{it}{it}{it}{{ return node % hu::val<{ept}>{{}}; }}'''

        elif baseType == 'variant':
            if self.d('nullVariant') == 'default':
                nullOperation = f'''return {{ }};'''
            else:
                nullOperation = f'''throw std::runtime_error("Variant could not be initialized.");'''
            src += f'''
{it}{it}Token tok = node.annotation("type");
{it}{it}if (! tok)
{it}{it}{it}{{ {nullOperation} }}
{it}{it}std::string_view tokStr = tok.str();'''

            for arg in typeArgs:
                arg = utilities.dictify(arg, 'type')
                argDecl = self.makeNativeMemberType(arg, True)
                alias = arg.get('alias')
                if not alias:
                    alias = arg.get('type')

                src += f'''
{it}{it}if (tokStr == "{alias}")
{it}{it}{it}{{ return node % hu::val<{argDecl}>{{}}; }}'''
            src += f'''
{it}{it}{nullOperation}'''

        src += f'''
{it}}}
}};'''
    
        self._appendToSection(f'{t.name}|containerDeserializerDefs', src)


def genSerializers(self, t, memo):
    if (not self.dIs('computeTypes') or
        not self.dIs('serializeToHumon')):
        return ''

    # self._addInclude('mainHeaderIncludes', 'containersHeader')
    # self._addInclude('containersHeaderIncludes', '<iostream>')

    for _, memberObj in t.members.items():
        self.gen_containers._genSerializer(self, t, memberObj, memo)


def _genSerializer(self, t, m, memo):
    it = self.indent()

    def recurse(phase, memo, typeDict):
        memberDeclType = self.makeNativeMemberType(typeDict)
        #print (memberDeclType)
        if memberDeclType not in memo:
            memo[memberDeclType] = {phase: None}
        elif phase not in memo[memberDeclType]:
            memo[memberDeclType][phase] = None
        else:
            return ''

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

        # go until we are at a leaf node (no 'of' subtypes)
        if baseType not in ['array', 'pair', 'tuple', 'vector', 'set', 'unordered_set', 'map', 'unordered_map', 'optional', 'variant']:
            return ''

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

        src = ''
        ofProps = typeDict.get('of')
        if ofProps:
            for prop in utilities.listify(ofProps):
                src += recurse(phase, memo, utilities.dictify(prop, 'type'))

        src += f'''
        
{it}std::ostream & operator <<(std::ostream & out, {memberDeclType} const & obj)'''
        if phase == 'classDecl':
            src += f';'
        elif phase == 'classDef':
            src += f'''
{it}{{{self.gen_containers._genCsBody(self, typeDict)}
{it}{it}return out;
{it}}}
'''
        return src
    
    src = recurse('classDecl', memo, m.properties)
    self._appendToSection(f'{t.name}|containerSerializerDecls', src)

    src = recurse('classDef', memo, m.properties)
    self._appendToSection(f'{t.name}|containerSerializerDefs', src)


def _genCsBody(self, typeDict):
    it = self.indent()

    src = ''

    baseType = typeDict['type']
    if baseType == 'array':
        src += f"""
{it}{it}out << '[';"""
        for i in range(0, int(typeDict['of'][1]['type'])):
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


def genIsLessStructs(self, t):
    def visit(properties):
        name = properties['fullName']

        for ofo in properties.get('of', []):
            visit(ofo)

        lessCode = properties.get('isLess')
        if lessCode:
            self.gen_containers._genIsLessStruct(self, t, name, properties)


    for memberName, m in t.members.items():
        visit(m.properties)


def _genIsLessStruct(self, t, name, properties):
    it = self.indent()
    lessCode = properties.get('isLess')
    subtypeDecl = ''
    stype = properties.get('type')
    if stype == 'set' or stype == 'map':
        subtypeDecl = self.makeNativeSubtype(properties['of'][0])

    #subtypeDecl = self.makeNativeSubtype(properties)
    print (f'@@@@@@@ {name}: {subtypeDecl}: {lessCode}')
    src = f'''

{it}struct IsLess_{name}
{it}{{
{it}{it}bool operator()({self.const(subtypeDecl)} & lhs, {self.const(subtypeDecl)} & rhs) const
{it}{it}{{
{it}{it}{it}{lessCode}
{it}{it}}}
{it}}};'''
    self._appendToSection(f'{t.name}|isLessCode', src)

