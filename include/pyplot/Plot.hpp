//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Graph.hpp"

namespace cpppyplot {
    class CPPPYPLOT_EXPORT Plot : Graph {
    private:
        PyObject* plot;
        PyObject* show;
        PyObject* show_fun;
        PyObject* pValue;
        PyObject* arglist;
        
    public:
        Plot();
        ~Plot();

        int
        draw();
    };
}

#endif //CPPPYPLOT_PLOT_HPP
