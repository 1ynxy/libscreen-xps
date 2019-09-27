#!/bin/bash

[[ -d build ]] || mkdir -p build

gcc -O2 -o build/screencon src/screencon.c

if [ ! -f ./build/screencon ]; then
    echo "executable not built correctly"
    exit
fi

chmod u+x build/screencon

# install

[[ $# > 0 ]] && [[ $1 == "run" ]] && build/screencon

[[ $# > 0 ]] && [[ $1 == "install" ]] && sudo cp build/screencon /usr/local/bin/screencon
