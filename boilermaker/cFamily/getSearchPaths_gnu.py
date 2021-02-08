from .. import utilities

def getSearchPaths(defsPath):
    quotedSearchPaths = []
    systemSearchPaths = []

    quotedSearchPaths.append(defsPath)

    cp = utilities.doShellCommand('cpp -v /dev/null -o /dev/null')
    if cp.returncode == 0:
        sps = cp.stderr[
            cp.stderr.find('#include "..." search starts here:') : 
            cp.stderr.find('#include <...> search starts here:')].strip()
        spsp = sps.find('/')
        if spsp >= 0:
            sps = sps[spsp:]
            quotedSearchPaths = [p.strip() for p in sps.split('\n')]

        sps = cp.stderr[
            cp.stderr.find('#include <...> search starts here:') : 
            cp.stderr.find('End of search list.')].strip()
        spsp = sps.find('/')
        if spsp >= 0:
            sps = sps[spsp:]
            systemSearchPaths = [p.strip() for p in sps.split('\n')]

    return (quotedSearchPaths, systemSearchPaths)
