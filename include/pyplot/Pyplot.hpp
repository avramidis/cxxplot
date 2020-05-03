//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_PYPLOT_HPP
#define CXXPLOT_PYPLOT_HPP

#include "Matplotlib.hpp"
#include <map>
#include <stdexcept>
#include <string>

namespace cxxplot {
    template <class inputType> class CXXPLOT_EXPORT Pyplot : public Matplotlib {
      public:
        PyObject *xlabel;
        PyObject *ylabel;
        PyObject *show_py_object;

        Pyplot() = default;

        ~Pyplot() = default;

        void set_xlabel(std::string const &label,
                        std::map<std::string, std::string> const &args = {});

        void set_ylabel(std::string const &label,
                        std::map<std::string, std::string> const &args = {});

        void show(bool blocked = true);

        void savefig(std::string const &fname);

        void set_xlim(double x_min, double x_max);
        void set_ylim(double y_min, double y_max);

      private:
        void set_x_or_y_lim(double min_value, double max_value,
                            std::string lim_type);
    };
} // namespace cxxplot

#endif