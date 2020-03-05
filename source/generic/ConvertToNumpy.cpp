//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "generic/ConvertToNumpy.hpp"

namespace cxxplot {
    template <class inputType>
    PyObject *ConvertToNumpy<inputType>::covert_to_numpy_array(std::vector<inputType> &vector) {
        import_array();
        npy_intp dims = vector.size();
        PyObject *p_array =
            PyArray_SimpleNewFromData(1, &dims, ConvertToNumpy<inputType>::get_numpy_type(), (void *)(vector.data()));
        return p_array;
    }

    template <class inputType>
    PyObject *ConvertToNumpy<inputType>::vector_to_numpy(std::vector<inputType> &vector) {
        PyObject *p_array = covert_to_numpy_array(vector);
        if (!p_array)
            throw std::runtime_error("Could not convert vector to NumPy array!\n");
        return p_array;
    }

    template <>
    NPY_TYPES ConvertToNumpy<int>::get_numpy_type() {
        return NPY_INT;
    }
    template <>
    NPY_TYPES ConvertToNumpy<float>::get_numpy_type() {
        return NPY_FLOAT;
    }
    template <>
    NPY_TYPES ConvertToNumpy<double>::get_numpy_type() {
        return NPY_DOUBLE;
    }

    template ConvertToNumpy<int>;
    template ConvertToNumpy<float>;
    template ConvertToNumpy<double>;
} // namespace cxxplot