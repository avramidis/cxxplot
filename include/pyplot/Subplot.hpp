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
        int rows_count, columns_count;

      public:
        Subplot(int subplot_rows_count, int subplot_columns_count);
        ~Subplot();
        void initialize();
        void set_subplot_index(int index);
    };
} // namespace cxxplot

#endif
