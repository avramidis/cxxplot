//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Pyplot.hpp"

namespace cxxplot {

	Pyplot::Pyplot() { };

	Pyplot::~Pyplot() { };

	void
	Pyplot::set_xlabel(std::string const& label, std::map<std::string, std::string> const& args)
	{
		xlabel = PyObject_GetAttrString(matplotlib_pyplot, "xlabel");
		if (PyCallable_Check(xlabel)) {
			PyObject* py_label = PyUnicode_FromString(label.c_str());

			PyObject* label_args = PyTuple_New(1);
			PyTuple_SetItem(label_args, 0, py_label);

			PyObject* kwargs = PyDict_New();
			for (auto const& v:args) {
				PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
			}

			PyObject_Call(xlabel, label_args, kwargs);
		}
		else {
			PyErr_Print();
			throw std::runtime_error("xlabel could not be called!\n");
		}
	}

	void
	Pyplot::set_ylabel(std::string const& label, std::map<std::string, std::string> const& args)
	{
		ylabel = PyObject_GetAttrString(matplotlib_pyplot, "ylabel");
		if (PyCallable_Check(ylabel)) {
			PyObject* py_label = PyUnicode_FromString(label.c_str());

			PyObject* label_args = PyTuple_New(1);
			PyTuple_SetItem(label_args, 0, py_label);

			PyObject* kwargs = PyDict_New();
			for (auto const& v:args) {
				PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
			}

			PyObject_Call(ylabel, label_args, kwargs);
		}
		else {
			PyErr_Print();
			throw std::runtime_error("ylabel could not be called!\n");
		}
	}
}
