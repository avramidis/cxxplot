//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Bar.hpp"
#include "generic/ConvertToNumpy.hpp"
#include "generic/PythonCalls.hpp"

namespace cxxplot {

    template <class inputType> Bar<inputType>::Bar(bool create_new_figure) {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
    }

    template <class inputType>
    Bar<inputType>::Bar(std::vector<inputType> &x,
                        std::vector<inputType> &height,
                        bool create_new_figure) {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x, height);
    }

    template <class inputType>
    Bar<inputType>::Bar(std::vector<inputType> &x,
                        std::vector<inputType> &height, float width,
                        std::vector<inputType> &bottom,
                        bool create_new_figure) {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x, height, width, bottom);
    }

    template <class inputType> Bar<inputType>::~Bar() {
        Py_DECREF(bar);
    }

    template <class inputType> void Bar<inputType>::initialize() {
        bar = PythonCalls::get_pyobject_function_by_string(
            this->matplotlib_pyplot, "bar");
    }

    template <class inputType>
    void Bar<inputType>::add_data(std::vector<inputType> &x,
                                  std::vector<inputType> &height, double width,
                                  std::vector<inputType> &bottom) {
        draw(x, height, width, bottom);
    }

    template <class inputType>
    void Bar<inputType>::draw(std::vector<inputType> &x,
                              std::vector<inputType> &height) {
        PyObject *args = generate_args_pytuple(x, height);

        PythonCalls::pyobject_callobject_with_checks(bar, args);
    }

    template <class inputType>
    void Bar<inputType>::draw(std::vector<inputType> &x,
                              std::vector<inputType> &height, double width,
                              std::vector<inputType> &bottom) {
        PyObject *args = generate_args_pytuple(x, height, width, bottom);

        PythonCalls::pyobject_callobject_with_checks(bar, args);
    }

    template <class inputType>
    PyObject *
    Bar<inputType>::generate_args_pytuple(std::vector<inputType> &x,
                                          std::vector<inputType> &height) {
        PyObject *x_py = ConvertToNumpy<inputType>::vector_to_numpy(x);
        PyObject *height_py = ConvertToNumpy<inputType>::vector_to_numpy(height);

        PyObject *args = PyTuple_New(2);
        PyTuple_SetItem(args, 0, x_py);
        PyTuple_SetItem(args, 1, height_py);
        return args;
    }

    template <class inputType>
    PyObject *Bar<inputType>::generate_args_pytuple(
        std::vector<inputType> &x, std::vector<inputType> &height,
                                                    double width,
        std::vector<inputType> &bottom) {
        PyObject *x_py = ConvertToNumpy<inputType>::vector_to_numpy(x);
        PyObject *height_py = ConvertToNumpy<inputType>::vector_to_numpy(height);
        PyObject *bottom_py = ConvertToNumpy<inputType>::vector_to_numpy(bottom);

        PyObject *args = PyTuple_New(4);
        PyTuple_SetItem(args, 0, x_py);
        PyTuple_SetItem(args, 1, height_py);
        PyTuple_SetItem(args, 2, Py_BuildValue("f", width));
        PyTuple_SetItem(args, 3, bottom_py);

        return args;
    }

    template class Bar<int>;

    template class Bar<float>;

    template class Bar<double>;
} // namespace cxxplot