//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_PYPLOT_HPP
#define CXXPLOT_PYPLOT_HPP

#include "Python.h"
#include "Matplotlib.hpp"
#include "pyplot/Pyplot.hpp"
#include <map>
#include <string>
#include <stdexcept>

namespace cxxplot {
    template<class inputType>
	class CXXPLOT_EXPORT Pyplot : public Matplotlib<inputType> {
	public:
		PyObject* xlabel;
		PyObject* ylabel;
		PyObject* show;

		Pyplot();

		~Pyplot();

		void
		set_xlabel(std::string const& label, std::map<std::string, std::string> const& args = {});

		void
		set_ylabel(std::string const& label, std::map<std::string, std::string> const& args = {});

		void
		show_plot();
	};
}

#endif
