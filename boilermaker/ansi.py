
class Ansi:
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

    def __init__(self, usingColor = True):
        self.usingColor = usingColor

    def c(self, string, fg, bg = 'black'):
        if not self.usingColor:
            return string

        on = ''
        off = Ansi.all_off
        if   fg == 'dk_black':      on = Ansi.dk_black_fg
        elif fg == 'dk_red':        on = Ansi.dk_red_fg
        elif fg == 'dk_green':      on = Ansi.dk_green_fg
        elif fg == 'dk_yellow':     on = Ansi.dk_yellow_fg
        elif fg == 'dk_blue':       on = Ansi.dk_blue_fg
        elif fg == 'dk_cyan':       on = Ansi.dk_cyan_fg
        elif fg == 'dk_magenta':    on = Ansi.dk_magenta_fg
        elif fg == 'dk_white':      on = Ansi.dk_white_fg
        elif fg == 'lt_black':      on = Ansi.lt_black_fg
        elif fg == 'lt_red':        on = Ansi.lt_red_fg
        elif fg == 'lt_green':      on = Ansi.lt_green_fg
        elif fg == 'lt_yellow':     on = Ansi.lt_yellow_fg
        elif fg == 'lt_blue':       on = Ansi.lt_blue_fg
        elif fg == 'lt_cyan':       on = Ansi.lt_cyan_fg
        elif fg == 'lt_magenta':    on = Ansi.lt_magenta_fg
        elif fg == 'ltk_white':     on = Ansi.lt_white_fg

        return f'{on}string{off}'
