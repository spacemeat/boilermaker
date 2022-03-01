# TODO: This is intended to replace boma.py
import sys
import os
from .ansi import Ansi
from .project import Project


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
