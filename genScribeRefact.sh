#!/usr/bin/bash

if [ $1. == debug. ] ; then
    python -m pdb -m boilermaker testSamples/scribeRefact/boma.hu -p -e -t -w
else
    python -m boilermaker testSamples/scribeRefact/boma.hu -p -e -t -w
fi