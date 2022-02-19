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
re_join = re.compile(r'^(\s*join)[^A-Za-z0-9_]?')
re_file = re.compile(r'^(\s*file)[^A-Za-z0-9_]?')
re_endif = re.compile(r'^(\s*endif)\s*$')
re_endjoin = re.compile(r'^(\s*endjoin)\s*$')
re_endfile = re.compile(r'^(\s*endfile)\s*$')
re_elif = re.compile(r'^(\s*elif)[^A-Za-z0-9_]')
re_else = re.compile(r'^(\s*else)\s*$')
re_delim = re.compile(r'^(\s*delim)[^A-Za-z0-9_]?')

re_joinexpr = re.compile(f'^(\s*for\s+)([A-Za-z_][A-Za-z0-9_]*)(\s+in\s+)')

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


def parseTag_old(val, props):
    class Clause:
        def __init__(self):
            self.parent = None
            self.terms = []     # a term is either a string or another Clause
            self.isIf = False
            self.isJoin = False
            self.isFile = False
            self.isObject = False

        def toStr(self, indent = 0):
            s = ''
            ind = '  ' * indent
            for t in self.terms:
                if type(t) == str:
                    s += f'{ind}"{t}"\n'
                elif type(t) == Clause:
                    s += f'{ind}{{\n{t.toStr(indent + 1)}\n{ind}}}\n'
                else:
                    s += f'{ind}<{t}:{type(t)}>\n'
            return s

        def __repr__(self):
            return self.toStr()

    if type(val) is not str:
        c = Clause()
        c.terms.append(val)
        c.isObject = True
        return c

    idx = 0
    end = len(val)
    inTag = False
    inQuote = False
    atWordBoundary = True
    quoteChar = ''
    accum = ''
    rootClause = Clause()
    currentClause = rootClause
    while idx < end:
        if val[idx] == '$':
            if idx < end - 1 and val[idx + 1] == '<':
                idx += 1
                atWordBoundary = True
                if len(accum) > 0:
                    currentClause.terms.append(accum)
                accum = ''
                newClause = Clause()
                newClause.parent = currentClause
                currentClause.terms.append(newClause)
                currentClause = newClause
                # ...
            elif idx < end - 1 and (val[idx + 1].isalpha() or val[idx + 1] == '_'):
                idx += 1
                atWordBoundary = True
                if len(accum) > 0:
                    currentClause.terms.append(accum)
                accum = ''
                fullIdent = ''
                while idx < end:
                    if val[idx].isalpha() or val[idx].isdigit() or val[idx] == '_':
                        fullIdent += val[idx]
                        idx += 1
                    else:
                        break
                idx -= 1
                if rootClause != currentClause:
                    # store the props.get string, but do not eval
                    currentClause.terms.append(f'props.get("{fullIdent}")')
                else:
                    # eval the props.get string, must be a str returned
                    res = eval(f'props.get("{fullIdent}")')
                    if type(res) != str:
                        raise RuntimeError(f'Outer tags must resovle to strings.')
                    currentClause.terms.append(res)

            elif idx < end - 1 and (val[idx + 1] == '\'' or val[idx + 1] == '"' or val[idx + 1] == '`'):
                idx += 1
                quoteChar = val[idx]
                idx += 1
                atWordBoundary = True
                if len(accum) > 0:
                    currentClause.terms.append(accum)
                accum = ''
                fullStr = ''
                while idx < end - 1:
                    if val[idx] != quoteChar:
                        fullStr += val[idx]
                        idx += 1
                    else:
                        break
                idx += 1
                if val[idx] != quoteChar:
                    raise RuntimeError('no endquote found')
                currentClause.terms.append(fullStr)

        elif val[idx] == '>':
            atWordBoundary = True
            if len(accum) > 0:
                currentClause.terms.append(accum)
            accum = ''

            firstWord = currentClause.terms[0]
            if type(firstWord) == str:
                firstWord = firstWord.strip()
                if firstWord == "if":
                    currentClause.isIf = True
                elif firstWord == "join":
                    currentClause.isJoin = True
                elif firstWord == "file":
                    currentClause.isFile = True

                if currentClause.isIf or currentClause.isJoin or currentClause.isFile:
                    newClause = Clause()
                    newClause.parent = currentClause
                    newClause.terms = currentClause.terms
                    currentClause.terms = [newClause]
                    currentClause = newClause
                else:
                    if firstWord == "endif":
                        if len(currentClause.terms) > 1:
                            raise RuntimeError("endif must be a single word tag")
                        currentClause = currentClause.parent
                        if not currentClause.isIf:
                            raise RuntimeError("endif must be paired with a prior $<if> tag")
                        # form the expr
                        #breakpoint()
                        print (f'Current clause: {currentClause}')
                        expr = 'True == ('
                        for i, t in enumerate(currentClause.terms[0].terms[1:]):
                            if type(t) is str:
                                pt = props.get(t.strip())
                                if pt:
                                    expr += f"props.get('{t.strip()}') "
                                else:
                                    expr += f"{t} "
                            else:
                                expr += f"{t} "
                        expr += ')'
                        res = eval(expr, {}, {'props': props})
                        print (f'EXPR: {expr}\nRES: {res}')
                        # eval it
                        # if true, replace this clause with eval results
                    elif firstWord == "endjoin":
                        if len(currentClause.terms) > 1:
                            raise RuntimeError("endjoin must be a single word tag")
                        currentClause = currentClause.parent
                        if not currentClause.isJoin:
                            raise RuntimeError("bad endjoin")
                        #... process join
                    elif firstWord == "endfile":
                        if len(currentClause.terms) > 1:
                            raise RuntimeError("endfile must be a single word tag")
                        currentClause = currentClause.parent
                        if not currentClause.isFile:
                            raise RuntimeError("bad endfile")
                        #... process file
                    elif firstWord == "elif" or firstWord == "else" or firstWord == "delim":
                        # TODO: properly skip this for later evaluation in the respective end tag
                        pass
                    else:
                        # eval contents - replace words in props by their values, then eval()
                        expr = ''
                        for t in currentClause.terms:
                            #print (f'looking for {t}:{type(t)}')
                            if type(t) is str:
                                pt = props.get(t.strip())
                                if pt:
                                    expr += f"props.get('{t.strip()}') "
                                else:
                                    expr += f"{t} "
                            else:
                                expr += f"{t} "

                        #res = expr
                        #print (f'eval({expr})')
                        res = eval(expr, {}, {'props': props})

                        # parse it - returns a Clause
                        subClause = parseTag(res, props)

                        # replace this clause with the results
                        currentClause.parent.terms[-1] = subClause.terms[0]


            accum = ''
            currentClause = currentClause.parent
            # ...

        elif val[idx] == ' ' or val[idx] == '\n' or val[idx] == '\t':
            atWordBoundary = True
            accum += val[idx]
            if len(accum) > 0:
                currentClause.terms.append(accum)
            accum = ''
        else:
            accum += val[idx]
            atWordBoundary = False

        idx += 1

    if len(accum) > 0:
        currentClause.terms.append(accum)

    return rootClause

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
    FILE = auto(),
    FILECOMPREHENSION = auto(),
    ENDIFILE = auto()

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


