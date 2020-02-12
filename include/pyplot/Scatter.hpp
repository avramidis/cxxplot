//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_SCATTER_HPP
#define CXXPLOT_SCATTER_HPP

#include "Pyplot.hpp"
#include "Kwargs.hpp"
#include <string>
#include <map>

namespace cxxplot {
	template<class inputType>
	class CXXPLOT_EXPORT Scatter : public Pyplot<inputType> {
	private:
		PyObject* scatter;

	public:
		Scatter();
		explicit Scatter(std::vector<inputType>& x, std::vector<inputType>& y);
		explicit Scatter(std::vector<inputType>& x, std::vector<inputType>& y, Kwargs& args);
		~Scatter();

	private:
		void
		initialize();

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y);

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y, Kwargs& args);

	};
}

#endif

