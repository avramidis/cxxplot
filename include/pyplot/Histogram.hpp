//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_HISTOGRAM_HPP
#define CXXPLOT_HISTOGRAM_HPP

#include "Pyplot.hpp"

namespace cxxplot {

	template<class inputType>
	class CXXPLOT_EXPORT Histogram : public Pyplot<inputType> {
	private:
		PyObject* histogram;

	public:
		Histogram();
		explicit Histogram(std::vector<inputType>& x);
		explicit Histogram(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args);
		~Histogram();

	private:
		void
		initialize();

		void
		draw(std::vector<inputType>& x);

		void
		draw(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args);
	};
}

#endif
