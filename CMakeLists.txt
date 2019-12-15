# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

project(cxxplot
        DESCRIPTION "C++ plot library.")

set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU")
    message(STATUS "USING OPTIONS FOR GNU COMPILER")
    set(MY_DEBUG_OPTIONS "-O0;-g;-Wall;-Wextra;-Wpedantic")
    set(MY_RELEASE_OPTIONS "-O3;-Wall;-Wextra;-Wpedantic")
endif ()

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    message(STATUS "USING OPTIONS FOR MSVC COMPILER")
    set(MY_DEBUG_OPTIONS "/Wall /wd4710")
    set(MY_RELEASE_OPTIONS "/Wall;/wd4710;/wd4711;/wd4514")
endif ()

add_compile_options("$<$<CONFIG:DEBUG>:${MY_DEBUG_OPTIONS}>")
add_compile_options("$<$<CONFIG:RELEASE>:${MY_RELEASE_OPTIONS}>")

include(dependencies/CMakeLists.txt)
add_subdirectory(source)

include(GenerateExportHeader)
generate_export_header(cxxplot)

include(CMakePackageConfigHelpers)
write_basic_package_version_file(
        cxxplotConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

add_subdirectory(examples)
#add_subdirectory(tests)



