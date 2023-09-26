# SWPacker
## Description
SWPacker is program that allow to pack all files from a directory. 
It builds a single file `.swfp` with all resources inside.

## Compilation
The compilation is simple, you can choose between two target: Packer and Unpacker.
```shell
mkdir "build" && cd build
cmake -G "Visual Studio 17 2022" -DCMAKE_BUILD_TYPE=[Debug/Release] ..
cmake --build . --target SWEngine-[packer/unpacker]_1.1 --config [Debug/Release]
```
#### Option
You can define an option by using : `-D[option]=[value]`
- CMAKE_BUILD_TYPE: Debug/Release
- SWFP_COMP: ON/OFF
- BUILD_UNPACK_LIB_SHARED: ON/OFF
- BUILD_UNPACK_LIB_STATIC: ON/OFF

## Usage
### Packer
Simply run the executable and give the directory you want to pack.
```shell
./SWEngine-packer [PATH_TO_DIRECTORY]
```

### UnPacker
Simply run the executable and give the directory where the file `.swfp` file is.
```shell
./SWEngine-unpacker [PATH_TO_SWFP_FILE]
```

### Compression
You're able to add a compression process in the packer (and decompress for unpacker).
To do so, go to `Packer.cpp` and find the `SWFP_COMP` macro and edit the code above to add
your own compression process. For `UnPacker.cpp` find `SWFP_COMP` and edit the code above.

To enable the compression process use `-DSWFP_COMP=ON` (default: OFF).

Note: There is a default compression algorithm: [zstd](https://github.com/facebook/zstd). \
The header is already include in the project just build a __static__ libraries and add it to the cmake. \
Add `zstd_static` to `STATIC_LIB_NAME` and `${CMAKE_SOURCE_DIR}/libraries/zstd_static.lib` to `STATIC_LIB` in the CMakeLists.txt.

## Authors
The project is made by [Guillaume Soisson](https://github.com/Alvarwow69).

## Credits
This project is based on raysan5 works for [rres](https://github.com/raysan5/rres) \
This project use [zstd](https://github.com/facebook/zstd) to provide default compression process.