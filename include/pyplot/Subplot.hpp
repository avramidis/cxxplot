//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_SUBPLOT_HPP
#define CXXPLOT_SUBPLOT_HPP

#include "Matplotlib.hpp"
#include "cxxplot_export.h"

namespace cxxplot {
    class CXXPLOT_EXPORT Subplot : public Matplotlib {
      private:
        PyObject *subplots;
        int number_rows, number_columns;

      public:
        Subplot(int number_rows, int number_columns);
        ~Subplot();
        void initialize();
        void set_subplot_index(int index);
    };
} // namespace cxxplot

#endif
