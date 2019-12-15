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
#include "cxxplot_export.h"
#include <vector>
#include <string>

namespace cxxplot {

    class Graph {
    public:
        PyObject* matplotlib_pyplot;
        PyObject* numpy;

        Graph();

        ~Graph();

        virtual void
        draw(std::vector<double>& x, std::vector<double>& y) = 0;

        virtual void
        draw(std::vector<double>& x, std::vector<double>& y,
                std::vector<std::pair<std::string, std::string>>& args) = 0;

        PyObject*
        vector_2_numpy(std::vector<double>& vector);
    };
}

#endif
