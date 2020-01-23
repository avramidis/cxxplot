//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>

namespace cxxplot {
    template<class inputType>
    Plot<inputType>::Plot(std::vector<inputType> &x, std::vector<inputType> &y) {
        initialize();
        draw(x, y);
    }

    template<class inputType>
    Plot<inputType>::Plot(std::vector<inputType> &x, std::vector<inputType> &y,
                          std::vector<std::pair<std::string, std::string>> &args) {
    	this->figure();
        initialize();
        draw(x, y, args);
    }

    template<class inputType>
    Plot<inputType>::~Plot() {
        Py_DECREF(plot);
    }

    template<class inputType>
    void
    Plot<inputType>::initialize() {
        plot = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "plot");
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType> &x, std::vector<inputType> &y) {
        PyObject *x_py = this->vector_to_numpy(x);
        PyObject *y_py = this->vector_to_numpy(y);

        PyObject *plot_args = PyTuple_New(2);
        PyTuple_SetItem(plot_args, 0, x_py);
        PyTuple_SetItem(plot_args, 1, y_py);

        PythonCalls::pyobject_callobject_with_checks(plot, plot_args);
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType> &x, std::vector<inputType> &y,
                          std::vector<std::pair<std::string, std::string>> &args) {
        PyObject *kwargs = PyDict_New();
        for (auto &v:args) {
            PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        PyObject *x_py = this->vector_to_numpy(x);
        PyObject *y_py = this->vector_to_numpy(y);

        PyObject *plot_args = PyTuple_New(2);
        PyTuple_SetItem(plot_args, 0, x_py);
        PyTuple_SetItem(plot_args, 1, y_py);

        PythonCalls::pyobject_call_with_checks(plot, plot_args, kwargs);
    }

    template
    class Plot<int>;

    template
    class Plot<float>;

    template
    class Plot<double>;
}