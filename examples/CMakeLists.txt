# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

add_executable(example_1)
target_sources(example_1 PRIVATE example_1.cpp)
target_include_directories(example_1 PRIVATE ${CMAKE_SOURCE_DIR}/include ${Python3_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})
target_link_libraries(example_1 PRIVATE cpppyplot ${Python3_LIBRARIES})

add_executable(example_2)
target_sources(example_2 PRIVATE example_2.cpp)
target_include_directories(example_2 PRIVATE ${CMAKE_SOURCE_DIR}/include ${Python3_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})
target_link_libraries(example_2 PRIVATE cpppyplot ${Python3_LIBRARIES})

add_executable(example_3)
target_sources(example_3 PRIVATE example_3.cpp)
target_include_directories(example_3 PRIVATE ${CMAKE_SOURCE_DIR}/include ${Python3_INCLUDE_DIRS} ${CMAKE_BINARY_DIR})
target_link_libraries(example_3 PRIVATE cpppyplot ${Python3_LIBRARIES})

set_target_properties(example_1 example_2 example_3 PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")