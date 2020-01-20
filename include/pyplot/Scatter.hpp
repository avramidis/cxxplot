//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_SCATTER_HPP
#define CXXPLOT_SCATTER_HPP

#include "Pyplot.hpp"
#include <string>
#include <map>

namespace cxxplot {
	template<class inputType>
	class CXXPLOT_EXPORT Scatter : public Pyplot<inputType> {
	private:
		PyObject* scatter;

	public:
		explicit Scatter(std::vector<inputType>& x, std::vector<inputType>& y);
		explicit Scatter(std::vector<inputType>& x, std::vector<inputType>& y,
				std::vector<std::pair<std::string, std::string>>& args);
		~Scatter();

	private:
		void
		initialize();

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y);

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y,
				std::vector<std::pair<std::string, std::string>>& args);

	};
}

#endif

