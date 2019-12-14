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

namespace cxxplot {
    class CXXPLOT_EXPORT Plot : Graph {
    private:
        PyObject* plot;
        PyObject* show;

    public:
        explicit Plot(std::vector<double>& x, std::vector<double>& y);
        explicit Plot(std::vector<double>& x, std::vector<double>& y,
                std::vector<std::pair<std::string, std::string>>& args);
        ~Plot();

        void
        initialize();

        void
        draw(std::vector<double>& x, std::vector<double>& y) override;

        void
        draw(std::vector<double>& x, std::vector<double>& y,
                std::vector<std::pair<std::string, std::string>>& args) override;
    };
}

#endif
