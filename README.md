# Plugin Manager

Plugin Manager developed in C++.

[![CMake-CI](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake.yml/badge.svg)](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake.yml)

## Usage

Clone the repository using one of the following commands:

```bash
git clone https://github.com/vgtajdd/plugin_manager.git     # HTTPS
git clone git@github.com:VgTajdd/plugin_manager.git         # SSH
```

Run one of these scripts for building or rebuilding the project depending on your OS:

```
run_build_debug.bat
run_build_debug.sh
rebuild_debug.bat
rebuild_debug.sh
```

If you prefer to manually build the project, use the following commands.

### Debug and Release

#### Single configurations (CLI)

```js
# Debug.
cmake -S. -B build -DCMAKE_BUILD_TYPE=Debug     # Configure.
cmake --build build --config Debug -j           # Build.

# Release.
cmake -S. -B build -DCMAKE_BUILD_TYPE=Release   # Configure.
cmake --build build --config Release -j         # Build.
```

#### Multi-configuration
```js
cmake -S. -B build -DCMAKE_CONFIGURATION_TYPES="Debug;Release"
```
Or simply run ```generate_vs_solution.bat``` if you are using ```Windows```.

Then you could use ```Visual Studio``` if you are using ```Windows```.

## Tests

Run one of these scripts to run the tests depending on your OS:

```
run_tests.bat
run_tests.sh
```

If you prefer to manually run the tests, run the following commands:

```js
cmake --build build/tests --target test_plugin_manager -j
cd build && ctest --output-on-failure && cd ..
```

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