def parseTagStructure(val, props):
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
                currentClause.append('$$')

            elif val[idx] == '>':   #  $> is a way to escape > so as not to close a tag.
                idx += 1
                dbg(f'$> tag')
                currentClause.append('$>')

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
                dbg(f'tag')
                currentClause = currentClause.parent

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

            elif m := re.match(re_file, currentClause.terms[0]):
                dbg(f'file tag')
                pass

            elif m := re.match(re_endif, currentClause.terms[0]):
                currentClause.terms = []
                currentClause = currentClause.mergeToParent()
                currentClause = currentClause.parent
                if currentClause.kind != ClauseKind.IF:
                    raise RuntimeError('$<endif> does not match a preceding $<if>')
                currentClause = currentClause.parent
                dbg(f'endif -> {accum}')

            elif m := re.match(re_endjoin, currentClause.terms[0]):
                currentClause.terms = []
                currentClause = currentClause.mergeToParent()
                currentClause = currentClause.parent
                if currentClause.kind != ClauseKind.JOIN:
                    raise RuntimeError('$<endjoin> does not match a preceding $<join>')
                currentClause = currentClause.parent
                dbg(f'endjoin tag')

            elif m := re.match(re_endfile, currentClause.terms[0]):
                dbg(f'endfile tag')
                pass

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
                pass

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


def parseText(val, props):
    clause = parseTagStructure(val, props)
    return parseClause(clause, props)


