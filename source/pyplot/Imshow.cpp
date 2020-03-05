//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Imshow.hpp"
#include "generic/ConvertToNumpy.hpp"
#include "generic/PythonCalls.hpp"

namespace cxxplot {
    template <class inputType>
    Imshow<inputType>::Imshow(bool create_new_figure) {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
    }

    template <class inputType>
    Imshow<inputType>::Imshow(std::vector<std::vector<inputType>> &x, bool create_new_figure) {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x);
    }

    template <class inputType>
    Imshow<inputType>::~Imshow() {
        Py_DECREF(imshow);
    }

    template <class inputType>
    void Imshow<inputType>::initialize() {
        imshow = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "imshow");
    }

    template <class inputType>
    void Imshow<inputType>::draw(std::vector<std::vector<inputType>> &x) {
        PyObject *args = generate_args_pytuple(x);

        PythonCalls::pyobject_callobject_with_checks(imshow, args);
    }

    template <class inputType>
    PyObject *Imshow<inputType>::generate_args_pytuple(std::vector<std::vector<inputType>> &x) {

        PyObject *x_py = ConvertToNumpy<inputType>::vector_to_numpy(x);

        PyObject *args = PyTuple_New(1);
        PyTuple_SetItem(args, 0, x_py);
        return args;
    }

    template class Imshow<int>;

    template class Imshow<float>;

    template class Imshow<double>;
} // namespace cxxplot
