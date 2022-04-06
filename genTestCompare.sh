#!/usr/bin/bash

if [ $1 == debug ] ; then
    python3 -m pdb -m boilermaker testSamples/testCompare/defs.hu
else
    python3 -m boilermaker testSamples/testCompare/defs.hu
fi
