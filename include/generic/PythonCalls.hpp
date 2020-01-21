//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_PYTHONCALLS_HPP
#define CXXPLOT_PYTHONCALLS_HPP

#include <Python.h>
#include "cxxplot_export.h"
#include <string>
#include <stdexcept>

namespace cxxplot {

    class CXXPLOT_EXPORT PythonCalls {
    public:
        [[nodiscard]] static PyObject *
        get_pyobject_module_by_string(const std::string &str);

        [[nodiscard]] static PyObject *
        get_pyobject_function_by_string(PyObject *parent_module, const std::string &str);

        [[nodiscard]] static void pyobject_call_with_checks(PyObject *object_to_call, PyObject *args, PyObject *kwargs);

        [[nodiscard]] static void pyobject_callobject_with_checks(PyObject *object_to_call);

        [[nodiscard]] static void pyobject_callobject_with_checks(PyObject *object_to_call, PyObject *args);
    };
}

#endif
