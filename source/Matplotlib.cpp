//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "Matplotlib.hpp"
#include "generic/convertToNumpy.hpp"
#include "generic/PythonCalls.hpp"
#include <iostream>
#include <stdexcept>
#include "PythonInterpreter.hpp"

namespace cxxplot {
    template<class inputType>
    Matplotlib<inputType>::Matplotlib() {
        PythonInterpreter *python_interpreter = PythonInterpreter::getInstance();

        matplotlib_pyplot = PythonCalls::get_pyobject_module_by_string("matplotlib.pyplot");
        numpy = PythonCalls::get_pyobject_module_by_string("numpy");
    }

    template<class inputType>
    Matplotlib<inputType>::~Matplotlib() {
    }

    template<class inputType>
    PyObject *
    Matplotlib<inputType>::vector_to_numpy(std::vector<inputType> &vector) {
        PyObject *p_array = covert_to_numpy_array(vector);

        if (!p_array)
            std::cout << "Error!" << std::endl;

        return p_array;
    }

    template
    class Matplotlib<int>;

    template
    class Matplotlib<float>;

    template
    class Matplotlib<double>;
}