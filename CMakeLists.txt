# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

project(cxxplot
        VERSION 0.0.1
        DESCRIPTION "C++ plot library."
        HOMEPAGE_URL "https://github.com/avramidis/cxxplot")

# Set default visibility to hidden for all targets
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN YES)

# Project dependencies
include(cmake/ProjectDependencies.cmake)

# Project settings
include(cmake/StandardProjectSettings.cmake)
add_library(cxxplot_project_options INTERFACE)
target_compile_features(cxxplot_project_options INTERFACE cxx_std_17)

# Standard compiler warnings
add_library(cxxplot_project_warnings INTERFACE)
include(cmake/CompilerWarnings.cmake)
set_project_warnings(cxxplot_project_warnings)

add_subdirectory(source)
include(GenerateExportHeader)
generate_export_header(cxxplot)

option(CXXPLOT_ENABLE_EXAMPLES "Enable examples" OFF)
option(CXXPLOT_ENABLE_TESTS "Enable tests" OFF)

if (CXXPLOT_ENABLE_EXAMPLES)
    add_subdirectory(examples)
endif ()

if (CXXPLOT_ENABLE_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif ()
