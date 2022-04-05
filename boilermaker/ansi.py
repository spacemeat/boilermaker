from pathlib import Path

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

    usingColor = True

    @classmethod
    def c(cls, string, fg, bg = 'black'):
        if not cls.usingColor:
            return string

        on = ''
        dkon = ''
        lton = ''
        off = Ansi.all_off
        if   fg == 'dk_black':      on = Ansi.dk_black_fg;      dkon = Ansi.dk_black_fg;    lton = Ansi.dk_black_fg
        elif fg == 'dk_red':        on = Ansi.dk_red_fg;        dkon = Ansi.dk_red_fg;      lton = Ansi.dk_red_fg
        elif fg == 'dk_green':      on = Ansi.dk_green_fg;      dkon = Ansi.dk_green_fg;    lton = Ansi.dk_green_fg
        elif fg == 'dk_yellow':     on = Ansi.dk_yellow_fg;     dkon = Ansi.dk_yellow_fg;   lton = Ansi.dk_yellow_fg
        elif fg == 'dk_blue':       on = Ansi.dk_blue_fg;       dkon = Ansi.dk_blue_fg;     lton = Ansi.dk_blue_fg
        elif fg == 'dk_cyan':       on = Ansi.dk_cyan_fg;       dkon = Ansi.dk_cyan_fg;     lton = Ansi.dk_cyan_fg
        elif fg == 'dk_magenta':    on = Ansi.dk_magenta_fg;    dkon = Ansi.dk_magenta_fg;  lton = Ansi.dk_magenta_fg
        elif fg == 'dk_white':      on = Ansi.dk_white_fg;      dkon = Ansi.dk_white_fg;    lton = Ansi.dk_white_fg

        elif fg == 'lt_black':      on = Ansi.lt_black_fg;      dkon = Ansi.lt_black_fg;    lton = Ansi.lt_black_fg
        elif fg == 'lt_red':        on = Ansi.lt_red_fg;        dkon = Ansi.lt_red_fg;      lton = Ansi.lt_red_fg
        elif fg == 'lt_green':      on = Ansi.lt_green_fg;      dkon = Ansi.lt_green_fg;    lton = Ansi.lt_green_fg
        elif fg == 'lt_yellow':     on = Ansi.lt_yellow_fg;     dkon = Ansi.lt_yellow_fg;   lton = Ansi.lt_yellow_fg
        elif fg == 'lt_blue':       on = Ansi.lt_blue_fg;       dkon = Ansi.lt_blue_fg;     lton = Ansi.lt_blue_fg
        elif fg == 'lt_cyan':       on = Ansi.lt_cyan_fg;       dkon = Ansi.lt_cyan_fg;     lton = Ansi.lt_cyan_fg
        elif fg == 'lt_magenta':    on = Ansi.lt_magenta_fg;    dkon = Ansi.lt_magenta_fg;  lton = Ansi.lt_magenta_fg
        elif fg == 'lt_white':      on = Ansi.lt_white_fg;      dkon = Ansi.lt_white_fg;    lton = Ansi.lt_white_fg

        elif fg == 'black':         on = Ansi.lt_black_fg;      dkon = Ansi.dk_black_fg;    lton = Ansi.lt_black_fg
        elif fg == 'red':           on = Ansi.lt_red_fg;        dkon = Ansi.dk_red_fg;      lton = Ansi.lt_red_fg
        elif fg == 'green':         on = Ansi.lt_green_fg;      dkon = Ansi.dk_green_fg;    lton = Ansi.lt_green_fg
        elif fg == 'yellow':        on = Ansi.lt_yellow_fg;     dkon = Ansi.dk_yellow_fg;   lton = Ansi.lt_yellow_fg
        elif fg == 'blue':          on = Ansi.lt_blue_fg;       dkon = Ansi.dk_blue_fg;     lton = Ansi.lt_blue_fg
        elif fg == 'cyan':          on = Ansi.lt_cyan_fg;       dkon = Ansi.dk_cyan_fg;     lton = Ansi.lt_cyan_fg
        elif fg == 'magenta':       on = Ansi.lt_magenta_fg;    dkon = Ansi.dk_magenta_fg;  lton = Ansi.lt_magenta_fg
        elif fg == 'white':         on = Ansi.lt_white_fg;      dkon = Ansi.dk_white_fg;    lton = Ansi.lt_white_fg

        if type(string) is Path:
            return f'{dkon}{str(string.parent)}/{lton}{string.name}'

        return f'{on}{string}{off}'

    @classmethod
    def p(cls, path, color):
        if cls.usingColor:
            if   color == 'black':         dkon = Ansi.dk_black_fg;    lton = Ansi.lt_black_fg
            elif color == 'red':           dkon = Ansi.dk_red_fg;      lton = Ansi.lt_red_fg
            elif color == 'green':         dkon = Ansi.dk_green_fg;    lton = Ansi.lt_green_fg
            elif color == 'yellow':        dkon = Ansi.dk_yellow_fg;   lton = Ansi.lt_yellow_fg
            elif color == 'blue':          dkon = Ansi.dk_blue_fg;     lton = Ansi.lt_blue_fg
            elif color == 'cyan':          dkon = Ansi.dk_cyan_fg;     lton = Ansi.lt_cyan_fg
            elif color == 'magenta':       dkon = Ansi.dk_magenta_fg;  lton = Ansi.lt_magenta_fg
            elif color == 'white':         dkon = Ansi.dk_white_fg;    lton = Ansi.lt_white_fg
            return f'{dkon}{str(path.parent)}/{lton}{path.name}{Ansi.all_off}'
        else:
            return str(path)
