#!/usr/bin/bash

if [[ $1 == debug ]] ; then
    python3 -m pdb -m boilermaker testSamples/defaults/defs.hu
else
    python3 -m boilermaker testSamples/defaults/defs.hu
fi
