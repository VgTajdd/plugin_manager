# Plugin Manager

Plugin Manager developed in C++.

[![CMake-CI](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake.yml/badge.svg)](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake.yml)

## Usage

Clone the repository using one of the following commands:

```bash
git clone https://github.com/vgtajdd/plugin_manager.git     # HTTPS
git clone git@github.com:VgTajdd/plugin_manager.git         # SSH
```

Configure the project (CMake):

```bash
cd plugin_manager
cmake -S . -B build
```

Build the targets (CMake):

```bash
cmake --build build --config Debug -j
```

Run the main target:

- For ```macOS``` and ```Linux```:

    ```bash
    cd build/bin
    ./app
    ```

- For ```Windows```:

    ```bash
    cd build/bin/Debug
    app.exe
    ```

### Visual Studio Code

I added some helper files for ```vscode``` if the user prefers to use this IDE. If ```vscode``` is chosen, I recommend to install and use the extension [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools). It works for Windows, Linux and macOS.

### Windows

It also possible to load and build the project using ```Visual Studio```.

## Tests

Use the following commands:

```bash
cmake --build build/tests --target test_plugin_manager -j
cd build && ctest --output-on-failure && cd ..
```
## Contributing

Just to let you know, pull requests are welcome. For major changes, please open an issue first to discuss what you want to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
