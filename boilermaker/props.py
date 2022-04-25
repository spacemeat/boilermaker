from enum import Enum, auto
from pathlib import Path
import re
from .ansi import Ansi as ansi

re_comment = re.compile(r'^(#\s*)')
re_if = re.compile(r'^(\s*if\s*)[^A-Za-z0-9_]?')
re_elif = re.compile(r'^(\s*elif\s*)[^A-Za-z0-9_]?')
re_else = re.compile(r'^(\s*else\s*)[^A-Za-z0-9_]?')
re_endif = re.compile(r'^(\s*endif\s*)[^A-Za-z0-9_]?')
re_join = re.compile(r'^(\s*join\s*)[^A-Za-z0-9_]?')
re_delim = re.compile(r'^(\s*delim\s*)[^A-Za-z0-9_]?')
re_endjoin = re.compile(r'^(\s*endjoin\s*)[^A-Za-z0-9_]?')
re_out = re.compile(r'^(\s*out\s*)[^A-Za-z0-9_]?')
re_in = re.compile(r'^(\s*in\s*)[^A-Za-z0-9_]?')
re_endout = re.compile(r'^(\s*endout\s*)[^A-Za-z0-9_]?')
re_set = re.compile(r'^(\s*set\s*)[^A-Za-z0-9_]?')
re_endset = re.compile(r'^(\s*endset\s*)[^A-Za-z0-9_]?')
re_fmt = re.compile(r'^(\s*fmt\s*)[^A-Za-z0-9_]?')
re_endfmt = re.compile(r'^(\s*endfmt\s*)[^A-Za-z0-9_]?')

re_joinexpr = re.compile(r'^(for\s+)([A-Za-z_][A-Za-z0-9_]*)(\s+in\s+)')
re_setexpr = re.compile(r'^([A-Za-z_][A-Za-z0-9_]*)(\s*as\s+)')
re_fmtexpr = re.compile(r'(right|left|center\s*)')


class ClauseKind(Enum):
    TEXT = auto(),
    QUOTE = auto(),
    COMMENT = auto(),
    QUERY = auto(),
    EXPRESSION = auto(),
    IF = auto(),
    THEN = auto(),
    IFCONDITIONAL = auto(),
    ELIFCONDITIONAL = auto(),
    ELIF = auto(),
    ELSE = auto(),
    ENDIF = auto(),
    JOIN = auto(),
    JOINCOMPREHENSION = auto(),
    DELIM = auto(),
    ENDJOIN = auto(),
    PATH = auto(),
    OUT = auto(),
    ENDOUT = auto(),
    IN = auto(),
    SET = auto(),
    SETASSIGNMENT = auto(),
    ENDSET = auto(),
    FMT = auto(),
    FMTCODE = auto(),
    ENDFMT = auto(),
    EATSPACE = auto(),
    DEBUG = auto()

class Clause:
    def __init__(self):
        self.parent = None
        #self.siblingIdx = 0
        self.terms = []     # a term is either a string or another Clause
        self.kind = ClauseKind.TEXT
        self.line = 0
        self.col = 0

    def appendClause(self):
        nc = Clause()
        #nc.siblingIdx = len(self.terms)
        self.terms.append(nc)
        nc.parent = self
        return nc

    def append(self, string):
        assert(type(string) is str)
        if len(self.terms) > 0 and type(self.terms[-1]) is str:
            self.terms[-1] += string
        else:
            self.terms.append(string)

    def insertClause(self):
        si = self.getSiblingIdx()
        nc = Clause()
        nc.parent = self.parent
        self.parent.terms[si] = nc
        self.parent = nc
        nc.terms.append(self)
        return nc

    def getParent(self):
        return self.parent

    def getSiblingIdx(self):
        return self.parent.terms.index(self)

    def mergeToParent(self):
        si = self.getSiblingIdx()
        newTerms = [* self.parent.terms[:si], * self.terms[:], * self.parent.terms[si + 1:]]
        self.parent.terms = newTerms
        return self.parent

    def toStr(self, indent = 0):
        s = ''
        ind0 = '  ' * indent
        ind1 = '  ' * (indent + 1)
        if len(self.terms) > 0:
            s += f'{ind0}<{self.kind}>:\n{ind0}{{\n'
            for t in self.terms:
                if type(t) == str:
                    s += f'{ind1}"{t}"\n'
                elif type(t) == Clause:
                    s += f'{t.toStr(indent + 1)}'
                else:
                    s += f'{ind1}<{t}:{type(t)}>\n'
            s += f'{ind0}}}\n'
        else:
            s += f'{ind0}<{self.kind}>: {{ }}\n'
        return s

    def __str__(self):
        return self.toStr(0)

    def __repr__(self):
        return self.toStr(0)


