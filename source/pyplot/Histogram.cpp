//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Histogram.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>

namespace cxxplot {

	template<class inputType>
	Histogram<inputType>::Histogram()
	{
		this->figure();
		initialize();
	}

	template<class inputType>
	Histogram<inputType>::Histogram(std::vector<inputType>& x)
	{
		this->figure();
		initialize();
		draw(x);
	}

	template<class inputType>
	Histogram<inputType>::Histogram(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args)
	{
		this->figure();
		initialize();
		draw(x, args);
	}

	template<class inputType>
	Histogram<inputType>::~Histogram()
	{
		Py_DECREF(histogram);
	}

	template<class inputType>
	void
	Histogram<inputType>::initialize()
	{
		histogram = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "hist");
	}

	template<class inputType>
	void
	Histogram<inputType>::draw(std::vector<inputType>& x)
	{
		PyObject* x_py = this->vector_to_numpy(x);

		PyObject* plot_args = PyTuple_New(1);
		PyTuple_SetItem(plot_args, 0, x_py);

		PythonCalls::pyobject_callobject_with_checks(histogram, plot_args);
	}

	template<class inputType>
	void
	Histogram<inputType>::draw(std::vector<inputType>& x, std::vector<std::pair<std::string, std::string>>& args)
	{
		PyObject* kwargs = PyDict_New();
		for (auto& v:args) {
			PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
		}

		PyObject* x_py = this->vector_to_numpy(x);

		PyObject* histogram_args = PyTuple_New(1);
		PyTuple_SetItem(histogram_args, 0, x_py);

		PythonCalls::pyobject_call_with_checks(histogram, histogram_args, kwargs);
	}

	template
	class Histogram<int>;

	template
	class Histogram<float>;

	template
	class Histogram<double>;
}