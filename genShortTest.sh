#!/usr/bin/bash

if [ $1 == debug ] ; then
    python -m pdb -m boilermaker testSamples/shortTest/defs.hu -g
else
    python -m boilermaker testSamples/shortTest/defs.hu -g
fi
