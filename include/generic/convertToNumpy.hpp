//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_CONVERTTONUMPY_HPP
#define CXXPLOT_CONVERTTONUMPY_HPP

#include <Python.h>
#include "numpy/arrayobject.h"
#include <vector>

namespace cxxplot {

    PyObject*
    covert_to_numpy_array(std::vector<int> &vector)
    {
        import_array();
        npy_intp dims = vector.size();
        PyObject* p_array = PyArray_SimpleNewFromData(
                1, &dims, NPY_INT, (void*) (vector.data()));
        return p_array;
    }

    PyObject*
    covert_to_numpy_array(std::vector<float> &vector)
    {
        import_array();
        npy_intp dims = vector.size();
        PyObject* p_array = PyArray_SimpleNewFromData(
                1, &dims, NPY_FLOAT, (void*) (vector.data()));
        return p_array;
    }

    PyObject*
    covert_to_numpy_array(std::vector<double> &vector)
    {
        import_array();
        npy_intp dims = vector.size();
        PyObject* p_array = PyArray_SimpleNewFromData(
                1, &dims, NPY_DOUBLE, (void*) (vector.data()));
        return p_array;
    }
}

#endif
