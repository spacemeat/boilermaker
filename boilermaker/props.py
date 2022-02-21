#from . import utilities

#props.set('copyable', False)
#props.set('movable', True)
#props.push()
#props.set('movable', False)
#...
#props.pop()
# # now props.movable == True again

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


re_if = re.compile(r'^(\s*if)[^A-Za-z0-9_]?')
re_elif = re.compile(r'^(\s*elif)[^A-Za-z0-9_]')
re_else = re.compile(r'^(\s*else)\s*$')
re_endif = re.compile(r'^(\s*endif)\s*$')
re_join = re.compile(r'^(\s*join)[^A-Za-z0-9_]?')
re_delim = re.compile(r'^(\s*delim)[^A-Za-z0-9_]?')
re_endjoin = re.compile(r'^(\s*endjoin)\s*$')
re_out = re.compile(r'^(\s*out\s+)[^A-Za-z0-9_]?')
re_in = re.compile(r'^(\s*in\s+)[^A-Za-z0-9_]?')
re_endout = re.compile(r'^(\s*endout)\s*$')
re_set = re.compile(r'^(\s*set\s+)[^A-Za-z0-9_]?')
re_endset = re.compile(r'^(\s*endset)\s*$')
re_fmt = re.compile(r'^(\s*fmt\s+)[^A-Za-z0-9_]?')
re_endfmt = re.compile(r'^(\s*endfmt)\s*$')

re_joinexpr = re.compile(f'^(\s*for\s+)([A-Za-z_][A-Za-z0-9_]*)(\s+in\s+)')
re_setexpr = re.compile(f'^([A-Za-z_][A-Za-z0-9_]*)(\s*as\s+)')

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


