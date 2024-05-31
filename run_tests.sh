#!/bin/bash

cmake --build build/tests --target test_plugin_manager -j
cd build && ctest --output-on-failure && cd ..
