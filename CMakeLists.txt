cmake_minimum_required(VERSION 3.23)

set(CMAKE_SYSTEM_NAME "Generic")
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR powerpc-eabi)

if(NOT CLANG_DEFAULT)
    set(CLANG_DEFAULT "${CMAKE_CURRENT_SOURCE_DIR}/tools/clang/clang${CMAKE_HOST_EXECUTABLE_SUFFIX}")
endif()

# Use the default clang if it exists, otherwise fall back to whatever cmake has decided
if(EXISTS ${CLANG_DEFAULT})
    set(CMAKE_CXX_COMPILER ${CLANG_DEFAULT})
endif()

file(TO_CMAKE_PATH "$ENV{DEVKITPPC}" DEVKITPPC)
if(NOT DEVKITPPC)
    message(FATAL_ERROR "Please set DEVKITPPC in your environment")
endif()

# Specify the target triple as the custom platform
set(CMAKE_CXX_COMPILER_TARGET powerpc-eabi-kuribo)

set(OLD_CXX_FLAGS, ${CMAKE_CXX_FLAGS})
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} -c)

project(mkwcat-nsmbw LANGUAGES CXX)

set(CMAKE_EXECUTABLE_SUFFIX ".elf")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

set(CMAKE_CXX_FLAGS ${OLD_CXX_FLAGS})
set(CMAKE_CXX_LINK_FLAGS "")

include_directories(
    source
    source/msl/c
    source/msl/cpp
    source/wiimj2d
)

add_compile_options(
    -Os

    -fno-PIE
    -fno-PIC
    -fno-rtti
    -fno-strict-enums
    -fno-short-enums
    -fshort-wchar
    -fno-signed-char
    -fno-fast-math
    -fno-exceptions
    -fno-unwind-tables
    -fno-threadsafe-statics
    -fno-use-cxa-atexit
    -fcheck-new
    -fnew-alignment=4
    -fkeep-static-consts
    -femit-all-decls
    -fforce-emit-vtables
    -fno-virtual-function-elimination
    -fmerge-all-constants
    -ffreestanding
    -ffunction-sections
    -fdata-sections

    -nostdinc
    -nostdinc++

    -Wpedantic
    -Wall
    -Wextra

    -Wno-out-of-line-declaration
    -Wno-gcc-compat
    -Wno-invalid-offsetof
    -Wno-frame-address
    -Wno-nested-anon-types
    -Wno-gnu-anonymous-struct
    -Wno-gnu-case-range
    -Wno-c99-extensions
    -Wno-c++26-extensions
    -Wno-unused-private-field
    -Wno-unused-parameter
    -Wno-unused-const-variable
    -Wno-overloaded-virtual
    -Wno-sign-conversion
    -Wno-sign-compare
)

add_link_options(
    --prefix "${DEVKITPPC}/bin/powerpc-eabi-"
    -fuse-ld=ld
    -Wl,-n
    -Wl,--gc-sections
    -fno-exceptions
    -fno-PIE
    -fno-PIC
    -nostartfiles
    -nodefaultlibs
)

add_subdirectory(source)
add_subdirectory(loader)

include(ExternalProject)

ExternalProject_Add(
    tools
    PREFIX tools
    SOURCE_DIR "${CMAKE_SOURCE_DIR}/tools"
    BINARY_DIR "${CMAKE_BINARY_DIR}/tools"
    INSTALL_COMMAND ""
)

set(ELF2REL "${CMAKE_BINARY_DIR}/tools/elf2rel${CMAKE_HOST_EXECUTABLE_SUFFIX}")
set(LZX "${CMAKE_BINARY_DIR}/tools/lzx${CMAKE_HOST_EXECUTABLE_SUFFIX}")
set(WUJ5 "${CMAKE_SOURCE_DIR}/tools/wuj5/wuj5.py")
set(GENSMAP "${CMAKE_SOURCE_DIR}/tools/generate_symbol_map.py")
set(INSERTXML "${CMAKE_SOURCE_DIR}/tools/insert-xml.py")

