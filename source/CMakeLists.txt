add_executable(project "")

target_compile_options(project PRIVATE
    -include System.h
    -fstack-protector-strong
)

target_link_options(project PRIVATE
    -T "${CMAKE_SOURCE_DIR}/source/Module.ld"
    -r
    -Wl,--force-group-allocation
)

file(GLOB_RECURSE C_SOURCE_FILES "${CMAKE_SOURCE_DIR}/*.c")
set_source_files_properties(${C_SOURCE_FILES} PROPERTIES LANGUAGE CXX)

target_sources(project PRIVATE
# Note: Uppercase letters are always sorted before lowercase

# Root source files
    Module.cpp
    Four.cpp
)

add_subdirectory(wiimj2d)
add_subdirectory(revolution)
add_subdirectory(nw4r)
add_subdirectory(egg)
add_subdirectory(msl)
