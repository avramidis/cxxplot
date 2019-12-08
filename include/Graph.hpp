//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_GRAPH_HPP
#define CPPPYPLOT_GRAPH_HPP

#define PY_SSIZE_T_CLEAN

#include <Python.h>
#include "numpy/arrayobject.h"
#include "cpppyplot_export.h"
#include <vector>

namespace cpppyplot {

    class CPPPYPLOT_EXPORT Graph {
    public:
        PyObject* matplotlib;
        PyObject* numpy;

        Graph();

        ~Graph();

        PyObject*
        vector_2_numpy(std::vector<double> &vector);
    };
}

#endif //CPPPYPLOT_GRAPH_HPP