from enum import Enum, auto
class ClauseKind(Enum):
    TEXT = auto(),
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
    ENDOUT = auto()
    IN = auto(),
    SET = auto(),
    SETASSIGNMENT = auto(),
    ENDSET = auto(),
    FMT = auto(),
    FMTCODE = auto()
    ENDFMT = auto()

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
                    accum = f'${quoteChar}'
                    while idx < end and val[idx] != quoteChar:
                        accum += val[idx]
                        idx += 1
                    accum = f'{quoteChar}'
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

                elif type(currentClause.terms[0]) is not str:
                    currentClause = currentClause.parent
                    dbg(f'tag')

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

            else:   # all other chars before $
                accum = ''
                while idx < end and val[idx] != '$' and val[idx] != '>':
                    accum += val[idx]
                    idx += 1
                dbg(f'verbatim: {accum}')
                currentClause.append(accum)

        return rootClause

    def parseClause(self, clause):
        accum = ''
        if type(clause) is str:
            accum += clause

        elif (clause.kind == ClauseKind.TEXT or
            clause.kind == ClauseKind.THEN):
            expr = ''
            for tidx, t in enumerate(clause.terms):
                expr += self.parseClause(t)
            accum += expr

        elif clause.kind == ClauseKind.QUERY:
            expr = f'props.get("{clause.terms[0]}")'
            if (clause.parent.kind == ClauseKind.EXPRESSION or
                clause.parent.kind == ClauseKind.IFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELIFCONDITIONAL or
                clause.parent.kind == ClauseKind.ELSE or
                clause.parent.kind == ClauseKind.JOINCOMPREHENSION or
                clause.parent.kind == ClauseKind.SETASSIGNMENT):
                accum += expr
            else:
                res = eval(expr, {}, {'props': self.props})
                if res:
                    accum += str(res)
                else:
                    accum += f'$<!{clause.terms[0]}>'

        elif clause.kind == ClauseKind.EXPRESSION:
            # parseClauses on expression contents
            expr = ''
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    expr += self.parseClause(t)
                elif t.kind == ClauseKind.QUERY:
                    expr += self.parseClause(t)
                else:
                    text = self.parseClause(t)
                    expr += f'{text}'

            # eval returned exression
            res = ''
            if expr.strip() != '':
                res = str(eval(expr, {}, {'props': self.props}))
            # return eval results
            accum += self.parseClause(self.parseTagStructure(res))

        elif (clause.kind == ClauseKind.IFCONDITIONAL or
            clause.kind == ClauseKind.ELIFCONDITIONAL or
            clause.kind == ClauseKind.ELSE or
            clause.kind == ClauseKind.JOINCOMPREHENSION or
            clause.kind == ClauseKind.SETASSIGNMENT):
            # parseClauses on expression contents
            expr = ''
            for tidx, t in enumerate(clause.terms):
                expr += self.parseClause(t)

            accum += expr

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
                #breakpoint()
                res = eval(expr, {}, {'props': self.props})
                #   if eval is True:
                assert(type(res) is bool)
                if type(res) is bool and res == True:
                #       gather each text clause after idx
                    i = tidx + 1
                    assert(clause.terms[i].kind == ClauseKind.THEN)
                    accum += self.parseClause(clause.terms[i])
                    break

        elif clause.kind == ClauseKind.JOIN:
            compClause = -1
            delimClause = -1
            for tidx, t in enumerate(clause.terms):
                if type(t) is str:
                    continue
                elif t.kind == ClauseKind.JOINCOMPREHENSION:
                    compClause = tidx
                elif t.kind == ClauseKind.DELIM:
                    delimClause = tidx
                elif (t.kind == ClauseKind.THEN or
                    t.kind == ClauseKind.ENDJOIN):
                    pass
                else:
                    raise RuntimeError(f'Found a clause of type {t.kind} in an $<if> tag.')

            if compClause < 0:
                raise RuntimeError(f'No comprehension found for join tag.')
            c = self.parseClause(clause.terms[compClause])

            # parse 'for x in y' to set up the loop on x, y
            # for must be 'for'
            # x must be a symbol-legal string
            # in must be 'in'
            # y is the rest is an expression for 'for foo in (y)'

            if m := re.match(re_joinexpr, c):
                varname = m.group(2)
                expr = c[len(m.group(0)):]

                vals = eval(expr, {}, {'props': self.props})

                for vidx, val in enumerate(vals):
                    self.props.push()
                    self.props.set(varname, val)
                    th = self.parseClause(clause.terms[compClause + 1])
                    d = ''
                    if delimClause >= 0:
                        d = self.parseClause(clause.terms[delimClause + 1])

                    accum += th
                    if len(d) > 0 and vidx < len(vals) - 1:
                        accum += d
                    self.props.pop()

            else:
                raise RuntimeError(f'malformed join tag')

        elif clause.kind == ClauseKind.IN:
            accum += f'!<FILE IN: {clause.terms[0].terms[0]}>'

        elif clause.kind == ClauseKind.OUT:
            accum += f'<!FILE OUT: {clause.terms[0].terms[0]}>'

        elif clause.kind == ClauseKind.SET:
            keyClause = 0

            # parse 'for x in y' to set up the loop on x, y
            # for must be 'for'
            # x must be a symbol-legal string
            # in must be 'in'
            # y is the rest is an expression for 'for foo in (y)'
            k = self.parseClause(clause.terms[keyClause])
            if m := re.match(re_setexpr, k):
                varname = m.group(1)
                expr = k[len(m.group(0)):]

                val = eval(expr, {}, {'props': self.props})

                self.props.push()
                self.props.set(varname, val)
                th = self.parseClause(clause.terms[keyClause + 1])
                accum += th

                self.props.pop()

            else:
                raise RuntimeError(f'malformed set tag')

        # :[[<fill>]<align>][<sign>][#][0][<width>][<group>][.<prec>][<type>]
        elif clause.kind == ClauseKind.FMT:
            fmtcodeKey = 0
            fmtcode = clause.terms[fmtcodeKey].terms[0]
            if fmtcode[0] == ':':
                #breakpoint()
                fmtcode = f'{{0{fmtcode}}}'
                th = self.parseClause(clause.terms[fmtcodeKey + 1])
                th = fmtcode.format(th)
                accum += th

            else:
                raise RuntimeError(f'malformed fmt tag')

        # replace myself with the joined text
        return accum


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
            'dollaz': [1.23, -2.34, 3.45]
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
    src = f'foo $<out test_output>test $outputForm$<endout>bar'
    print (p.parseTagStructure(src))
    print (str(p.parseText(src)))
    src = f'foo $<set test_output as $outputForm>test $test_output$<endset> bar'
    print (str(p.parseText(src)))
    src = f'foo $<set test_output as $serializeTo>test $<$test_output[2]>$<endset> bar'
    print (str(p.parseText(src)))
    # TODO NEXT: fmt needs a redesign. Just a width, centering and pad char.
    src  = '''Tabulated data: $<join for pay in $dollaz>$$$<fmt : =+8,.2f>$pay$<endfmt>$<delim>
                $<endjoin>'''
    print (p.parseTagStructure(src))
    #print (str(p.parseText(src)))
