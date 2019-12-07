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
#include "cpppyplot_export.h"

namespace cpppyplot {

    class CPPPYPLOT_EXPORT Graph {
    public:
        PyObject *matplotlib;

        Graph();

        ~Graph();
    };
}

#endif //CPPPYPLOT_GRAPH_HPP