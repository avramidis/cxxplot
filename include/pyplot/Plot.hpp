//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Pyplot.hpp"
#include <string>
#include <map>

namespace cxxplot {
    template<class inputType>
    class CXXPLOT_EXPORT Plot : public Pyplot<inputType> {
    private:
        PyObject* plot;

    public:
        explicit Plot(std::vector<inputType>& x, std::vector<inputType>& y);
        explicit Plot(std::vector<inputType>& x, std::vector<inputType>& y,
                std::vector<std::pair<std::string, std::string>>& args);
        ~Plot();

    private:
        void
        initialize();

        void
        draw(std::vector<inputType>& x, std::vector<inputType>& y);

        void
        draw(std::vector<inputType>& x, std::vector<inputType>& y,
                std::vector<std::pair<std::string, std::string>>& args);

    };
}

#endif
