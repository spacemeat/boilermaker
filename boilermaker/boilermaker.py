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
    propsFile = None

    propAdds = {}
    for arg in sys.argv:
        vals = arg.split('=')
        if len(vals) > 1:
            for i in range(0, len(vals) - 1):
                propAdds[vals[i]] = vals[-1]
        else:
            propsFile = arg

    path = os.path.abspath(propsFile)
    project = Project(path, propAdds)
    return 0 if project.run() else 1
