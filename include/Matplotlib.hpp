//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_MATPLOTLIB_HPP
#define CPPPYPLOT_MATPLOTLIB_HPP

#define PY_SSIZE_T_CLEAN
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION

#include "cxxplot_export.h"
#include <Python.h>
#include <string>
#include <vector>

namespace cxxplot {
    class CXXPLOT_EXPORT Matplotlib {
      public:
        PyObject *matplotlib_pyplot;

        Matplotlib();

        ~Matplotlib();

        void figure();
    };
} // namespace cxxplot

#endif
