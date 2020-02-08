//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Axis.hpp"
#include "generic/PythonCalls.hpp"
#include <stdexcept>

namespace cxxplot {
    Axis::Axis()
    {
        initialize();
    }

    Axis::Axis(float xmin, float xmax, float ymin, float ymax)
    {
        initialize();

        PyObject* args = PyTuple_New(1);
        PyTuple_SetItem(args, 0, Py_BuildValue("ffff", xmin, xmax, ymin, ymax));

        PythonCalls::pyobject_callobject_with_checks(axis, args);
    }

    Axis::Axis(Axis_option option)
    {
        initialize();

        PyObject* args = PyTuple_New(1);
        PyTuple_SetItem(args, 0, Py_BuildValue("s", get_option_string_value(option)));

        PythonCalls::pyobject_callobject_with_checks(axis, args);
    }

    Axis::Axis(std::vector<std::pair<std::string, std::string>>& args)
    {
        initialize();

        PyObject *kwargs = PyDict_New();
        for (auto &v:args) {
            PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        PythonCalls::pyobject_call_with_checks(axis, NULL, kwargs);
    }

    Axis::~Axis()
    {

    }

    const char*
    Axis::get_option_string_value(Axis_option option)
    {
        switch (option) {
        case Axis_option::on  : return "on";
        case Axis_option::off  : return "off";
        case Axis_option::equal  : return "equal";
        case Axis_option::scaled  : return "scaled";
        case Axis_option::tight  : return "tight";
        case Axis_option::automatic  : return "automatic";
        case Axis_option::normal  : return "normal";
        case Axis_option::image  : return "image";
        case Axis_option::square  : return "square";
        }
    }

    void
    Axis::initialize()
    {
        axis = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "axis");
    }
}

