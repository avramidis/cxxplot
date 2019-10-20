//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Graph.hpp"
#include "ddldefines.hpp"

namespace cpppyplot {
    class CPPPLOT_EXPORT Plot : Graph {
    private:
        PyObject *matplotlib, *plot, *show, *show_fun, *pValue;
    public:
        Plot();

        void draw();
    };
}

#endif //CPPPYPLOT_PLOT_HPP
