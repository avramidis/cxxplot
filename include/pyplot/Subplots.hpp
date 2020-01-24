//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_SUBPLOTS_HPP
#define CXXPLOT_SUBPLOTS_HPP

#include "cxxplot_export.h"
#include "Matplotlib.hpp"

namespace cxxplot {
	class CXXPLOT_EXPORT Subplots : public Matplotlib {
	private:
		PyObject *subplots;
	public:
		Subplots();
		~Subplots();
		void initialize();
	};
}

#endif