class PropertyBag:
    def __init__(self, initialProps = {}):
        self.props = initialProps
        self.parents = []  # other PropertyBags


    def __str__(self):
        def toStr(self, depth):
            s = ' ' * depth + f'{ansi.dk_blue_fg}name{ansi.all_off}: {ansi.lt_blue_fg}{self.props.get("name", "")}{ansi.all_off}\n'
            for [k, v] in self.props.items():
                if k == 'types' or k == 'enums' or k == 'bomaTypes' or k == 'bomaEnums' or k == 'anchors' or k == 'props' or k.startswith('--'):
                    s += ' ' * depth + f'{ansi.dk_blue_fg}{k}{ansi.all_off}: {ansi.lt_blue_fg}...{ansi.all_off}\n'
                elif k == 'name':
                    continue
                else:
                    s += ' ' * depth + f'{ansi.dk_blue_fg}{k}{ansi.all_off}: {ansi.lt_blue_fg}{v}{ansi.all_off}\n'
            for inh in reversed(self.parents):
                s += toStr(inh, depth + 1)
            return s
        return toStr(self, 0)


    def __repr__(self):
        def toRepr(self, depth):
            s = ' ' * depth + f'name: {self.props.get("name", "")}\n'
            for [k, v] in self.props.items():
                if k == 'types' or k == 'enums' or k == 'bomaTypes' or k == 'bomaEnums' or k == 'anchors' or k == 'props' or k.startswith('--'):
                    s += ' ' * depth + f'{k}: ...\n'
                elif k == 'name':
                    continue
                else:
                    s += ' ' * depth + f'{k}: {v}\n'
            for inh in reversed(self.parents):
                s += toRepr(inh, depth + 1)
            return s
        return toRepr(self, 0)


    def setProp(self, key, value):
        self.props[key] = value


    def setDict(self, props):
        for k, v in props.items():
            self.props[k] = v


    def getProp(self, key, default = None):
        if key in self.props:
            v = self.props[key]
            if type(v) is str:
                if v.lower() == 'true': v = True
                elif v.lower() == 'false': v = False
            return v
        for inh in reversed(self.parents):
            v = inh.getProp(key)
            if v != None:
                return v
        return default


    def getAll(self, key):
        vs = []
        if key in self.props:
            v = self.props[key]
            if type(v) is str:
                if v == 'true': v = True
                elif v == 'false': v = False
            vs.append(v)
        for inh in reversed(self.parents):
            v = inh.getAll(key)
            if len(v):
                vs.extend(v)
        return vs


    def inherit(self, ancestorBag):
        self.parents.append(ancestorBag)


    def push(self, newProps):
        pb = PropertyBag(self.props)
        pb.parents = self.parents
        self.props = newProps
        self.parents = [pb]


    def pop(self):
        if len(self.parents) != 1:
            raise RuntimeError(f'trying to pop with {len(self.parents)} parents')
        self.props = self.parents[0].props
        self.parents = self.parents[0].parents


    def ensureList(self, key):
        if key in self.props:
            if type(self.props[key]) is not list:
                self.props[key] = list(self.props[key])
        for inh in self.parents:
            inh.ensureList(key)


class Props:
    def __init__(self, initialProps = {}):
        if type(initialProps) is PropertyBag:
            self.props = initialProps
        elif type(initialProps) is dict:
            self.props = PropertyBag(initialProps)
        else:
            raise RuntimeError(f'Props() must take a PropertyBag or dict')

    def __str__(self):
        return str(self.props)

    def __repr__(self):
        return repr(self.props)

    def setProp(self, key, value):
        self.props.setProp(key, value)

    def setDict(self, props):
        self.props.setDict(props)

    def getProp(self, key, default = None):
        return self.props.getProp(key, default)

    def getAll(self, key):
        return self.props.getAll(key)

    def push(self, newProps = {}):
        self.props.push(newProps)

    def pop(self):
        self.props.pop()

    def inherit(self, ancestorBag):
        self.props.inherit(ancestorBag)

    def ensureList(self, key):
        self.props.ensureList(key)


