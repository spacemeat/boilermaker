#!/usr/bin/bash

if [ $1. == debug. ] ; then
    python -m pdb -m boilermaker testSamples/scribeRefact/boma.hu -p -e -t
else
    python -m boilermaker testSamples/scribeRefact/boma.hu -p -e -t
fi
