#from . import utilities

#props.set('copyable', False)
#props.set('movable', True)
#props.push()
#props.set('movable', False)
#...
#props.pop()
# # now props.movable == True again

from enum import Enum, auto
import re

#from . import ansi
class ansi:
    all_off = '\033[0m'

    dk_black_fg = '\033[30m'
    dk_red_fg = '\033[31m'
    dk_green_fg = '\033[32m'
    dk_yellow_fg = '\033[33m'
    dk_blue_fg = '\033[34m'
    dk_magenta_fg = '\033[35m'
    dk_cyan_fg = '\033[36m'
    dk_white_fg = '\033[37m'

    lt_black_fg = '\033[90m'
    lt_red_fg = '\033[91m'
    lt_green_fg = '\033[92m'
    lt_yellow_fg = '\033[93m'
    lt_blue_fg = '\033[94m'
    lt_magenta_fg = '\033[95m'
    lt_cyan_fg = '\033[96m'
    lt_white_fg = '\033[97m'


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

re_joinexpr = re.compile(f'^(for\s+)([A-Za-z_][A-Za-z0-9_]*)(\s+in\s+)')
re_setexpr = re.compile(f'^([A-Za-z_][A-Za-z0-9_]*)(\s*as\s+)')
re_fmtexpr = re.compile(f'(right|left|center\s*)')

class Props:
    def __init__(self):
        self.props = [{}]

    def set(self, key, value):
        self.props[-1][key] = value

    def setM(self, values):
        for k, v in values.items():
            self.set(k, v)

    def get(self, key):
        for ps in reversed(self.props):
            if key in ps:
                return ps[key]
        return None

    def push(self):
        self.props.append({})

    def pop(self):
        self.props = self.props[:-1 or [{}] ]

    def __str__(self):
        s = 'props: '
        for ps in reversed(self.props):
            for k, v, in ps.items():
                s += f'{k}: {v}  '
        return s


class ClauseKind(Enum):
    TEXT = auto(),
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
    EATSPACE = auto()

class Clause:
    def __init__(self):
        self.parent = None
        #self.siblingIdx = 0
        self.terms = []     # a term is either a string or another Clause
        self.kind = ClauseKind.TEXT


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


    def __repr__(self):
        return self.toStr()


