//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_BAR_HPP
#define CXXPLOT_BAR_HPP

#include "cxxplot_export.h"
#include "pyplot/Pyplot.hpp"

namespace cxxplot {
    template <class inputType>
    class CXXPLOT_EXPORT Bar : public Pyplot<inputType> {
      private:
        PyObject *bar;

      public:
        explicit Bar(bool create_new_figure = true);
        explicit Bar(std::vector<inputType> &x, std::vector<inputType> &height,
                     bool create_new_figure = true);
        explicit Bar(std::vector<inputType> &x, std::vector<inputType> &height,
                     float width, std::vector<inputType> &bottom,
                     bool create_new_figure = true);
        ~Bar();

        void initialize();

        void draw(std::vector<inputType> &x, std::vector<inputType> &height);
        void draw(std::vector<inputType> &x, std::vector<inputType> &height, double width, std::vector<inputType> &bottom);

        PyObject *generate_args_pytuple(std::vector<inputType> &x,
                                        std::vector<inputType> &height);
        PyObject *generate_args_pytuple(std::vector<inputType> &x,
                                        std::vector<inputType> &height, double width,
                                        std::vector<inputType> &bottom);
        void
        add_data(std::vector<inputType> &x, std::vector<inputType> &height, double width = 0.8,
                 std::vector<inputType> &bottom = std::vector<inputType>());
    };
} // namespace cxxplot

#endif
