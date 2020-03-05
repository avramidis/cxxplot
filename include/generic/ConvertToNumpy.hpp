//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_CONVERTTONUMPY_HPP
#define CXXPLOT_CONVERTTONUMPY_HPP

#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include "cxxplot_export.h"
#include "numpy/arrayobject.h"
#include <Python.h>
#include <stdexcept>
#include <vector>

namespace cxxplot {

    class CXXPLOT_EXPORT ConvertToNumpy {
      public:
        [[nodiscard]] static PyObject *
        covert_to_numpy_array(std::vector<int> &vector);

        [[nodiscard]] static PyObject *
        covert_to_numpy_array(std::vector<float> &vector);

        [[nodiscard]] static PyObject *
        covert_to_numpy_array(std::vector<double> &vector);

        [[nodiscard]] static PyObject *
        vector_to_numpy(std::vector<int> &vector);

        [[nodiscard]] static PyObject *
        vector_to_numpy(std::vector<float> &vector);

        [[nodiscard]] static PyObject *
        vector_to_numpy(std::vector<double> &vector);
    };
} // namespace cxxplot

#endif