class Propmaster:
    def __init__(self):
        self.props = Props()
        self.previousPaths = set()

    def eval(self, expr):
        print (f'{ansi.dk_red_fg} Eval expression: {ansi.lt_red_fg}{expr}{ansi.all_off}')
        res = eval(expr, {}, {'props': self.props})
        print (f'{ansi.dk_red_fg}      expression returned: {ansi.lt_red_fg}{res}{ansi.dk_red_fg}: ({ansi.lt_red_fg}{type(res)}{ansi.dk_red_fg}){ansi.all_off}')
        return res

    def exec(self, stmnts):
        res = ''
        locs = { 'props': self.props, 'res': '' }
        print (f'{ansi.dk_red_fg} Exec statements:\n{ansi.lt_red_fg}{stmnts}{ansi.all_off}')
        exec(stmnts, {}, locs)
        print (f'{ansi.dk_red_fg}      statements returned: {ansi.lt_red_fg}{locs["res"]}{ansi.dk_red_fg}: ({ansi.lt_red_fg}{type(locs["res"])}{ansi.dk_red_fg}){ansi.all_off}')
        return locs['res']

    def parseText(self, val):
        clause = self.parseTagStructure(val)
        return self.parseClause(clause)


    def parseTagStructure(self, val):
        idx = 0
        end = len(val)
        inTagCounter = 0
        quoteChar = ''
        rootClause = Clause()
        currentClause = rootClause

        print (f'{ansi.lt_yellow_fg}Parsing {ansi.dk_yellow_fg}{val}{ansi.all_off}')

        def dbg(msg):
            print (f'{ansi.lt_magenta_fg}({idx}{ansi.dk_magenta_fg}/{len(val)}) {ansi.dk_blue_fg}"{ansi.lt_blue_fg}{msg}{ansi.dk_blue_fg}"{ansi.all_off} {ansi.dk_yellow_fg}Tag counter: {ansi.dk_yellow_fg}{inTagCounter}{ansi.all_off}')

        while idx < end:
            if val[idx] == '$':
                idx += 1
                if val[idx] == '\'' or val[idx] == '"' or val[idx] == '`':
                    quoteChar = val[idx]
                    idx += 1
                    accum = ''
                    #accum = f'${quoteChar}'
                    while idx < end and val[idx] != quoteChar:
                        accum += val[idx]
                        idx += 1
                    #accum += f'{quoteChar}'
                    dbg(f'quote-tag: {accum}')
                    currentClause.append(accum)

                elif val[idx] == '<':
                    inTagCounter += 1
                    idx += 1
                    dbg(f'start tag')
                    currentClause = currentClause.appendClause()
                    currentClause.kind = ClauseKind.EXPRESSION

                elif val[idx] == '$':   #  $$ is a way to escape $ so as not to start a tag.
                    idx += 1
                    dbg(f'$$ tag')
                    currentClause.append('$')

                elif val[idx] == '>':   #  $> is a way to escape > so as not to close a tag.
                    idx += 1
                    dbg(f'$> tag')
                    currentClause.append('>')

                elif val[idx] == '+':   #  $+ marks the next non-whitespace start
                    idx += 1
                    exprClause = currentClause.appendClause()
                    exprClause.kind = ClauseKind.EATSPACE
                    dbg(f'$+ tag')

                elif val[idx].isalpha() or val[idx] == '_':
                    # eval props.get which must resolve to a string (because we are not inTag)
                    accum = ''
                    while idx < end and (val[idx].isalpha() or val[idx].isdigit() or val[idx] == '_'):
                        accum += val[idx]
                        idx += 1
                    #accum = f' props.get("{accum}")'
                    exprClause = currentClause.appendClause()
                    exprClause.kind = ClauseKind.QUERY
                    exprClause.append(accum)
                    dbg(f'query tag: {accum}')

                else:
                    raise RuntimeError('Naked query spec ($). Use $$ or $"$" to spec a "$" character.')

            elif val[idx] == '>':
                idx += 1
                inTagCounter -= 1

                # resolve if/join/file/expr/end* tags
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
                        raise RuntimeError('$<endif> does not match a preceding $<if>')
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
                        raise RuntimeError('$<endjoin> does not match a preceding $<join>')
                    currentClause = currentClause.parent
                    dbg(f'endjoin tag')

                elif m := re.match(re_in, currentClause.terms[0]):
                    currentClause.kind = ClauseKind.PATH
                    currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                    currentClause = currentClause.insertClause()
                    currentClause.kind = ClauseKind.IN
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
                        raise RuntimeError('$<endout> does not match a preceding $<out>')
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
                        raise RuntimeError('$<endset> does not match a preceding $<set>')
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
                        raise RuntimeError('$<endfmt> does not match a preceding $<fmt>')
                    currentClause = currentClause.parent
                    dbg(f'endfmt tag')

                else:
                    currentClause.kind = ClauseKind.EXPRESSION
                    currentClause = currentClause.parent
                    dbg(f'expr tag')

            else:   # all other chars before $ or >
                accum = ''
                while idx < end and val[idx] != '$' and val[idx] != '>':
                    accum += val[idx]
                    idx += 1
                dbg(f'verbatim: {accum}')
                currentClause.append(accum)

        return rootClause


    def parseClause(self, clause):
        acc = ''
        eatSpace = False
        def accum(string):
            nonlocal eatSpace, acc
            if eatSpace:
                string = string.lstrip(' \n\t')
                if len(string) > 0:
                    eatSpace = False
            acc += string

        if type(clause) is str:
            accum(clause)

        elif clause.kind == ClauseKind.COMMENT:
            pass

        elif (clause.kind == ClauseKind.TEXT or
              clause.kind == ClauseKind.THEN):
            for tidx, t in enumerate(clause.terms):
                if type(t) is Clause and t.kind == ClauseKind.EATSPACE:
                    eatSpace = True
                else:
                    accum(self.parseClause(t))

        elif clause.kind == ClauseKind.QUERY:
            expr = f'props.get("{clause.terms[0]}")'
            if (clause.parent.kind == ClauseKind.EXPRESSION or
                clause.parent.kind == ClauseKind.IFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELIFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELSE or
                clause.parent.kind == ClauseKind.JOINCOMPREHENSION or
                clause.parent.kind == ClauseKind.SETASSIGNMENT or
                clause.parent.kind == ClauseKind.FMTCODE):
                newvar = f'boma_{clause.terms[0]}'
                fullexpr = f'{newvar} = {expr}\n'
                accum(fullexpr)
            else:
                res = self.eval(expr)
                if res:
                    accum(str(res))
                else:
                    accum(f'$<!{clause.terms[0]}>')

        elif (clause.kind == ClauseKind.EXPRESSION or
              clause.kind == ClauseKind.IFCONDITIONAL or
              clause.kind == ClauseKind.ELIFCONDITIONAL or
              clause.kind == ClauseKind.ELSE or
              clause.kind == ClauseKind.JOINCOMPREHENSION or
              clause.kind == ClauseKind.SETASSIGNMENT or
              clause.kind == ClauseKind.FMTCODE):

            setters = ''
            expr = ''
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    expr += self.parseClause(t)
                elif t.kind == ClauseKind.QUERY:
                    setters += self.parseClause(t)
                    expr += f'boma_{t.terms[0]}'
                else:
                    text = self.parseClause(t)
                    expr += f'{text}'

            res = ''
            if expr.strip() != '':
                if (clause.kind == ClauseKind.JOINCOMPREHENSION or
                    clause.kind == ClauseKind.SETASSIGNMENT or
                    clause.kind == ClauseKind.FMTCODE):
                    expr = f'{setters}res = {expr}'
                    res = expr
                    accum(res)
                else:
                    expr = f'{setters}res = str({expr})'
                    res = self.exec(expr)
                    accum(self.parseClause(self.parseTagStructure(res)))

        elif (clause.kind == ClauseKind.IFCONDITIONAL or
              clause.kind == ClauseKind.ELIFCONDITIONAL or
              clause.kind == ClauseKind.ELSE or
              clause.kind == ClauseKind.JOINCOMPREHENSION or
              clause.kind == ClauseKind.SETASSIGNMENT or
              clause.kind == ClauseKind.FMTCODE):
            # parseClauses on expression contents
            expr = ''
            for tidx, t in enumerate(clause.terms):
                expr += self.parseClause(t)
            accum(expr)

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
                t = self.parseClause(clause.terms[tidx])
                #   make expr
                expr = False
                if type(t) is str:
                    expr = t
                elif len(t.terms) > 0:
                    expr = f'True == ({"".join(t.terms)})'
                #   eval to bool
                res = self.eval(expr)
                #   if eval is True:
                assert(type(res) is bool)
                if type(res) is bool and res == True:
                #       gather each text clause after idx
                    i = tidx + 1
                    assert(clause.terms[i].kind == ClauseKind.THEN)
                    accum(self.parseClause(clause.terms[i]))
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
                    raise RuntimeError(f'Found a clause of type {t.kind} in an $<if> tag.')

            if compIdx < 0:
                raise RuntimeError(f'No comprehension found for join tag.')

            # parse 'for x in y' to set up the loop on x, y
            # for must be 'for'
            # x must be a symbol-legal string
            # in must be 'in'
            # y is the rest is an expression for 'for foo in (y)'

            forString = clause.terms[compIdx].terms[0]
            if m := re.match(re_joinexpr, forString):
                varname = m.group(2)

                tempClause = Clause()
                tempClause.kind = ClauseKind.JOINCOMPREHENSION
                tempClause.append(forString[len(m.group(0)):])
                for t in clause.terms[compIdx].terms[1:]:
                    tempClause.terms.append(t)
                #c = self.parseClause(clause.terms[compIdx].terms[0])
                expr = self.parseClause(tempClause)

                vals = self.exec(expr)

                for vidx, val in enumerate(vals):
                    self.props.push()
                    self.props.set(varname, val)
                    th = self.parseClause(clause.terms[compIdx + 1])
                    d = ''
                    if delimIdx >= 0:
                        d = self.parseClause(clause.terms[delimIdx + 1])

                    accum(th)
                    if len(d) > 0 and vidx < len(vals) - 1:
                        accum(d)
                    self.props.pop()

            else:
                raise RuntimeError(f'malformed join tag')

        elif clause.kind == ClauseKind.IN:
            path = self.parseClause(clause.terms[0].terms[0])
            try:
                with open(path, 'r') as file:
                    # TODO: set path to props?
                    string = file.read()
                    string = self.parseText(string)
                    accum(string)
            except EnvironmentError:
                accum(f'!<File not found: {path}>')

        elif clause.kind == ClauseKind.OUT:
            # TODO: set path to props?
            string = self.parseClause(clause.terms[1])
            path = clause.terms[0].terms[0]
            openmode = 'w'
            if path in self.previousPaths:
                openmode = 'a'
            try:
                with open(path, openmode) as f:
                    f.write(string)
                    self.previousPaths.add(path)
            except EnvironmentError:
                accum(f'!<Could not open file {path}>')

        elif clause.kind == ClauseKind.SET:
            keyIdx = 0

            # parse 'for x in y' to set up the loop on x, y
            # for must be 'for'
            # x must be a symbol-legal string
            # in must be 'in'
            # y is the rest is an expression for 'for foo in (y)'
            setString = clause.terms[keyIdx].terms[0]
            if m := re.match(re_setexpr, setString):
                varname = m.group(1)
                tempClause = Clause()
                tempClause.kind = ClauseKind.SETASSIGNMENT
                tempClause.append(setString[len(m.group(0)):])
                for t in clause.terms[keyIdx].terms[1:]:
                    tempClause.terms.append(t)

                expr = self.parseClause(tempClause)

                obj = self.exec(expr)
                if expr.startswith('lambda'):
                    breakpoint()

                self.props.push()
                self.props.set(varname, obj)
                th = self.parseClause(clause.terms[keyIdx + 1])
                accum(th)

                self.props.pop()

            else:
                raise RuntimeError(f'malformed set tag')

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

            expr = self.parseClause(tempClause)
            breakpoint()

            width = self.exec(expr)
            if type(width) is not int:
                raise RuntimeError(f'fmt width expression must resolve to int type')

            if justification == 'left': j = '<'
            elif justification == 'right': j = '>'
            elif justification == 'center': j = '^'

            fmtcode = f'{{0: {j}{width}}}'
            th = self.parseClause(clause.terms[fmtcodeIdx + 1])
            th = fmtcode.format(th)
            accum(th)

        # replace myself with the joined text
        return acc


