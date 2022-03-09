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

Each plugin has a function:
    def onPhase(phase, props)
which modifies props, and possibly has side effects like output. phase is one of:
    props       boma (loads from .hu files), plugins in inherit order
    enums       boma (interprets user-defined enum values), plugins in inherit order (maybe load from other sources like C headers)
    types       boma (interprets user-defined type values), plugins in inherit order (maybe
    transform   boma (none), plugins in inherit order
    output      boma (prepares reports), plugins in inherit order
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

    if write or reportProps:
        if reportProps:
            project.reportProps()

    if write or reportEnums or reportTypes:
        project.makeEnums()
        if reportEnums:
            project.reportEnums()

    if write or reportTypes:
        project.makeTypes()
        if reportTypes:
            project.reportTypes()

    if write:
        project.write()
