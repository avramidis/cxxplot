# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

#include(ExternalProject)
#ExternalProject_Add(pybind11
#        GIT_REPOSITORY git@github.com:pybind/pybind11.git
#        GIT_TAG v2.4.2
#        INSTALL_DIR ${CMAKE_BINARY_DIR}
#        SOURCE_DIR "${CMAKE_CURRENT_BINARY_DIR}/pybind11-src"
#        BINARY_DIR "${CMAKE_CURRENT_BINARY_DIR}/pybind11-build"
#        STEP_TARGETS build
#        INSTALL_COMMAND ""
#        )