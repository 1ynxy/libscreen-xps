#!/bin/bash

# create build folder

[[ -d build ]] || mkdir -p build

# delete existing builds

[[ -f build/screenconnect ]] && rm build/screenconnect
[[ -f build/screenorient ]] && rm build/screenorient

# build

gcc -O2 -o build/screenconnect src/screenconnect.c
gcc -O2 -o build/screenorient src/screenorient.c

# exit if failed

[[ -f build/screenconnect ]] && [[ -f build/screenorient ]] && exit

chmod u+x build/screenconnect
chmod u+x build/screenorient

# run or install

[[ $# > 0 ]] && [[ $1 == "run" ]] && build/screenconnect &
[[ $# > 0 ]] && [[ $1 == "run" ]] && build/screenorient &

[[ $# > 0 ]] && [[ $1 == "install" ]] && sudo cp build/screenconnect /usr/local/bin/screenconnect
[[ $# > 0 ]] && [[ $1 == "install" ]] && sudo cp build/screenorient /usr/local/bin/screenorient
