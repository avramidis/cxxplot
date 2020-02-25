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
        PythonInterpreter::getInstance();

		matplotlib_pyplot = PythonCalls::get_pyobject_module_by_string("matplotlib.pyplot");
	}

	Matplotlib::~Matplotlib()
	{
        Py_DECREF(matplotlib_pyplot);
	}

	void Matplotlib::figure() {
		PyObject *figure = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "figure");
		PythonCalls::pyobject_callobject_with_checks(figure);
	}
}