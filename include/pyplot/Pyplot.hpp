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

		void figure();

		void
		set_xlabel(std::string const& label, std::map<std::string, std::string> const& args = {});

		void
		set_ylabel(std::string const& label, std::map<std::string, std::string> const& args = {});

		void
		show_plot(bool blocked=true);

		void
		savefig(std::string const& fname);

		void set_xlim(double x_min, double x_max);
		void set_ylim(double y_min, double y_max);

	private:
		void set_x_or_y_lim(double min_value, double max_value, std::string lim_type);
	};
}

#endif