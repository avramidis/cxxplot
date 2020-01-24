//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "Matplotlib.hpp"
#include "generic/PythonCalls.hpp"
#include <iostream>
#include <stdexcept>
#include "PythonInterpreter.hpp"

namespace cxxplot {
	Matplotlib::Matplotlib()
	{
		PythonInterpreter* python_interpreter = PythonInterpreter::getInstance();

		matplotlib_pyplot = PythonCalls::get_pyobject_module_by_string("matplotlib.pyplot");
		numpy = PythonCalls::get_pyobject_module_by_string("numpy");
	}

	Matplotlib::~Matplotlib()
	{
	}
}