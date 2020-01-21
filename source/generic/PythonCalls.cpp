//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "generic/PythonCalls.hpp"

namespace cxxplot {

    [[nodiscard]] PyObject*
    PythonCalls::get_pyobject_module_by_string(const std::string& str)
    {
        PyObject* py_object = PyImport_ImportModule(str.c_str());
        if (py_object==NULL) {
            PyErr_Print();
            throw std::runtime_error(str+" could not be imported!\n");
        }
        else {
            Py_INCREF(py_object);
            return py_object;
        }
    }

    [[nodiscard]] PyObject*
    PythonCalls::get_pyobject_function_by_string(PyObject* parent_module, const std::string& str)
    {
        PyObject* py_object = PyObject_GetAttrString(parent_module, str.c_str());
        if (PyCallable_Check(py_object)) {
            return py_object;
        }
        else {
            PyErr_Print();
            throw std::runtime_error(str+" could not be called!\n");
        }
    }
}

