# Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
#
# Distributed under The MIT License (MIT)
# See accompanying file LICENSE
#---------------------------------------------------------------------------//

file(DOWNLOAD https://github.com/catchorg/Catch2/releases/download/v2.11.1/catch.hpp ${CMAKE_CURRENT_BINARY_DIR}/catch.hpp)

function(ADD_TEST_EXE EXE_NAME SRC_NAME)
    message(STATUS "Generating ${EXE_NAME} target")

    add_executable(${EXE_NAME})
    target_sources(${EXE_NAME} PRIVATE ${SRC_NAME})

    target_include_directories(${EXE_NAME} PRIVATE ${CMAKE_CURRENT_BINARY_DIR})
    target_link_libraries(${EXE_NAME} PRIVATE cxxplot Python3::Python Python3::NumPy)

    set_target_properties(${EXE_NAME} PROPERTIES
            RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin/tests")
endfunction()

add_test_exe(test_python_interpreter test_python_interpreter.cpp)
add_test(NAME test_python_interpreter COMMAND test_python_interpreter)