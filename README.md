# Plugin Manager

Plugin Manager developed in C++.

[![CMake-Ubuntu](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake_ubuntu.yml/badge.svg?branch=main&event=push)](https://github.com/VgTajdd/plugin_manager/actions/workflows/cmake_ubuntu.yml)

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
    ```
    ./build/bin/app
    ```
- For ```Windows```:
    ```
    build/bin/Debug/app.exe
    ```

### Visual Studio Code

I added some helper files for ```vscode``` if the user prefers to use this IDE. If ```vscode``` is chosen, I recommend to install and use the extension [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools). It works for Windows, Linux and macOS.

### Windows

It also possible to load and build the project using ```Visual Studio```.
## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
