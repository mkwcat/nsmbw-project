cmake_minimum_required(VERSION 3.23)

project(tools LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(elf2rel
    elf2rel/elf2rel.cpp
)

target_include_directories(elf2rel PUBLIC
    ${CMAKE_SOURCE_DIR}/elf2rel
)

target_compile_options(elf2rel PRIVATE
    $<$<COMPILE_LANG_AND_ID:CXX,GNU,Clang,AppleClang>:-O3>
)