set(BUILD_ARCHIVE "${CMAKE_BINARY_DIR}/mkwcat-nsmbw.arc.d")

foreach(region P1 P2 E1 E2 J1 J2 "K1;K" "W1;W" "C1;C")
    list(GET region 0 suffix)
    list(LENGTH region count)
    if(count EQUAL 2)
        list(GET region 1 region)
    endif()

    set(rel_file "${CMAKE_BINARY_DIR}/source/project_${suffix}.rel")
    add_custom_command(OUTPUT ${rel_file}
        DEPENDS tools project
        COMMENT "Linking Wii relocatable module project_${suffix}.rel"
        COMMAND ${ELF2REL} "${CMAKE_BINARY_DIR}/source/project${CMAKE_EXECUTABLE_SUFFIX}" "${rel_file}" ${region}
    )
endforeach()

add_subdirectory(assets)

set(DST_DVD_FILES)
foreach(out_name ${DVD_FILES})
    if(NOT "${out_name}" STREQUAL "")
        set(src "${CMAKE_SOURCE_DIR}/assets/${out_name}")
        set(dst "${BUILD_ARCHIVE}/${out_name}")
        get_filename_component(dst_directory ${dst} DIRECTORY)
        get_filename_component(dst_name ${dst} NAME)
        if(EXISTS ${src})
            add_custom_command(OUTPUT ${dst}
                DEPENDS ${src}
                COMMENT "Copying ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${dst_directory}"
                COMMAND ${CMAKE_COMMAND} -E copy "${src}" "${dst}"
            )
        elseif("${dst}" MATCHES "\\.rel\\.LZ$")
            string(REPLACE ".LZ" "" src_name "${dst_name}")
            add_custom_command(OUTPUT ${dst}
                DEPENDS tools "${CMAKE_BINARY_DIR}/source/${src_name}"
                COMMENT "Compressing ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${dst_directory}"
                COMMAND ${LZX} -ewb "${CMAKE_BINARY_DIR}/source/${src_name}" "${dst}"
            )
        elseif("${out_name}" MATCHES "(\\.brlyt|\\.brlan)$" AND EXISTS ${src}.json5)
            add_custom_command(OUTPUT ${dst}
                DEPENDS "${src}.json5"
                COMMENT "Encoding ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory ${dst_directory}
                COMMAND python ${WUJ5} encode "${src}.json5" "--outputs=${dst}"
            )
        elseif("${out_name}" STREQUAL "rels/project.SMAP")
            add_custom_command(OUTPUT ${dst}
                DEPENDS project ${GENSMAP}
                COMMENT "Generating ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory ${dst_directory}
                COMMAND python ${GENSMAP} "${CMAKE_BINARY_DIR}/source/project${CMAKE_EXECUTABLE_SUFFIX}" "${dst}" "${MKWCAT_DOLPHIN_MAP_PATH}"
            )
        elseif("${out_name}" MATCHES "\\.LZ$")
            string(REPLACE ".LZ" "" src_name "${out_name}")
            add_custom_command(OUTPUT ${dst}
                DEPENDS tools "${CMAKE_SOURCE_DIR}/assets/${src_name}"
                COMMENT "Compressing ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${dst_directory}"
                COMMAND ${LZX} -ewb "${CMAKE_SOURCE_DIR}/assets/${src_name}" "${dst}"
            )
        endif()
        list(APPEND DST_DVD_FILES ${dst})
    endif()
endforeach()

add_subdirectory(riivolution)

add_custom_target(mkwcat-nsmbw.arc
    ALL
    DEPENDS ${DST_DVD_FILES}
    COMMENT "Packing archive mkwcat-nsmbw.arc"
    COMMAND python ${WUJ5} encode "${BUILD_ARCHIVE}" "--output=${CMAKE_BINARY_DIR}/riivolution/mkwcat-nsmbw.arc"
)
