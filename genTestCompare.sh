#!/usr/bin/bash

if [ $1 == debug ] ; then
    python -m pdb -m boilermaker testSamples/testCompare/defs.hu -p -e -t -w
else
    python -m boilermaker testSamples/testCompare/defs.hu -p -e -t -w
fi
