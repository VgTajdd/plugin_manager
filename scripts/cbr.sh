#! /bin/sh

CURRENT_DIR=`pwd`

cmake -S . -B build
cmake --build build --config Debug -j
cd "$CURRENT_DIR/build/bin" && ./app && cd $CURRENT_DIR
