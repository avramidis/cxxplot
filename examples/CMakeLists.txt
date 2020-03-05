# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE
#---------------------------------------------------------------------------//

function(ADD_EXAMPLE EXE_NAME SRC_NAME)
    message(STATUS "Generating ${EXE_NAME} target")

    add_executable(${EXE_NAME})
    target_sources(${EXE_NAME} PRIVATE ${SRC_NAME})

    target_link_libraries(${EXE_NAME} PRIVATE cxxplot cxxplot_project_options cxxplot_project_warnings Python3::Python Python3::NumPy)

    set_target_properties(${EXE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/examples")
endfunction()


add_example(plot_1 plot_1.cpp)
add_example(scatter_1 scatter_1.cpp)
add_example(save_plot_1 save_plot_1.cpp)
add_example(plot_block plot_block.cpp)
add_example(plot_add_extra_data plot_add_extra_data.cpp)
add_example(plot_add_data_in_loop plot_add_data_in_loop.cpp)
add_example(histogram_1 histogram_1.cpp)
add_example(plot_extra_arguments plot_extra_arguments.cpp)
add_example(subplots subplots.cpp)
add_example(axis_1 axis_1.cpp)
add_example(bar_1 bar_1.cpp)
add_example(imshow_1 imshow_1.cpp)