#! /bin/sh

SCRIPT_DIR=`dirname $0`
CURRENT_DIR=`pwd`

cd $SCRIPT_DIR/../      # Change dir to project directory.
rm -rf build            # Remove previous build directory (if exists).
mkdir build             # Create build directory.
cmake -S . -B build     # Configure project (cmake).
cd build                # Change dir to build directory.
make                    # Build targets.
cd $CURRENT_DIR         # Return to previous directory.
