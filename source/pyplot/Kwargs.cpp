//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Kwargs.hpp"
#include <stdexcept>
#include "Python.h"

namespace cxxplot {

    Kwargs::Kwargs() = default;

    Kwargs::~Kwargs() = default;

    void
    Kwargs::add_kwarg(const std::string& key, const std::string& item)
    {
        kwargs.emplace_back(key, item);
    }

    PyObject*
    Kwargs::get_pydict()
    {
        PyObject* kwargs_py = PyDict_New();
        for (auto& v:kwargs) {
            PyDict_SetItemString(kwargs_py, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        return kwargs_py;
    }
}

