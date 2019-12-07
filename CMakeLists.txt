# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

project(cpppyplot
        VERSION 1.00
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

FIND_PACKAGE(Python3 COMPONENTS Development)
if (${Python3_FOUND})
    message(STATUS "PYTHON3 FOUND")
    message(STATUS ${Python3_INCLUDE_DIRS})
    message(STATUS ${Python3_LIBRARIES})
else ()
    message(FATAL_ERROR "PYTHON3 NOT FOUND")
endif ()

add_library(cpppyplot SHARED)
target_sources(cpppyplot PRIVATE
        source/Graph.cpp
        source/pyplot/Plot.cpp)
target_include_directories(cpppyplot PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${CMAKE_CURRENT_SOURCE_DIR}/include/pyplot
        ${Python3_INCLUDE_DIRS}
        ${CMAKE_BINARY_DIR})
target_link_libraries(cpppyplot PRIVATE ${Python3_LIBRARIES})

set_target_properties(cpppyplot PROPERTIES
        ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_definitions(cpppyplot PRIVATE cpppyplot_EXPORT)
endif ()

include(GenerateExportHeader)
generate_export_header(cpppyplot)

include(CMakePackageConfigHelpers)

write_basic_package_version_file(
        SomeProjConfigVersion.cmake
        VERSION 1.0.0
        COMPATIBILITY SameMajorVersion
)

#add_subdirectory(external)
add_subdirectory(examples)
#enable_testing()
#add_subdirectory(tests)

if (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/examples/cpppyplot.dll
            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:cpppyplot>" "$<TARGET_FILE_DIR:example_1>"
            VERBATIM)
    add_custom_target(copyddlexamples ALL
            DEPENDS ${CMAKE_BINARY_DIR}/examples/cpppyplot.dll cpppyplot
            VERBATIM)

    #    add_custom_command(OUTPUT ${CMAKE_BINARY_DIR}/tests/cpppyplot.dll
    #            COMMAND ${CMAKE_COMMAND} -E copy "$<TARGET_FILE:cpppyplot>" "$<TARGET_FILE_DIR:test_timer>"
    #            VERBATIM)
    #    add_custom_target(copyddltests ALL
    #            DEPENDS ${CMAKE_BINARY_DIR}/tests/Chronos.dll cpppyplot
    #            VERBATIM)
endif ()