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
    source/msl/c/include
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
    -Wold-style-cast

    -Wno-out-of-line-declaration
    -Wno-gcc-compat
    -Wno-invalid-offsetof
    -Wno-frame-address
    -Wno-nested-anon-types
    -Wno-gnu-anonymous-struct
    -Wno-gnu-case-range
    -Wno-gnu-conditional-omitted-operand
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
    -fuse-ld=lld
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

set(MAKEREL "${CMAKE_SOURCE_DIR}/tools/make_rel.py")
set(WUJ5 "${CMAKE_SOURCE_DIR}/tools/wuj5/wuj5.py")
set(YAZ "${CMAKE_SOURCE_DIR}/tools/wuj5/yaz.py")
set(GENSMAP "${CMAKE_SOURCE_DIR}/tools/generate_symbol_map.py")
set(INSERTXML "${CMAKE_SOURCE_DIR}/tools/insert-xml.py")

set(BUILD_ARCHIVE "${CMAKE_BINARY_DIR}/mkwcat-nsmbw.arc.d")

set(imp_outputs)
set(imp_args)
foreach(region P1 P2 E1 E2 J1 J2 K W)
    set(imp_args "${imp_args}" "--imp" "${region}")
    set(imp_outputs "${imp_outputs}" "${CMAKE_BINARY_DIR}/source/d_project.rel.${region}.imp")
endforeach()
set(rel_file "${CMAKE_BINARY_DIR}/source/d_project.rel")
add_custom_command(OUTPUT ${rel_file} ${imp_outputs}
    DEPENDS tools project ${MAKEREL}
    COMMENT "Linking Wii relocatable module d_project.rel"
    COMMAND python ${MAKEREL} "${CMAKE_BINARY_DIR}/source/project${CMAKE_EXECUTABLE_SUFFIX}" "${rel_file}" "1835364215" "--address-map" "${CMAKE_SOURCE_DIR}/address-map.txt" ${imp_args}
)

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
        elseif("${out_name}" MATCHES "(\\.brlyt|\\.brlan)$" AND EXISTS ${src}.json5)
            add_custom_command(OUTPUT ${dst}
                DEPENDS "${src}.json5"
                COMMENT "Encoding ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory ${dst_directory}
                COMMAND python ${WUJ5} encode "${src}.json5" "--outputs=${dst}"
            )
        elseif("${out_name}" STREQUAL "rels/d_project.SMAP")
            add_custom_command(OUTPUT ${dst}
                DEPENDS project ${GENSMAP}
                COMMENT "Generating ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory ${dst_directory}
                COMMAND python ${GENSMAP} "${CMAKE_BINARY_DIR}/source/project${CMAKE_EXECUTABLE_SUFFIX}" "${dst}" "${MKWCAT_DOLPHIN_MAP_PATH}"
            )
        elseif("${out_name}" MATCHES "\\.szs$")
            string(REPLACE ".szs" "" src_name "${out_name}")
            if("${out_name}" STREQUAL "rels/d_project.rel.szs")
                set(src_name "${rel_file}")
            elseif("${out_name}" MATCHES "^rels/d_project_(P1|P2|E1|E2|J1|J2|K1|W1|C1)\\.imp\\.szs$")
                string(REGEX REPLACE "^rels/d_project_(P1|P2|E1|E2|J1|J2|K|W|C)1?\\.imp\\.szs$" "\\1" region "${out_name}")
                set(src_name "${CMAKE_BINARY_DIR}/source/d_project.rel.${region}.imp")
            elseif(NOT EXISTS "${CMAKE_SOURCE_DIR}/assets/${src_name}" AND EXISTS "${CMAKE_SOURCE_DIR}/assets/${src_name}.arc")
                set(src_name "${CMAKE_SOURCE_DIR}/assets/${src_name}.arc")
            else()
                set(src_name "${CMAKE_SOURCE_DIR}/assets/${src_name}")
            endif()
            add_custom_command(OUTPUT ${dst}
                DEPENDS tools "${src_name}"
                COMMENT "Compressing ${out_name}"
                COMMAND ${CMAKE_COMMAND} -E make_directory "${dst_directory}"
                COMMAND python ${YAZ} encode "${src_name}" "${dst}"
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
