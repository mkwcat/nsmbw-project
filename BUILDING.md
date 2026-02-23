# Building nsmbw-project

## Prerequisites

A few third-party tools are required in the process of building nsmbw-project:
- [CMake](https://cmake.org/)
- [Python](https://www.python.org/), with the following packages:
  - pyelftools
  - pyjson5 (if installing from pip, the package is `json5` NOT `pyjson5`)
- Some kind of CMake generator that isn't Visual Studio or Xcode.
  - Something like `Unix Makefiles` or my personal recommendation: [Ninja](https://ninja-build.org/).
- My custom fork of Clang.
  - Building Clang takes a little while and can be a process if you're on Windows, so for convenience a prebuilt Windows binary can be found on my website, [here](https://mkw.cat/d/llvm_cw_fork/clang.exe).
  - Otherwise, see the README in [tools/clang](tools/clang) for information on how to build it.
  - When you have acquired a build of the Clang fork, the binary must be placed inside the `tools/clang` directory in the repository before building.
 
## Configuring and Building

With the above-mentioned prerequisites installed, you may run the following in the root of the repository to configure with CMake:
```
mkdir build
cd build
cmake .. -G Ninja
```
After configuring, still in the build directory, you may run the CMake build command to build the project:
```
cmake --build .
```
If successful, there will be a generated `riivolution` directory in the build directory. The important files are `mkwcat-nsmbw.xml` and `mkwcat-nsmbw.arc`, both to be placed in the Riivolution XML directory.
