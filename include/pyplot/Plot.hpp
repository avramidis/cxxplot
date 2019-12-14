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

    public:
        Plot(std::vector<double>& x, std::vector<double>& y);
        Plot(std::vector<double>& x, std::vector<double>& y, std::vector<std::pair<std::string, std::string>>& args);
        ~Plot();

        void
        initialize();

        void
        draw(std::vector<double>& x, std::vector<double>& y);

        void
        draw(std::vector<double>& x, std::vector<double>& y, std::vector<std::pair<std::string, std::string>>& args);
    };
}

#endif
