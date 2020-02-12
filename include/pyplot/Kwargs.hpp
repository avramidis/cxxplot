//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_KWARGS_HPP
#define CXXPLOT_KWARGS_HPP

#include "cxxplot_export.h"
#include <vector>
#include <string>
#include "Matplotlib.hpp"

namespace cxxplot {

    class CXXPLOT_EXPORT Kwargs : public Matplotlib {
    private:
        std::vector<std::pair<std::string, std::string>> kwargs;

    public:
        Kwargs();
        ~Kwargs();
        void
        add_kwarg(const std::string& key, const std::string& item);
        PyObject*
        get_pydict();
    };
}

#endif
