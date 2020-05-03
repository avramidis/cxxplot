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

    Subplot::Subplot(int subplot_rows_count, int subplot_columns_count) {
        this->rows_count = subplot_rows_count;
        this->columns_count = subplot_columns_count;
        initialize();
    }

    Subplot::~Subplot() {}

    void Subplot::initialize() {
        subplots = PythonCalls::get_pyobject_function_by_string(
            this->matplotlib_pyplot, "subplot");
        set_subplot_index(1);
    }

    void Subplot::set_subplot_index(int index) {
        if (index <= 0 || index > rows_count * columns_count) {
            throw std::runtime_error("Subplot index out of bounds!!");
        }

        PyObject *args = PyTuple_New(3);
        PyTuple_SetItem(args, 0, Py_BuildValue("i", rows_count));
        PyTuple_SetItem(args, 1, Py_BuildValue("i", columns_count));
        PyTuple_SetItem(args, 2, Py_BuildValue("i", index));

        PythonCalls::pyobject_callobject_with_checks(subplots, args);
    }
} // namespace cxxplot
