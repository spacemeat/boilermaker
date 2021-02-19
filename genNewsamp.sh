#!/usr/bin/bash

if [ $1 == debug ] ; then
    python -m pdb -m boilermaker testSamples/newsamp/defs.hu -g
else
    python -m boilermaker testSamples/newsamp/defs.hu -g
fi