if __name__ == "__main__":
    p = Propmaster()
    p.props.setM({
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
    src = f'One $<>two$<> three'
    print (str(p.parseText(src)))
    src = f'One $< >two$< > three'
    print (str(p.parseText(src)))
    src = f'Output form: $outputForm'
    print (str(p.parseText(src)))
    src = f'Deserialize from: $<$deserializeFrom [ $selector ]>'
    print (str(p.parseText(src)))
    src = f'Deserialize from: $<$deserializeFrom [$selector+1]>'
    print (str(p.parseText(src)))
    src = f'Script: $<$< len(props.get("deserializeFrom"))> * ($selector+1)>'
    print (str(p.parseText(src)))
    src = f'Deserialize from humon: $<if "humon" in $deserializeFrom>yes$<else>no$<endif>'
    print (str(p.parseText(src)))
    src = f'Deserialize from telepathy: $<if "telepathy" in $deserializeFrom>yes$<else>no$<endif>'
    print (str(p.parseText(src)))
    src = f'Deserialize from preferred method: $<if "telepathy" in $deserializeFrom>telepathy$<elif "binary" in $deserializeFrom>binary$<else>humon$<endif>'
    print (str(p.parseText(src)))
    src = f'$<if $<if "binary" in $deserializeFrom>"Weeby"$<else>"Rude"$<endif> in $cats>Treats!$<else>Snacks!$<endif>'
    print (str(p.parseText(src)))
    src = f'Deserialize from: [$<join for method in $deserializeFrom> $method$<delim>,\n                    $<endjoin> ]'
    print (str(p.parseText(src)))
    src = f'cats: $<in test_input.scribe> baz'
    print (str(p.parseText(src)))
    src = f'foo $<out test_output>test $outputForm$<endout>bar'
    print (str(p.parseText(src)))
    src = f'foo $<set test_output as $outputForm>test $test_output$<endset> bar'
    print (p.parseTagStructure(src))
    print (str(p.parseText(src)))
    src = f'foo $<set test_output as $serializeTo>test $<$test_output[2]>$<endset> bar'
    print (str(p.parseText(src)))
    src  = '''Tabulated data: $<join for pay in $dollaz>$$$<fmt right $dataColumns>$pay$<endfmt>$<delim>
                $<endjoin>'''
    print (str(p.parseText(src)))
    src  = '''Tabulated data: $<join for pay in $dollaz>$$$<r"$`{0:>8.1f}`".format($pay)>$<delim>
                $<endjoin>'''
    print (str(p.parseText(src)))
    src = f'''$+
Deserialize from: [ $+
    $< join for method in $deserializeFrom >$+
        $method$+
        $<    delim   >,
                    $+
    $< endjoin > $+
]'''
    print (str(p.parseText(src)))
    src = f'foo $<#if you see me you have FAILED>bar'
    print (str(p.parseText(src)))
    src = f"$<set const as $<$const>>$<$const($type + \"&\")> foo;$<endset>"
    print (p.parseTagStructure(src))
    print (str(p.parseText(src)))

