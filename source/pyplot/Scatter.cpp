//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Scatter.hpp"
#include "generic/ConvertToNumpy.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>

namespace cxxplot {

    template <class inputType> Scatter<inputType>::Scatter() {
        this->figure();
        initialize();
    }

    template <class inputType>
    Scatter<inputType>::Scatter(std::vector<inputType> &x,
                                std::vector<inputType> &y) {
        this->figure();
        initialize();
        draw(x, y);
    }

    template <class inputType>
    Scatter<inputType>::Scatter(std::vector<inputType> &x,
                                std::vector<inputType> &y, Kwargs &args) {
        this->figure();
        initialize();
        draw(x, y, args);
    }

    template <class inputType> Scatter<inputType>::~Scatter() {
        Py_DECREF(scatter);
    }

    template <class inputType> void Scatter<inputType>::initialize() {
        scatter = PythonCalls::get_pyobject_function_by_string(
            this->matplotlib_pyplot, "scatter");
    }

    template <class inputType>
    void Scatter<inputType>::draw(std::vector<inputType> &x,
                                  std::vector<inputType> &y) {
        PyObject *x_py = ConvertToNumpy<inputType>::vector_to_numpy(x);
        PyObject *y_py = ConvertToNumpy<inputType>::vector_to_numpy(y);

        PyObject *scatter_args = PyTuple_New(2);
        PyTuple_SetItem(scatter_args, 0, x_py);
        PyTuple_SetItem(scatter_args, 1, y_py);

        PythonCalls::pyobject_callobject_with_checks(scatter, scatter_args);
    }

    template <class inputType>
    void Scatter<inputType>::draw(std::vector<inputType> &x,
                                  std::vector<inputType> &y, Kwargs &args) {
        PyObject *x_py = ConvertToNumpy<inputType>::vector_to_numpy(x);
        PyObject *y_py = ConvertToNumpy<inputType>::vector_to_numpy(y);

        PyObject *scatter_args = PyTuple_New(2);
        PyTuple_SetItem(scatter_args, 0, x_py);
        PyTuple_SetItem(scatter_args, 1, y_py);

        PythonCalls::pyobject_call_with_checks(scatter, scatter_args,
                                               args.get_pydict());
    }

    template class Scatter<int>;

    template class Scatter<float>;

    template class Scatter<double>;
} // namespace cxxplot