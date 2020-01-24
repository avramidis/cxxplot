//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Subplots.hpp"
#include "generic/PythonCalls.hpp"

namespace cxxplot {

	Subplots::Subplots()
	{
		this->figure();
		initialize();
	}

	Subplots::~Subplots()
	{

	}

	void Subplots::initialize()
	{
		subplots = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "subplots");
	}
}
