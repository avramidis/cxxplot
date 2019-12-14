//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

namespace cxxplot {
    Graph::Graph()
    {
        Py_SetProgramName(reinterpret_cast<const wchar_t*>("cxxpyplot"));
        Py_Initialize();
        PyRun_SimpleString("import sys\n"
                           "sys.argv.append('')\n"
                           "print(sys.argv)\n");

        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
        Py_INCREF(matplotlib);
        if (matplotlib==NULL) {
            PyErr_Print();
            throw std::runtime_error("matplotlib.pyplot could not be imported!\n");
        }

        numpy = PyImport_ImportModule("numpy");
        Py_INCREF(numpy);
        if (numpy==NULL) {
            PyErr_Print();
            throw std::runtime_error("numpy could not be imported!\n");
        }
    }

    Graph::~Graph()
    {
        Py_DECREF(matplotlib);
        if (Py_FinalizeEx()<0) {
            PyErr_Print();
            std::cout << "Warning: Python interpreter could not be finalized!" << std::endl;
        }
    }

    PyObject*
    Graph::vector_2_numpy(std::vector<double>& vector)
    {
        import_array();

        npy_intp dims = vector.size();

        // Convert it to a NumPy array.
        PyObject* p_array = PyArray_SimpleNewFromData(
                1, &dims, NPY_DOUBLE, (void*) (vector.data()));
        if (!p_array)
            std::cout << "Error!" << std::endl;

        return p_array;
    }
}