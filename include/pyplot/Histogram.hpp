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
		explicit Histogram(std::vector<inputType>& x, int bins = 10);
		explicit Histogram(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args);
		~Histogram();

	private:
		void
		initialize();

		void
		draw(std::vector<inputType>& x, int bins = 10);

		void
		draw(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args);
		PyObject* generate_args_pytuple(std::vector<inputType>& x, int bins = 10);
	};
}

#endif
