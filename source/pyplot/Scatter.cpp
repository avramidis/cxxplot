//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Scatter.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>
#include <iostream>

namespace cxxplot {
    template<class inputType>
    Scatter<inputType>::Scatter(std::vector<inputType> &x, std::vector<inputType> &y) {
        initialize();
        draw(x, y);
    }

    template<class inputType>
    Scatter<inputType>::Scatter(std::vector<inputType> &x, std::vector<inputType> &y,
                                std::vector<std::pair<std::string, std::string>> &args) {
        initialize();
        draw(x, y, args);
    }

    template<class inputType>
    Scatter<inputType>::~Scatter() {
        Py_DECREF(scatter);
    }

    template<class inputType>
    void
    Scatter<inputType>::initialize() {
        scatter = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "scatter");
    }

    template<class inputType>
    void
    Scatter<inputType>::draw(std::vector<inputType> &x, std::vector<inputType> &y) {
        PyObject *x_py = this->vector_to_numpy(x);
        PyObject *y_py = this->vector_to_numpy(y);

        PyObject *scatter_args = PyTuple_New(2);
        PyTuple_SetItem(scatter_args, 0, x_py);
        PyTuple_SetItem(scatter_args, 1, y_py);

        PyObject *result = PyObject_CallObject(scatter, scatter_args);
        if (result == NULL)
            throw std::runtime_error("scatter could not be called!\n");
        Py_DECREF(result);
    }

    template<class inputType>
    void
    Scatter<inputType>::draw(std::vector<inputType> &x, std::vector<inputType> &y,
                             std::vector<std::pair<std::string, std::string>> &args) {
        PyObject *kwargs = PyDict_New();
        for (auto &v:args) {
            PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        PyObject *x_py = this->vector_to_numpy(x);
        PyObject *y_py = this->vector_to_numpy(y);

        PyObject *scatter_args = PyTuple_New(2);
        PyTuple_SetItem(scatter_args, 0, x_py);
        PyTuple_SetItem(scatter_args, 1, y_py);

        PyObject *result = PyObject_Call(scatter, scatter_args, kwargs);
        if (result == NULL)
            throw std::runtime_error("scatter could not be called!\n");
        Py_DECREF(result);
    }

    template
    class Scatter<int>;

    template
    class Scatter<float>;

    template
    class Scatter<double>;
}