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
        npy_intp dims = static_cast<npy_intp>(vector.size());
        PyObject *p_array = PyArray_SimpleNewFromData(1, &dims, ConvertToNumpy<inputType>::get_numpy_type(),
                                                      reinterpret_cast<void *>(vector.data()));
        return p_array;
    }

    template <class inputType>
    PyObject *ConvertToNumpy<inputType>::covert_to_numpy_array(std::vector<std::vector<inputType>> &vector) {
        import_array();

        npy_intp dims[2] = {static_cast<npy_intp>(vector.size()), static_cast<npy_intp>(vector[0].size())};

        inputType *array_data = new inputType[static_cast<unsigned long>(dims[0] * dims[1])];
        for (long i = 0; i < dims[0]; i++) {
            for (long j = 0; j < dims[1]; j++) {
                array_data[static_cast<unsigned long>(i) * static_cast<unsigned long>(dims[0]) +
                           static_cast<unsigned long>(j)] =
                    vector[static_cast<unsigned long>(i)][static_cast<unsigned long>(j)];
            }
        }

        PyObject *p_array = PyArray_SimpleNewFromData(2, dims, ConvertToNumpy<inputType>::get_numpy_type(),
                                                      reinterpret_cast<void *>(array_data));
        return p_array;
    }

    template <class inputType>
    PyObject *ConvertToNumpy<inputType>::vector_to_numpy(std::vector<inputType> &vector) {
        PyObject *p_array = covert_to_numpy_array(vector);
        if (!p_array)
            throw std::runtime_error("Could not convert vector to NumPy array!\n");
        return p_array;
    }

    template <class inputType>
    PyObject *ConvertToNumpy<inputType>::vector_to_numpy(std::vector<std::vector<inputType>> &vector) {
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

    template class ConvertToNumpy<int>;
    template class ConvertToNumpy<float>;
    template class ConvertToNumpy<double>;
} // namespace cxxplot