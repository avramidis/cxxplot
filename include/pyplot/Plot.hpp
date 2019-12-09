//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Graph.hpp"
#include <string>

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
        draw(std::vector<double> &x, std::vector<double> &y, std::vector<std::pair<std::string, std::string>> &args);
    };
}

#endif //CPPPYPLOT_PLOT_HPP
