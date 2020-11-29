#!/usr/bin/bash

if [ -d ./humon ]; then
    rm -r ./humon
fi

cp -r ../humon-py/humon ./humon