def parseClause(clause, props):
    accum = ''
    if type(clause) is str:
        accum += clause

    elif (clause.kind == ClauseKind.TEXT or
          clause.kind == ClauseKind.THEN):
        expr = ''
        for tidx, t in enumerate(clause.terms):
            expr += parseClause(t, props)
        accum += expr

    elif clause.kind == ClauseKind.QUERY:
        expr = f' props.get("{clause.terms[0]}")'
        if (clause.parent.kind == ClauseKind.EXPRESSION or
            clause.parent.kind == ClauseKind.IFCONDITIONAL or
            clause.parent.kind == ClauseKind.ELIFCONDITIONAL or
            clause.parent.kind == ClauseKind.ELSE or
            clause.parent.kind == ClauseKind.JOINCOMPREHENSION):
            accum += expr
        else:
            res = eval(expr, {}, {'props': props})
            if res:
                accum += res
            else:
                accum += f'<?{clause.terms[0]}?>'

    elif clause.kind == ClauseKind.EXPRESSION:
        # parseClauses on expression contents
        expr = ''
        for tidx, t in enumerate(clause.terms):
            expr += parseClause(t, props)

        # eval returned exression
        res = ''
        if expr.strip() != '':
            res = str(eval(expr, {}, {'props': props}))
        # return eval results
        accum += parseClause(parseTagStructure(res, props), props)

    elif (clause.kind == ClauseKind.IFCONDITIONAL or
          clause.kind == ClauseKind.ELIFCONDITIONAL or
          clause.kind == ClauseKind.ELSE or
          clause.kind == ClauseKind.JOINCOMPREHENSION):
        # parseClauses on expression contents
        expr = ''
        for tidx, t in enumerate(clause.terms):
            expr += parseClause(t, props)

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
            t = parseClause(clause.terms[tidx], props)
            #   make expr
            expr = False
            if type(t) is str:
                expr = t
            elif len(t.terms) > 0:
                expr = f'True == ({"".join(t.terms)})'
            #   eval to bool
            #breakpoint()
            res = eval(expr, {}, {'props': props})
            #   if eval is True:
            assert(type(res) is bool)
            if type(res) is bool and res == True:
            #       gather each text clause after idx
                i = tidx + 1
                assert(clause.terms[i].kind == ClauseKind.THEN)
                accum += parseClause(clause.terms[i], props)
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

        # TODO: shit
        if compClause < 0:
            raise RuntimeError(f'No comprehension found for join tag.')
        c = parseClause(clause.terms[compClause], props)

        # parse 'for x in y' to set up the loop on x, y
        # for must be 'for'
        # x must be a symbol-legal string
        # in must be 'in'
        # y is the rest is an expression for 'for foo in (y)'

        if m := re.match(re_joinexpr, c):
            varname = m.group(2)
            expr = c[len(m.group(0)):]

            vals = eval(expr, {}, {'props': props})

            for vidx, val in enumerate(vals):
                props.push()
                props.set(varname, val)
                th = parseClause(clause.terms[compClause + 1], props)
                d = ''
                if delimClause >= 0:
                    d = parseClause(clause.terms[delimClause + 1], props)

                accum += th
                if len(d) > 0 and vidx < len(vals) - 1:
                    accum += d
                props.pop()

        else:
            raise RuntimeError(f'malformed join tag')

    # replace myself with the joined text
    return accum


def parseClause2(clause, props):
    accum = ''
    for t in clause.terms:
        if type(t) is str:
            accum += t

        elif t.kind == ClauseKind.EXPRESSION:
            # parseClauses on expression contents
            expr = ''
            expr += parseClause2(t, props)
            # eval returned exression
            res = ''
            if expr.strip() != '':
                res = eval(expr, {}, {'props': props})
            # return eval results
            accum += parseClause2(parseTagStructure(res, props), props)

        elif t.kind == ClauseKind.IF:
            condClause = clause.terms[0]
            for tidx, t in enumerate(condClause.terms):
                if type(t) == str:
                    continue

                elif t.kind == ClauseKind.IFCONDITIONAL or t.kind == ClauseKind.ELIFCONDITIONAL:
                    #   make expr
                    expr = f'True == ({"".join(t.terms)})'
                    #   eval to bool
                    res = eval(expr, {}, {'props': props})
                    #   if eval is True:
                    assert(type(res) is bool)
                    if type(res) is bool and res == True:
                    #       gather each text clause after idx
                        i = tidx + 1
                        assert(condClause.terms[i].kind == ClauseKind.THEN)
                        accum += parseClause2(condClause.terms[i], props)
                        break

                elif t.kind == ClauseKind.ELSE:
                    #   gather each text clause after idx
                    i = tidx + 1
                    assert(condClause.terms[i].kind == ClauseKind.THEN)
                    accum += parseClause2(condClause.terms[i], props)

                elif t.kind == ClauseKind.THEN or t.kind == ClauseKind.ENDIF:
                    continue

                else:
                    raise RuntimeError(f'Found a clause of type {t.kind} in an $<if> tag.')

    # replace myself with the joined text
    return accum

