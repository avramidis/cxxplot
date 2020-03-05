//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_KWARGS_HPP
#define CXXPLOT_KWARGS_HPP

#include "Matplotlib.hpp"
#include "cxxplot_export.h"
#include <string>
#include <vector>

namespace cxxplot {

    class Kwargs : public Matplotlib {
      private:
        std::vector<std::pair<std::string, std::string>> kwargs;

      public:
        CXXPLOT_EXPORT Kwargs();
        CXXPLOT_EXPORT ~Kwargs();
        void CXXPLOT_EXPORT add_kwarg(const std::string &key,
                                      const std::string &item);
        CXXPLOT_EXPORT PyObject *get_pydict();
    };
} // namespace cxxplot

#endif
