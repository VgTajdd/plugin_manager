del /s /f /q build
cmake -S . -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
cd build/
start template.sln
cd ..