def parseTag(val, props):
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
            s += f'{ind0}<{self.kind}>:\n{ind0}{{\n'
            for t in self.terms:
                if type(t) == str:
                    s += f'{ind1}"{t}"\n'
                elif type(t) == Clause:
                    s += f'{t.toStr(indent + 1)}'
                else:
                    s += f'{ind1}<{t}:{type(t)}>\n'
            s += f'{ind0}}}\n'
            return s

        def __repr__(self):
            return self.toStr()
    # return either a string or a Clause
    #if type(val) is not str:
    #    c = Clause()
    #    c.terms.append(val)
    #    c.isObject = True
    #    return c

    idx = 0
    end = len(val)
    inTag = False
    inTagCounter = 0
    quoteChar = ''
    rootClause = Clause()
    currentClause = rootClause

    print (f'{ansi.lt_yellow_fg}Parsing {ansi.dk_yellow_fg}{val}{ansi.all_off}')

    def dbg(msg):
        print (f'{ansi.lt_magenta_fg}({idx}{ansi.dk_magenta_fg}/{len(val)}) {ansi.dk_blue_fg}"{ansi.lt_blue_fg}{msg}{ansi.dk_blue_fg}"{ansi.all_off} {ansi.dk_yellow_fg}Tag counter: {ansi.dk_yellow_fg}{inTagCounter}{ansi.all_off}')

    while idx < end:
        if inTagCounter == 0:
            if val[idx] == '$':
                idx += 1
                if val[idx] == '\'' or val[idx] == '"' or val[idx] == '`':
                    quoteChar = val[idx]
                    idx += 1
                    accum = ''
                    while idx < end and val[idx] != quoteChar:
                        accum += val[idx]
                        idx += 1
                    dbg(f'quote-tag: {accum}')
                    currentClause.append(accum)

                elif val[idx] == '<':
                    inTagCounter += 1
                    idx += 1
                    dbg(f'start tag')
                    currentClause = currentClause.appendClause()

                elif val[idx] == '$':   #  $$ is a way to escape $ so as not to start a tag.
                    idx += 1
                    currentClause.append('$')

                elif val[idx] == '>':   #  $> is a way to escape > so as not to close a tag.
                    idx += 1
                    currentClause.append('>')

                elif val[idx].isalpha() or val[idx] == '_':
                    # eval props.get which must resolve to a string (because we are not inTag)
                    accum = ''
                    while idx < end and (val[idx].isalpha() or val[idx].isdigit() or val[idx] == '_'):
                        accum += val[idx]
                        idx += 1
                    expr = f'props.get("{accum}")'
                    res = eval(expr, {}, {'props': props})
                    dbg(f'prop: key: "{accum}"  res: "{res}"')
                    if type(res) is not str:
                        raise RuntimeError(f'property queries must be strings.')
                    parsedRes = parseTag(res, props)
                    if type(parsedRes) is not str:
                        raise RuntimeError(f'property queries must be strings.')
                    currentClause.append(res)

                else:
                    raise RuntimeError('Naked query spec ($). Use $$ or $"$" to spec a "$" character.')

            else:   # all other chars before $
                accum = ''
                while idx < end and val[idx] != '$':
                    accum += val[idx]
                    idx += 1
                dbg(f'verbatim: {accum}')
                currentClause.append(accum)

        else:   # if inTagCounter > 0:
            if val[idx] == '>':
                inTagCounter -= 1
                idx += 1

                # resolve if/join/file/expr/end* tags
                if len(currentClause.terms) == 0:
                    dbg(f'empty tag')
                    # just a way of pruning this clause really
                    currentClause = currentClause.mergeToParent()

                elif m := re.match(re_if, currentClause.terms[0]):
                    ifClause = currentClause.insertClause()
                    ifClause.kind = ClauseKind.IF
                    condClause = ifClause.terms[0]
                    condClause.terms[0] = condClause.terms[0][len(m.group(1)):]
                    condClause.kind = ClauseKind.IFCONDITIONAL
                    currentClause = ifClause
                    dbg(f'if tag')

                elif m := re.match(re_join, currentClause.terms[0]):
                    joinClause = currentClause.insertClause()
                    joinClause.kind = ClauseKind.JOIN
                    condClause = ifClause.terms[0]
                    condClause.terms[0] = condClause.terms[0][len(m.group(1)):]
                    condClause.kind = ClauseKind.JOINCOMPREHENSION
                    currentClause = joinClause
                    dbg(f'join tag')

                elif m := re.match(re_file, currentClause.terms[0]):
                    dbg(f'file tag')
                    pass
                elif m := re.match(re_endif, currentClause.terms[0]):
                    currentClause = currentClause.parent
                    if currentClause.kind != ClauseKind.IF:
                        raise RuntimeError('$<endif> does not match a preceding $<if>')
                    accum = ''
                    for tidx, t in enumerate(currentClause.terms):
                        if type(t) == str:
                            continue

                        elif t.kind == ClauseKind.IFCONDITIONAL or t.kind == ClauseKind.ELIFCONDITIONAL:
                            #   make expr
                            expr = f'True == ({"".join(t.terms)})'
                            #   eval to bool
                            res = eval(expr, {}, {'props': props})
                            #   if eval is True:
                            assert(type(res) is bool)
                            if type(res) is bool and res == True:
                            #       gather each text clause after idx
                                i = tidx + 1
                                while type(currentClause.terms[i]) is str:
                                    accum += currentClause.terms[i]
                                    i += 1
                                break

                        elif t.kind == ClauseKind.ELSE:
                            #   gather each text clause after idx
                            i = tidx + 1
                            while type(currentClause.terms[i]) is str:
                                accum += currentClause.terms[i]
                                i += 1

                    # replace myself with the joined text
                    currentClause.terms = [accum]
                    currentClause = currentClause.mergeToParent()
                    dbg(f'endif -> {accum}')

                elif m := re.match(re_endjoin, currentClause.terms[0]):
                    currentClause = currentClause.parent
                    if currentClause.kind != ClauseKind.JOIN:
                        raise RuntimeError('$<endjoin> does not match a preceding $<join>')
                    accum = ''
                    for tidx, t in enumerate(currentClause.terms):
                        if type(t) == str:
                            continue

                        elif t.kind == ClauseKind.JOINCOMPREHENSION:
                            #   make expr
                            expr = f'True == ({"".join(t.terms)})'
                            #   eval to bool
                            res = eval(expr, {}, {'props': props})
                            #   if eval is True:
                            assert(type(res) is bool)
                            if type(res) is bool and res == True:
                            #       gather each text clause after idx
                                i = tidx + 1
                                while type(currentClause.terms[i]) is str:
                                    accum += currentClause.terms[i]
                                    i += 1
                                break

                        elif t.kind == ClauseKind.ELSE:
                            #   gather each text clause after idx
                            i = tidx + 1
                            while type(currentClause.terms[i]) is str:
                                accum += currentClause.terms[i]
                                i += 1

                    # replace myself with the joined text
                    currentClause.terms = [accum]
                    currentClause = currentClause.mergeToParent()
                    dbg(f'endjoin tag')

                elif m := re.match(re_endfile, currentClause.terms[0]):
                    dbg(f'endfile tag')
                    pass
                elif m := re.match(re_elif, currentClause.terms[0]):
                    currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                    currentClause.kind = ClauseKind.ELIFCONDITIONAL
                    currentClause = currentClause.parent
                    dbg(f'elif tag')

                elif m := re.match(re_else, currentClause.terms[0]):
                    currentClause.kind = ClauseKind.ELSE
                    currentClause = currentClause.parent
                    dbg(f'else tag')

                elif m := re.match(re_delim, currentClause.terms[0]):
                    currentClause.terms[0] = currentClause.terms[0][len(m.group(1)):]
                    currentClause.kind = ClauseKind.DELIM
                    currentClause = currentClause.parent
                    dbg(f'delim tag')
                    pass

                else:
                    # this should just return a python expression which is then parsed
                    #breakpoint()
                    expr = f'{"".join(currentClause.terms)}'
                    res = ''
                    if expr.strip() != '':
                        res = eval(expr, {}, {'props': props})
                    dbg(f'expr tag: expr: {expr}')
                    res = parseTag(str(res), props)
                    if type(res) is str:
                        currentClause.terms = [res]
                    #    currentClause = currentClause.mergeToParent()
                    elif type(res) is Clause:
                        assert(res.kind == ClauseKind.TEXT)
                        currentClause.terms = ''.join(res.terms)
                    #   currentClause = currentClause.parent
                    else:
                        raise RuntimeError("Wrong thing")
                    currentClause = currentClause.mergeToParent()

            elif val[idx] == '$':
                idx += 1
                if val[idx] == '\'' or val[idx] == '"' or val[idx] == '`':
                    quoteChar = val[idx]
                    idx += 1
                    accum = ''
                    while idx < end and val[idx] != quoteChar:
                        accum += val[idx]
                        idx += 1
                    dbg(f'quote-tag: {accum}')
                    currentClause.append(accum)

                elif val[idx] == '<':
                    inTagCounter += 1
                    idx += 1
                    dbg(f'start tag')
                    currentClause = currentClause.appendClause()

                elif val[idx] == '$':   #  $$ is a way to escape $ so as not to start a tag.
                    idx += 1
                    currentClause.append('$')

                elif val[idx] == '>':   #  $> is a way to escape > so as not to close a tag.
                    idx += 1
                    currentClause.append('>')

                elif val[idx].isalpha() or val[idx] == '_':
                    # because we're in a tag, a prop query results in an expression to be eval'd later
                    accum = ''
                    while idx < end and (val[idx].isalpha() or val[idx].isdigit() or val[idx] == '_'):
                        accum += val[idx]
                        idx += 1
                    expr = f' props.get("{accum}") '
                    dbg(f'prop tag: key: "{accum}"  expr: "{expr}"')
                    currentClause.append(expr)
                else:
                    raise RuntimeError('Naked query spec ($). Use $$ or $"$" to spec a "$" character.')

            else:
                accum = ''
                while idx < end and val[idx] != '$' and val[idx] != '>':
                    accum += val[idx]
                    idx += 1
                dbg(f'verbatim: {accum}')
                currentClause.append(accum)

    final = ''.join(rootClause.terms)

    return final



