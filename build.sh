#!/bin/bash

[[ -d build ]] || mkdir -p build

gcc -O2 -o build/screencon src/screencon.c

if [ ! -f ./build/screencon ]; then
    echo "executable not built correctly"
    exit
fi

chmod u+x build/screencon

sudo cp build/screencon /usr/local/bin/screencon