class Scribe:
    def __init__(self, props, execGlobals = {}):
        self.props = props
        self.execGlobals = execGlobals
        self.previousPaths = set()
        self.pathStack = []
        self.debug = False


    def parseText(self, val):
        try:
            accum = self._parseText(val)
            # find all \a, and eat ws until non-ws or \v
            eat = False
            final = ''
            for i, ch in enumerate(accum):
                if eat:
                    #breakpoint()
                    if ch not in [' ', '\r', '\n', '\t', '\a']:
                        eat = False
                        if ch != '\v':
                            final += ch
                elif ch == '\a':
                    eat = True
                elif ch == '\v':    # a quoted thing that doesn't get et
                    pass
                else:
                    final += ch
            return final
        except BaseException as e:
            print(f'{self.props.getProp("inFile")}: {e}')
            raise e


    X = parseText


    def parseStructure(self, structure):
        def rec(elem):
            if type(elem) is list:
                return [rec(elemelem) for elemelem in elem]
            elif type(elem) is dict:
                return {k: rec(v) for k, v in elem.items()}
            elif type(elem) is str:
                return self.parseText(elem)
            else:
                return elem
        return rec(structure)


    def _parseText(self, val):
        try:
            clause = self._parseTagStructure(val)
            return self._parseClause(clause)

        except BaseException as e:
            print(f'{self.props.getProp("inFile")}: {e}')
            raise e

    def getXProp(self, key, default = None):
        def rec(v):
            if type(v) is str:
                return self.parseText(v)
            elif type(v) is list:
                return [rec(vv) for vv in v]
            elif type(v) is dict:
                return {k: rec(vv) for k, vv in v.items()}
            else:
                return v

        v = rec(self.props.getProp(key, default))
        return v


    def getXPropAll(self, key):
        def rec(v):
            if type(v) is str:
                return self.parseText(v)
            elif type(v) is list:
                return [rec(vv) for vv in v]
            elif type(v) is dict:
                return {k: rec(vv) for k, vv in v.items()}
            else:
                return v

        vs = self.props.getAll(key)
        vs = [rec(v) for v in vs]
        return vs


    def _openFileForWriting(self, path):
        openmode = 'w'
        if path in self.previousPaths:
            openmode = 'a'

        for s in reversed(self.pathStack):
            if s[0] == path:
                return s[1]
        f = open(path, openmode)
        self.pathStack.append((path, f))
        self.previousPaths.add(path)
        return f

    def _closeFileForWriting(self, path):
        if self.pathStack[-1][0] != path:
            raise RuntimeError(f'Open/close mismatch on outfile {path}')
        self.pathStack[-1][1].close()
        del self.pathStack[-1]

    def _eval(self, expr):
        expr = self.parseText(expr)
        globlocs = {**self.execGlobals, 'props': self.props, 'scribe': self, 'true': True, 'false': False}
        if self.debug:
            print (f'{ansi.dk_red_fg}Eval expression: {ansi.lt_red_fg}{expr}{ansi.all_off}')
        res = eval(expr, globlocs)
        if self.debug:
            print (f'{ansi.dk_red_fg}     expression returned: {ansi.lt_red_fg}{res}{ansi.dk_red_fg}: ({ansi.lt_red_fg}{type(res)}{ansi.dk_red_fg}){ansi.all_off}')
        return res

    def _exec(self, stmnts):
        stmnts = self.parseText(stmnts)
        res = ''
        locs = {'props': self.props, 'res': '', 'scribe': self, 'true': True, 'false': False}
        globlocs = {**self.execGlobals, **locs}
        if self.debug:
            print (f'{ansi.dk_red_fg}Exec statements:\n{ansi.lt_red_fg}{stmnts}{ansi.all_off}')
        try:
            exec(stmnts, globlocs)
        except BaseException as e:
            if not self.debug:
                print (f'{ansi.dk_red_fg}Exec statements:\n{ansi.lt_red_fg}{stmnts}{ansi.all_off}')
            print (f'{ansi.dk_red_fg}     exception raised: {ansi.lt_red_fg}{e}{ansi.dk_red_fg}{ansi.all_off}')
            raise e
        if self.debug:
            print (f'{ansi.dk_red_fg}     statements returned: {ansi.lt_red_fg}{locs["res"]}{ansi.dk_red_fg}: ({ansi.lt_red_fg}{type(locs["res"])}{ansi.dk_red_fg}){ansi.all_off}')
        return globlocs['res']

    def _parseTagStructure(self, val):
        idx = 0
        line = 1
        col = 1
        end = len(val)
        inTagCounter = 0
        quoteChar = ''
        rootClause = Clause()
        currentClause = rootClause

        if self.debug:
            print (f'{ansi.lt_yellow_fg}Parsing {ansi.dk_yellow_fg}{val}{ansi.all_off}')

        def dbg(msg):
            if self.debug:
                print (f'{ansi.lt_magenta_fg}({idx}{ansi.dk_magenta_fg}/{len(val)}) {line}, {col}: {ansi.dk_blue_fg}"{ansi.lt_blue_fg}{msg}{ansi.dk_blue_fg}"{ansi.all_off} {ansi.dk_yellow_fg}Tag counter: {ansi.dk_yellow_fg}{inTagCounter}{ansi.all_off}')

        def incIdx():
            nonlocal idx, line, col, val
            idx += 1
            col += 1
            if idx < len(val) and val[idx] == '\n':
                line += 1
                col = 1

        currentClause.line = line
        currentClause.col = col
        while idx < end:
            if val[idx] == '$':
                currentClause.line = line
                currentClause.col = col
                incIdx()
                if val[idx] == '\'' or val[idx] == '"' or val[idx] == '`':
                    quoteChar = val[idx]
                    incIdx()
                    accum = ''
                    while idx < end and val[idx] != quoteChar:
                        accum += val[idx]
                        incIdx()
                    incIdx()
                    dbg(f'quote-tag: {accum}')
                    quotedClause = currentClause.appendClause()
                    quotedClause.kind = ClauseKind.QUOTE
                    quotedClause.append(accum)

                elif val[idx] == '<':
                    inTagCounter += 1
                    incIdx()
                    dbg(f'start tag')
                    currentClause = currentClause.appendClause()
                    currentClause.kind = ClauseKind.EXPRESSION

                elif val[idx] == '$':   #  $$ is a way to escape $ so as not to start a tag.
                    incIdx()
                    quotedClause = currentClause.appendClause()
                    quotedClause.kind = ClauseKind.QUOTE
                    quotedClause.append('$')
                    dbg(f'$$ tag')

                elif val[idx] == '>':   #  $> is a way to escape > so as not to close a tag.
                    incIdx()
                    quotedClause = currentClause.appendClause()
                    quotedClause.kind = ClauseKind.QUOTE
                    quotedClause.append('>')
                    dbg(f'$> tag')

                elif val[idx] == '+':   #  $+ marks the next non-whitespace start
                    incIdx()
                    eatWsClause = currentClause.appendClause()
                    eatWsClause.kind = ClauseKind.EATSPACE
                    dbg(f'$+ tag')

                elif val[idx] == '!':   #  $! traps in a running debugger
                    incIdx()
                    eatWsClause = currentClause.appendClause()
                    eatWsClause.kind = ClauseKind.DEBUG
                    dbg(f'$! tag')

                elif val[idx].isalpha() or val[idx] == '_':
                    # eval props.get which must resolve to a string (because we are not inTag)
                    accum = ''
                    while idx < end and (val[idx].isalpha() or val[idx].isdigit() or val[idx] == '_'):
                        accum += val[idx]
                        incIdx()
                    #accum = f' props.get("{accum}")'
                    exprClause = currentClause.appendClause()
                    exprClause.kind = ClauseKind.QUERY
                    exprClause.append(accum)
                    dbg(f'query tag: {accum}')

                else:
                    raise RuntimeError(f'({line}, {col}): Naked query spec ($). Use $$ or $"$" to spec a "$" character.')

            elif val[idx] == '>':
                incIdx()

                if inTagCounter == 0:
                    accum = '>'
                    dbg(f'verbatim: {accum}')
                    currentClause.append(accum)

                else:
                    inTagCounter -= 1

                    # empty tag
                    if len(currentClause.terms) == 0:
                        dbg(f'empty tag')
                        # just a way of pruning this clause really
                        currentClause = currentClause.mergeToParent()

                    # First token isn't text - might be an expression or query.
                    # Either way, skip it for now. We're just examining structure
                    # and looking for keywords or text patterns.
                    elif type(currentClause.terms[0]) is not str:
                        currentClause = currentClause.parent
                        dbg(f'tag')

                    elif m := re.match(re_comment, currentClause.terms[0]):
                        currentClause.kind = ClauseKind.COMMENT
                        currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        currentClause = currentClause.parent
                        dbg(f'comment tag')

                    elif m := re.match(re_if, currentClause.terms[0]):
                        ifClause = currentClause.insertClause()
                        ifClause.kind = ClauseKind.IF
                        condClause = ifClause.terms[0]
                        condClause.terms[0] = condClause.terms[0][len(m.group(1)):]
                        condClause.kind = ClauseKind.IFCONDITIONAL
                        currentClause = ifClause
                        currentClause = currentClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'if tag')

                    elif m := re.match(re_elif, currentClause.terms[0]):
                        thenClause = currentClause.parent
                        ifClause = thenClause.parent    # pop out of THEN
                        ifCondClause = ifClause.appendClause()
                        ifCondClause.kind = ClauseKind.ELIFCONDITIONAL
                        ifCondClause.terms = currentClause.terms
                        currentClause.terms = []
                        currentClause.mergeToParent()
                        ifCondClause.terms[0] = ifCondClause.terms[0][len(m.group(1)):]
                        currentClause = ifClause
                        currentClause = currentClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'elif tag')

                    elif m := re.match(re_else, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent    # pop out of ELSE
                        currentClause = currentClause.appendClause()
                        currentClause.kind = ClauseKind.ELSE
                        currentClause.append("True")
                        currentClause = currentClause.parent    # pop out of ELSE
                        currentClause = currentClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'else tag')

                    elif m := re.match(re_endif, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent
                        if currentClause.kind != ClauseKind.IF:
                            raise RuntimeError(f'{self.props.getProp("inFile")} ({line}, {col}): $<endif> does not match a preceding $<if>')
                        currentClause = currentClause.parent
                        dbg(f'endif -> {accum}')

                    elif m := re.match(re_join, currentClause.terms[0]):
                        joinClause = currentClause.insertClause()
                        joinClause.kind = ClauseKind.JOIN
                        condClause = joinClause.terms[0]
                        condClause.terms[0] = condClause.terms[0][len(m.group(1)):]
                        condClause.kind = ClauseKind.JOINCOMPREHENSION
                        currentClause = joinClause
                        currentClause = currentClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'join tag')

                    elif m := re.match(re_delim, currentClause.terms[0]):
                        thenClause = currentClause.parent
                        joinClause = thenClause.parent    # pop out of ELSE
                        delimClause = joinClause.appendClause()
                        delimClause.kind = ClauseKind.DELIM
                        delimClause.terms = currentClause.terms
                        delimClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        currentClause.terms = []
                        currentClause.mergeToParent()
                        currentClause = joinClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'delim tag')

                    elif m := re.match(re_endjoin, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent
                        if currentClause.kind != ClauseKind.JOIN:
                            raise RuntimeError(f'({line}, {col}): $<endjoin> does not match a preceding $<join>')
                        currentClause = currentClause.parent
                        dbg(f'endjoin tag')

                    elif m := re.match(re_in, currentClause.terms[0]):
                        currentClause.kind = ClauseKind.PATH
                        currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        currentClause = currentClause.insertClause()
                        currentClause.kind = ClauseKind.IN
                        currentClause = currentClause.parent
                        dbg(f'in tag')

                    elif m := re.match(re_out, currentClause.terms[0]):
                        currentClause.kind = ClauseKind.PATH
                        currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        outClause = currentClause.insertClause()
                        outClause.kind = ClauseKind.OUT
                        currentClause = outClause.appendClause()
                        dbg(f'out tag')

                    elif m := re.match(re_endout, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent
                        if currentClause.kind != ClauseKind.OUT:
                            raise RuntimeError(f'({line}, {col}): $<endout> does not match a preceding $<out>')
                        currentClause = currentClause.parent
                        dbg(f'endout tag')

                    elif m := re.match(re_set, currentClause.terms[0]):
                        currentClause.kind = ClauseKind.SETASSIGNMENT
                        currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        setClause = currentClause.insertClause()
                        setClause.kind = ClauseKind.SET
                        currentClause = setClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'set tag')

                    elif m := re.match(re_endset, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent
                        if currentClause.kind != ClauseKind.SET:
                            raise RuntimeError(f'({line}, {col}): $<endset> does not match a preceding $<set>')
                        currentClause = currentClause.parent
                        dbg(f'endset tag')

                    elif m := re.match(re_fmt, currentClause.terms[0]):
                        currentClause.kind = ClauseKind.FMTCODE
                        currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                        fmtClause = currentClause.insertClause()
                        fmtClause.kind = ClauseKind.FMT
                        currentClause = fmtClause.appendClause()
                        currentClause.kind = ClauseKind.THEN
                        dbg(f'fmt tag')

                    elif m := re.match(re_endfmt, currentClause.terms[0]):
                        currentClause.terms = []
                        currentClause = currentClause.mergeToParent()
                        currentClause = currentClause.parent
                        if currentClause.kind != ClauseKind.FMT:
                            raise RuntimeError(f'({line}, {col}): $<endfmt> does not match a preceding $<fmt>')
                        currentClause = currentClause.parent
                        dbg(f'endfmt tag')

                    else:
                        currentClause.kind = ClauseKind.EXPRESSION
                        currentClause = currentClause.parent
                        dbg(f'expr tag')

            else:   # all other chars before $ or >
                accum = ''
                while idx < end:
                    if (val[idx] == '$' or
                        (inTagCounter > 0 and val[idx] == '>')):
                        break

                    accum += val[idx]
                    incIdx()
                dbg(f'verbatim: {accum}')
                currentClause.append(accum)

        return rootClause


    def _parseClause(self, clause, depth = 0):
        acc = ''
        eatSpace = False
        def accum(string):
            nonlocal acc
            acc += string
            if self.debug:
                print (f'{ansi.dk_green_fg}Accum: {"  " * depth}{ansi.lt_green_fg}{string}{ansi.all_off}')
        # def accum(string, quoted = False):
        #     nonlocal eatSpace, acc
        #     if quoted:
        #         if string.startswith(' '):
        #             breakpoint()
        #         eatSpace = False        # here a 0-length quote ($'') WILL disable eatSpace
        #         acc += '\v'
        #     if eatSpace:
        #         string = string.lstrip(' \n\t')
        #         if len(string) > 0:     # here a 0-length accum will NOT disable eatSpace
        #             eatSpace = False
        #     acc += string
        #     if self.debug:
        #         print (f'{ansi.dk_green_fg}Accum: {"  " * depth}{ansi.lt_green_fg}{string}{ansi.all_off}')

        def dbg(msg):
            if self.debug:
                if type(clause) is Clause:
                    print (f'Clause depth: {depth} at {clause.line}, {clause.col}: {clause.kind}')
                elif type(clause) is str:
                    print (f'Clause depth: {depth}: {ansi.lt_black_fg}{clause}{ansi.all_off}')

        dbg(f' - foo')

        if type(clause) is str:
            accum(clause)

        elif clause.kind == ClauseKind.DEBUG:
            breakpoint()
            print(clause)

        elif clause.kind == ClauseKind.COMMENT:
            pass

        elif (clause.kind == ClauseKind.TEXT or
              clause.kind == ClauseKind.THEN):
            for tidx, t in enumerate(clause.terms):
                if type(t) is Clause and t.kind == ClauseKind.EATSPACE:
                    accum('\a') #eatSpace = True
                else:
                    accum(self._parseClause(t, depth + 1))

        elif clause.kind == ClauseKind.QUOTE:
            accum('\v' + clause.terms[0])

        elif clause.kind == ClauseKind.QUERY:
            expr = f'scribe.getXProp("{clause.terms[0]}")'
            if (clause.parent.kind == ClauseKind.EXPRESSION or
                clause.parent.kind == ClauseKind.IFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELIFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELSE or
                clause.parent.kind == ClauseKind.JOINCOMPREHENSION or
                clause.parent.kind == ClauseKind.PATH or
                clause.parent.kind == ClauseKind.SETASSIGNMENT or
                clause.parent.kind == ClauseKind.FMTCODE):
                newvar = f'boma_{clause.terms[0]}'
                fullexpr = f'{newvar} = {expr}\n'
                accum(fullexpr)
            else:
                res = self._eval(expr)
                if res is not None:
                    if type(res) is str:
                        res = self._parseText(res)
                    accum(str(res))
                else:
                    accum(f'$<!{clause.terms[0]}>')

        elif (clause.kind == ClauseKind.EXPRESSION or
              clause.kind == ClauseKind.IFCONDITIONAL or
              clause.kind == ClauseKind.ELIFCONDITIONAL or
              clause.kind == ClauseKind.ELSE or
              clause.kind == ClauseKind.JOINCOMPREHENSION or
              clause.kind == ClauseKind.PATH or
              clause.kind == ClauseKind.SETASSIGNMENT or
              clause.kind == ClauseKind.FMTCODE):

            setters = ''
            expr = ''
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    expr += self._parseClause(t, depth + 1)
                elif t.kind == ClauseKind.QUERY:
                    setters += self._parseClause(t, depth + 1)
                    expr += f'boma_{t.terms[0]}'
                else:
                    text = self._parseClause(t, depth + 1)
                    expr += f'{text}'

            res = ''
            if expr.strip() != '':
                expr = f'{setters}res = {expr}'
                res = expr
                if clause.kind == ClauseKind.EXPRESSION:
                    res = str(self._exec(expr))
                    res = self._parseText(res)
                accum(res)

        elif clause.kind == ClauseKind.IF:
            condClauses = []
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    continue
                elif (t.kind == ClauseKind.IFCONDITIONAL or
                      t.kind == ClauseKind.ELIFCONDITIONAL or
                      t.kind == ClauseKind.ELSE):
                    condClauses.append(tidx)
                elif (t.kind == ClauseKind.THEN or
                      t.kind == ClauseKind.ENDIF):
                    pass
                else:
                    raise RuntimeError(f'Found a clause of type {t.kind} in an $<if> tag.')

            for tidx in condClauses:
                t = self._parseClause(clause.terms[tidx], depth + 1)
                #   make expr
                expr = False
                if type(t) is str:
                    expr = t
                elif len(t.terms) > 0:
                    expr = "".join(t.terms)
                #   exec
                res = self._exec(expr)
                #   if eval is True:
                if res is None:
                    res = False
                #assert(type(res) is bool)
                if res != False:
                #       gather each text clause after idx
                    i = tidx + 1
                    assert(clause.terms[i].kind == ClauseKind.THEN)
                    accum(self._parseClause(clause.terms[i], depth + 1))
                    break

        elif clause.kind == ClauseKind.JOIN:
            compIdx = -1
            delimIdx = -1
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    continue
                elif t.kind == ClauseKind.JOINCOMPREHENSION:
                    compIdx = tidx
                elif t.kind == ClauseKind.DELIM:
                    delimIdx = tidx
                elif (t.kind == ClauseKind.THEN or
                    t.kind == ClauseKind.ENDJOIN):
                    pass
                else:
                    raise RuntimeError(f'Found a clause of type {t.kind} in a $<join> tag.')

            if compIdx < 0:
                raise RuntimeError(f'No comprehension found for join tag.')

            # parse 'for x in y' to set up the loop on x, y
            # for must be 'for'
            # x must be a symbol-legal string
            # in must be 'in'
            # y is the rest is an expression for 'for foo in y'

            forString = clause.terms[compIdx].terms[0]
            if m := re.match(re_joinexpr, forString):
                varname = m.group(2)

                tempClause = Clause()
                tempClause.kind = ClauseKind.JOINCOMPREHENSION
                tempClause.append(forString[len(m.group(0)):])
                for t in clause.terms[compIdx].terms[1:]:
                    tempClause.terms.append(t)
                expr = self._parseClause(tempClause, depth + 1)
                vals = self._exec(expr)

                if vals is None:
                    vals = []

                if type(vals) is dict:
                    vals = [v for k, v in vals.items()]

                for vidx, val in enumerate(vals):
                    self.props.push({varname: val})
                    oldProps = self.props
                    try:
                        # if our value has a 'props' member, set the scribing props
                        # to this value. Enables $<join for x in y> to set props for
                        # objects of type y.
                        props = self.props
                        if type(val) is dict and 'props' in val and type(val['props']) is Props:
                            props = val['props']
                        elif getattr(val, 'props', False) and type(val.props) is Props:
                            props = val.props
                        self.props = props
                        th = self._parseClause(clause.terms[compIdx + 1], depth + 1)
                        d = ''
                        if delimIdx >= 0:
                            d = self._parseClause(clause.terms[delimIdx + 1], depth + 1)
                    finally:
                        self.props = oldProps
                        self.props.pop()

                    accum(th)
                    if len(d) > 0 and vidx < len(vals) - 1:
                        accum(d)

            else:
                raise RuntimeError(f'malformed join tag')

        elif clause.kind == ClauseKind.IN:
            expr = self._parseClause(clause.terms[0], depth + 1)
            path = self._exec(expr)
            if type(path) is str:
                path = self._parseText(path)
            try:
                with open(path, 'r') as file:
                    self.props.push({'inFile': Path(path).name, 'inPath': str(Path(path)), 'inDir': str(Path(path).parent)})
                    string = file.read()
                    try:
                        string = self._parseText(string)
                    finally:
                        self.props.pop()
                    accum(string)
            except EnvironmentError:
                accum(f'!<Could not open file {path} for reading>')

        elif clause.kind == ClauseKind.OUT:
            expr = self._parseClause(clause.terms[0], depth + 1)
            path = self._exec(expr)
            if type(path) is str:
                path = self._parseText(path)
            f = None
            try:
                Path(path).parent.mkdir(exist_ok=True, parents=True)
                f = self._openFileForWriting(path)
                try:
                    self.props.push({'outfile': path})
                    string = self._parseClause(clause.terms[1], depth + 1)
                finally:
                    self.props.pop()
                try:
                    f.write(self.parseText(string))
                except EnvironmentError:
                    accum(f'!<Could not write to file {path}>')
                finally:
                    f.close()
                    self._closeFileForWriting(path)
            except EnvironmentError:
                accum(f'!<Could not open file {path} for writing>')

        elif clause.kind == ClauseKind.SET:
            keyIdx = 0
            #breakpoint()

            setString = clause.terms[keyIdx].terms[0]
            varname = ''
            matched = 0
            if m := re.match(re_setexpr, setString):
                varname = m.group(1)
                matched = len(m.group(0))

            tempClause = Clause()
            tempClause.kind = ClauseKind.SETASSIGNMENT
            tempClause.append(setString[matched:])
            for t in clause.terms[keyIdx].terms[1:]:
                tempClause.terms.append(t)
            expr = self._parseClause(tempClause, depth + 1)

            obj = self._exec(expr)
            if type(obj) is str:
                obj = self._parseText(obj)
                self.props.push({varname: obj})
            elif matched == 0 and type(obj) is dict:
                for k, v in obj.items():
                    varname = k
                    pv = self._parseText(v)
                    self.props.push({varname: pv})
            else:
                self.props.push({varname: obj})
            try:
                th = self._parseClause(clause.terms[keyIdx + 1], depth + 1)
            finally:
                self.props.pop()
            accum(th)

        # (left|center|right) widthExpression
        elif clause.kind == ClauseKind.FMT:
            fmtcodeIdx = 0

            # parse 'justification y' to set up the loop on x, y
            # justification must be 'left' or 'right' or 'center'
            # y is the rest is an expression for the format width
            # and must resolve to an integer.
            fmtcodeClause = clause.terms[fmtcodeIdx]
            exprstart = 0
            justification = 'left'
            fmtString = fmtcodeClause.terms[0]
            if m := re.match(re_fmtexpr, fmtString):
                justification = m.group(1)
                exprstart = len(m.group(0))

            tempClause = Clause()
            tempClause.kind = ClauseKind.FMTCODE
            tempClause.append(fmtString[exprstart:])
            for t in clause.terms[fmtcodeIdx].terms[1:]:
                tempClause.terms.append(t)

            expr = self._parseClause(tempClause, depth + 1)

            width = self._exec(expr)
            if type(width) is not int:
                raise RuntimeError(f'fmt width expression must resolve to int type')

            if justification == 'left': j = '<'
            elif justification == 'right': j = '>'
            elif justification == 'center': j = '^'

            fmtcode = f'{{0: {j}{width}}}'
            th = self._parseClause(clause.terms[fmtcodeIdx + 1], depth + 1)
            th = fmtcode.format(th)
            accum(th)

        # replace myself with the joined text
        return acc


if __name__ == "__main__":

    passStr = f'{ansi.lt_green_fg}pass{ansi.all_off}'
    failStr = f'{ansi.lt_red_fg}fail{ansi.all_off}'

    p = Props({
            'outputForm': 'compiled',
            'defaultConstructible': True,
            'selector': 1,
            'deserializeFrom': ['humon', 'binary', 'dna'],
            'serializeTo': ['humon', 'binary', 'dna'],
            'a': 'i',
            'b': 'f',
            'cats': ['Leo', 'Lilly', "Weeby", "Butters"],
            'dollaz': [1.23, -2.34, 3.45],
            'dataColumns': 8,
            'constStyle': 'east',
            'const': r"lambda t: f'{t} const' if '$constStyle' == 'east' else f'const {t}'",
            'type': 'hu::Node'
    })

    def test(src, exp, debug = False):
        p.debug = debug
        print (f'Test src: {ansi.dk_cyan_fg}{src}{ansi.all_off}')
        try:
            s = Scribe(p)
            res = s._parseText(src)
            if res == exp:
                print (f'  {passStr}')
            else:
                print (f'  expected:\n{ansi.lt_blue_fg}{exp}{ansi.all_off}\n  {failStr}\n  result:\n{res}')
        except BaseException as e:
            print (f'  expected:\n{ansi.lt_blue_fg}{exp}{ansi.all_off}\n  {failStr}\n  result:\n  Exception thrown: {e}')
            raise e

        p.debug = False

    test('One $<>two$<> three',
         'One two three')
    test('One $< >two$< > three',
         'One two three')
    test('Output form: $outputForm',
         'Output form: compiled')
    test('Deserialize from: $<$deserializeFrom [ $selector ]>',
         'Deserialize from: binary')
    test('Deserialize from: $<$deserializeFrom [$selector+1]>',
         'Deserialize from: dna')
    test('Script: $<$< len(props.getProp("deserializeFrom"))> * ($selector+1)>',
         'Script: 6')
    test('Deserialize from humon: $<if "humon" in $deserializeFrom>yes$<else>no$<endif>',
         'Deserialize from humon: yes')
    test('Deserialize from telepathy: $<if "telepathy" in $deserializeFrom>yes$<else>no$<endif>',
         'Deserialize from telepathy: no')
    test('Deserialize from preferred method: $<if "telepathy" in $deserializeFrom>telepathy$<elif "binary" in $deserializeFrom>binary$<else>humon$<endif>',
         'Deserialize from preferred method: binary')
    test('$<if $<if "binary" in $deserializeFrom>"Weeby"$<else>"Rude"$<endif> in $cats>Treats!$<else>Snacks!$<endif>',
         'Treats!')
    test('Deserialize from: [$<join for method in $deserializeFrom> $method$<delim>,\n                   $<endjoin> ]',
         '''Deserialize from: [ humon,
                    binary,
                    dna ]''')
    test('cats: $<in "test_input.scribe"> baz',
         'cats: Butters, Weeby, Lilly, Leo baz')
    test('foo $<out "test_output">test $outputForm$<endout>bar',
         'foo bar')
    test('foo $<set test_output as $outputForm>test $test_output$<endset> bar',
         'foo test compiled bar')
    test('foo $<set test_output as $outputForm>$test_output $<set test_output as "zing">$test_output$<endset> $test_output$<endset> bar',
         'foo compiled zing compiled bar')
    test('foo $<set test_output as $serializeTo>test $<$test_output[2]>$<endset> bar',
         'foo test dna bar')
    test('''Tabulated data: $<join for pay in $dollaz>$$$<fmt right $dataColumns>$pay$<endfmt>$<delim>
                $<endjoin>''',
         '''Tabulated data: $    1.23
                $   -2.34
                $    3.45''')
    test('''Tabulated data: $<join for pay in $dollaz>$$$<r"$`{0:>8.1f}`".format($pay)>$<delim>
                $<endjoin>''',
         '''Tabulated data: $     1.2
                $    -2.3
                $     3.5''')
    test('''$+
Deserialize from: [ $+
    $< join for method in $deserializeFrom >$+
        $method$+
        $<    delim   >,
                    $+
    $< endjoin > $+
]''',
         '''Deserialize from: [ humon,
                    binary,
                    dna ]''')
    test('foo $<#if you see me you have FAILED>bar',
         'foo bar')
    test('foo $<if $selector==1>bar$<endif $<#WHAT>> baz',
         'foo bar baz')
    test('foo $<join for m in $serializeTo>-<($m)>-$<endjoin $<#WHAT>> baz',
         'foo -<(humon)>--<(binary)>--<(dna)>- baz')
    test('foo $<join for m in $serializeTo>-<($m)>-$<delim $<#WHAT>> $<endjoin $<#WHAT>> baz',
         'foo -<(humon)>- -<(binary)>- -<(dna)>- baz')
    test('$<set const as $<$const>>$<$const($type + "&")> foo;$<endset>', \
         'hu::Node& const foo;')
