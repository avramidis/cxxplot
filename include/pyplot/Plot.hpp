//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Graph.hpp"
#include "Pyplot.hpp"
#include <string>
#include <map>

namespace cxxplot {
	class CXXPLOT_EXPORT Plot : public Pyplot {
	private:
		PyObject* plot;

	public:
		explicit Plot(std::vector<double>& x, std::vector<double>& y);
		explicit Plot(std::vector<double>& x, std::vector<double>& y,
				std::vector<std::pair<std::string, std::string>>& args);
		~Plot();

	private:
		void
		initialize();

		void
		draw(std::vector<double>& x, std::vector<double>& y);

		void
		draw(std::vector<double>& x, std::vector<double>& y,
				std::vector<std::pair<std::string, std::string>>& args);

	};
}

#endif
