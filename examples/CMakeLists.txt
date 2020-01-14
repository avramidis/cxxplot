# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)
add_executable(plot_1)
target_sources(plot_1 PRIVATE plot_1.cpp)
target_link_libraries(plot_1 PRIVATE cxxplot Python3::Python Python3::NumPy)

add_executable(example_2)
target_sources(example_2 PRIVATE example_2.cpp)
target_link_libraries(example_2 PRIVATE cxxplot Python3::Python Python3::NumPy)

add_executable(example_3)
target_sources(example_3 PRIVATE example_3.cpp)
target_link_libraries(example_3 PRIVATE cxxplot Python3::Python Python3::NumPy)

set_target_properties(example_1 example_2 example_3 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")