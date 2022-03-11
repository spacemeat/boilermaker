# TODO: This is intended to replace boma.py
import sys
import os
from .ansi import Ansi
from .project import Project


# plugin stuff
'''
We need plugins to:
    o   present props for inheritance
    o   process props, possibly by doing things like parsing external files
    o   process props, possibly converting types and enums into target-specific data
    o   contain scribe files for output

plugins/$pluginName/props.hu        - available props for inheritance
plugins/$pluginName/plugin.py       - plugin module
plugins/$pluginName/*.py            - other modules for plugin
plugins/$pluginName/default.scribe  - output
plugins/$pluginName/*.scribe        - other scribe files for output

Each plugin has functions:
    def transform(props) -> None
    def output(props) -> None
which modifies props, and possibly has side effects like output.

Boma runs in phases:
    props       (loads Props from .hu files)
    transform   (nop), call plugin.transform() in inherit order
    output      (prepares reports), call plugin.output() in inherit order

In general, unless a plugin is disabled it will run transform. Output must be optional, and may not be called by boma.
'''


# cmdline:
# $ python -m boilermaker boma.hu [--props || -p || --enums || -e || --types || -t || --write || -w]

def main():
    reportProps = False
    reportEnums = False
    reportTypes = False
    write = False
    propsFile = None
    A = Ansi()

    for arg in sys.argv:
        if arg == '--props' or arg == '-p':
            reportProps = True
        elif arg == '--enums' or arg == '-e':
            reportEnums = True
        elif arg == '--types' or arg == '-t':
            reportTypes = True
        elif arg == '--write' or arg == '-w':
            write = True
        else:
            propsFile = arg

    path = os.path.abspath(propsFile)
    project = Project(A, path)
    return 0 if project.run() else 1