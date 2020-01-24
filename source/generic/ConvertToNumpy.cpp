//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "generic/ConvertToNumpy.hpp"

namespace cxxplot {
	PyObject* ConvertToNumpy::covert_to_numpy_array(std::vector<int>& vector)
	{
		import_array();
		npy_intp dims = vector.size();
		PyObject* p_array = PyArray_SimpleNewFromData(
				1, &dims, NPY_INT, (void*) (vector.data()));
		return p_array;
	}

	PyObject* ConvertToNumpy::covert_to_numpy_array(std::vector<float>& vector)
	{
		import_array();
		npy_intp dims = vector.size();
		PyObject* p_array = PyArray_SimpleNewFromData(
				1, &dims, NPY_FLOAT, (void*) (vector.data()));
		return p_array;
	}

	PyObject* ConvertToNumpy::covert_to_numpy_array(std::vector<double>& vector)
	{
		import_array();
		npy_intp dims = vector.size();
		PyObject* p_array = PyArray_SimpleNewFromData(
				1, &dims, NPY_DOUBLE, (void*) (vector.data()));
		return p_array;
	}

	PyObject* ConvertToNumpy::vector_to_numpy(std::vector<int>& vector)
	{
		PyObject* p_array = covert_to_numpy_array(vector);
		if (!p_array)
			throw std::runtime_error("Could not convert vector to NumPy array!\n");
		return p_array;
	}

	PyObject* ConvertToNumpy::vector_to_numpy(std::vector<float>& vector)
	{
		PyObject* p_array = covert_to_numpy_array(vector);
		if (!p_array)
			throw std::runtime_error("Could not convert vector to NumPy array!\n");
		return p_array;
	}

	PyObject* ConvertToNumpy::vector_to_numpy(std::vector<double>& vector)
	{
		PyObject* p_array = covert_to_numpy_array(vector);
		if (!p_array)
			throw std::runtime_error("Could not convert vector to NumPy array!\n");
		return p_array;
	}
}