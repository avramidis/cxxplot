//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_PYTHONCALLS_HPP
#define CXXPLOT_PYTHONCALLS_HPP

#include "cxxplot_export.h"
#include <Python.h>
#include <stdexcept>
#include <string>

namespace cxxplot {

    class CXXPLOT_EXPORT PythonCalls {
      public:
        [[nodiscard]] static PyObject *
        get_pyobject_module_by_string(const std::string &str);

        [[nodiscard]] static PyObject *
        get_pyobject_function_by_string(PyObject *parent_module,
                                        const std::string &str);

        static void pyobject_call_with_checks(PyObject *object_to_call,
                                              PyObject *args, PyObject *kwargs);

        static void pyobject_callobject_with_checks(PyObject *object_to_call);

        static void pyobject_callobject_with_checks(PyObject *object_to_call,
                                                    PyObject *args);
    };
} // namespace cxxplot

#endif
