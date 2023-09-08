# SWPacker
## Description
SWPacker is program that allow to pack all files from a directory. 
It builds a single file `.swfp` with all resources inside.

## Compilation
The compilation is simple, you can choose between two target: Packer and Unpacker.
```shell
mkdir "build" && cd build
cmake -G "Visual Studio 17 2022" - DCMAKE_BUILD_TYPE=[Debug/Release] ..
cmake --build . --target SWEngine-[packer/unpacker]_0.1 --config [Debug/Release]
```

## Usage
### Packer
Simply run the executable and give the directory you want to pack.
```shell
./SWEngine-packer_0.1 [PATH_TO_DIRECTORY]
```

### UnPacker
Simply run the executable and give the directory where the file `.swfp` file is.
```shell
./SWEngine-unpacker_0.1 [PATH_TO_SWFP_FILE]
```

## Authors
The project is made by [Guillaume Soisson](https://github.com/Alvarwow69). \
This project is based on raysan5 works for [rres](https://github.com/raysan5/rres)