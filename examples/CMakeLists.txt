# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE.txt
#---------------------------------------------------------------------------//

cmake_minimum_required(VERSION 3.15.3)

function(SIMPLE EXE_NAME SRC_NAME)
    message(STATUS "Generating ${EXE_NAME} target")

    add_executable(${EXE_NAME})
    target_sources(${EXE_NAME} PRIVATE ${SRC_NAME})

    target_include_directories(${EXE_NAME} PRIVATE ${Python3_INCLUDE_DIRS} ${Python3_NumPy_INCLUDE_DIRS})
    target_link_libraries(${EXE_NAME} PRIVATE cxxplot Python3::Python Python3::NumPy)

    set_target_properties(${EXE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")

endfunction()


simple(plot_1 plot_1.cpp)
simple(save_plot_1 save_plot_1.cpp)