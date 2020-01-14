//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Matplotlib.hpp"
#include "generic/convertToNumpy.hpp"
#include <iostream>
#include <stdexcept>

namespace cxxplot {
    template<class inputType>
    Matplotlib<inputType>::Matplotlib()
    {
        Py_Initialize();
        PyRun_SimpleString("import sys\n"
                           "sys.argv.append('')\n");
        //"print(sys.argv)\n");

        matplotlib_pyplot = PyImport_ImportModule("matplotlib.pyplot");
        if (matplotlib_pyplot==NULL) {
            PyErr_Print();
            throw std::runtime_error("matplotlib.pyplot could not be imported!\n");
        }
        else {
            Py_INCREF(matplotlib_pyplot);
        }

        numpy = PyImport_ImportModule("numpy");
        Py_INCREF(numpy);
        if (numpy==NULL) {
            PyErr_Print();
            throw std::runtime_error("numpy could not be imported!\n");
        }
    }

    template<class inputType>
    Matplotlib<inputType>::~Matplotlib()
    {
        Py_DECREF(matplotlib_pyplot);
        if (Py_FinalizeEx()<0) {
            PyErr_Print();
            std::cout << "Warning: Python interpreter could not be finalized!" << std::endl;
        }
    }

    template<class inputType>
    PyObject*
    Matplotlib<inputType>::vector_to_numpy(std::vector<inputType>& vector)
    {
        PyObject* p_array = covert_to_numpy_array(vector);

        if (!p_array)
            std::cout << "Error!" << std::endl;

        return p_array;
    }

    template class Matplotlib<int>;
    template class Matplotlib<float>;
    template class Matplotlib<double>;
}