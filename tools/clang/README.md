### Clang

My custom fork of Clang for compatibility with the PowerPC CodeWarrior ABI, developed at [mkwcat/llvm-project release-19-with-cw](https://github.com/mkwcat/llvm-project/tree/release-19-with-cw).

Credit to [JoshuaMK](https://github.com/JoshuaMKW) and [CyrusTheHedgehog](https://github.com/CyrusTheHedgehog) for most of the work getting Clang compatible with CodeWarrior! My fork is a fork of their work.

The CMakeLists.txt in this directory should be adequate for automatically downloading and building this version of Clang with the right settings. Use it with the following:
```
mkdir build
cmake ..
cmake --build .
```
It should take a while to download and build. Once completed, find the `clang` executable and copy it into this directory (`tools/clang`).
