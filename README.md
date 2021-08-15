# Plugin Manager
Plugin Manager developed in C++.

# Build & run

I added some helper files for ```vscode``` if the user prefer to use this IDE. If ```vscode``` is choosen, I recommend to install and use the extension [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools). It works for Windows, Linux and macOS.

## Linux - macOS

If you prefer to use the terminal instead of ```vscode```, use these commands:

```bash
git clone https://github.com/vgtajdd/plugin_manager.git
cd plugin-manager
mkdir build
cd build
cmake ..
make -j
./bin/app
```
or just use this script:

```bash
source script/rebuild.bash
```
and then run it:
```bash
./bin/app
```
## Windows

Use the equivalent commands. It also possible to load and build the project using ```Visual Studio```.

## TODO
Go to [TODO.md](TODO.md)

## Contributing

Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

## License

[MIT](https://choosealicense.com/licenses/mit/)
