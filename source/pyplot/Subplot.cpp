//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Subplot.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>

namespace cxxplot {

    Subplot::Subplot(int number_rows, int number_columns) {
        this->number_rows = number_rows;
        this->number_columns = number_columns;
        initialize();
    }

    Subplot::~Subplot() {}

    void Subplot::initialize() {
        subplots = PythonCalls::get_pyobject_function_by_string(
            this->matplotlib_pyplot, "subplot");
        set_subplot_index(1);
    }

    void Subplot::set_subplot_index(int index) {
        if (index <= 0 || index > number_rows * number_columns) {
            throw std::runtime_error("Subplot index out of bounds!!");
        }

        PyObject *args = PyTuple_New(3);
        PyTuple_SetItem(args, 0, Py_BuildValue("i", number_rows));
        PyTuple_SetItem(args, 1, Py_BuildValue("i", number_columns));
        PyTuple_SetItem(args, 2, Py_BuildValue("i", index));

        PythonCalls::pyobject_callobject_with_checks(subplots, args);
    }
} // namespace cxxplot