def transform(self, val):
    # turn string val containing $<> tags into a fully-interpolated string.
    inTag = False
    cur = 0



if __name__ == "__main__":
    p = Props()
    p.setM({
            'outputForm': 'compiled',
            'defaultConstructible': True,
            'selector': 1,
            'deserializeFrom': ['humon', 'binary', 'dna'],
            'serializeTo': ['humon', 'binary', 'dna']
    })
    src = f'One $<>two$<> three'
    print (str(parseText(src, p)))
    src = f'One $< >two$< > three'
    print (str(parseText(src, p)))
    src = f'Output form: $outputForm'
    print (str(parseText(src, p)))
    src = f'Deserialize from: $<$deserializeFrom [ $selector ]>'
    print (str(parseText(src, p)))
    src = f'Deserialize from: $<$deserializeFrom [$selector+1]>'
    print (str(parseText(src, p)))
    src = f'Script: $<$< len(props.props[0])> * ($selector+1)>'
    print (str(parseText(src, p)))
    src = f'Deserialize from humon: $<if "humon" in $deserializeFrom>yes$<else>no$<endif>'
    print (str(parseText(src, p)))
    src = f'Deserialize from telepathy: $<if "telepathy" in $deserializeFrom>yes$<else>no$<endif>'
    print (str(parseText(src, p)))
    src = f'Deserialize from preferred method: $<if "telepathy" in $deserializeFrom>telepathy$<elif "binary" in $deserializeFrom>binary$<else>humon$<endif>'
    print (str(parseText(src, p)))
    src = f'Deserialize from: [$<join for method in $deserializeFrom> $method$<delim>,\n                    $<endjoin> ]'
    #print (parseTagStructure(src, p))
    print (str(parseText(src, p)))
