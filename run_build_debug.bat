@echo off

cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug
cmake --build build --config Debug -j
cd build/Debug/
app.exe
cd ../..
cmd /k
