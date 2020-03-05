//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_IMSHOW_HPP
#define CXXPLOT_IMSHOW_HPP

#include "cxxplot_export.h"
#include "pyplot/Pyplot.hpp"

namespace cxxplot {
    template <class inputType>
    class CXXPLOT_EXPORT Imshow : public Pyplot<inputType> {
      private:
        PyObject *imshow;

      public:
        explicit Imshow(bool create_new_figure = true);
        explicit Imshow(std::vector<std::vector<inputType>> &x, bool create_new_figure = true);

        ~Imshow();

        void initialize();

        void draw(std::vector<std::vector<inputType>> &x);

        PyObject *generate_args_pytuple(std::vector<std::vector<inputType>> &x);
    };
} // namespace cxxplot
#endif
