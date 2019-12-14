//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"
#include <stdexcept>

namespace cpppyplot {
    Plot::Plot(std::vector<double>& x, std::vector<double>& y)
    {
        initialize();
        draw(x, y);
    }

    Plot::Plot(std::vector<double>& x, std::vector<double>& y, std::vector<std::pair<std::string, std::string>>& args)
    {
        initialize();
        draw(x, y, args);
    }

    Plot::~Plot()
    {
        Py_DECREF(plot);
//        Py_DECREF(show);
    }

    void
    Plot::initialize()
    {
        plot = PyObject_GetAttrString(matplotlib, "plot");
        Py_INCREF(plot);
        if (plot==NULL) {
            PyErr_Print();
            throw std::runtime_error("Could not get plot attribute!\n");
        }
    }

    void
    Plot::draw(std::vector<double>& x, std::vector<double>& y)
    {
        if (PyCallable_Check(plot)) {
            PyObject* x_py = vector_2_numpy(x);
            PyObject* y_py = vector_2_numpy(y);

            PyObject* plot_args = PyTuple_New(2);
            PyTuple_SetItem(plot_args, 0, x_py);
            PyTuple_SetItem(plot_args, 1, y_py);

            PyObject* res = PyObject_CallObject(plot, plot_args);
            if (res) Py_DECREF(res);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("plot could not be called!\n");
        }

        show = PyObject_GetAttrString(matplotlib, "show");
        if (show==NULL)
            throw std::runtime_error("show string not be accessed!\n");

        if (PyCallable_Check(show)) {
            PyObject_CallObject(show, NULL);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("show could not be called!\n");
        }
    }

    void
    Plot::draw(std::vector<double>& x, std::vector<double>& y, std::vector<std::pair<std::string, std::string>>& args)
    {
        if (PyCallable_Check(plot)) {

            PyObject* kwargs = PyDict_New();
            for (auto& v:args) {
                PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
            }

            PyObject* x_py = vector_2_numpy(x);
            PyObject* y_py = vector_2_numpy(y);

            PyObject* plot_args = PyTuple_New(2);
            PyTuple_SetItem(plot_args, 0, x_py);
            PyTuple_SetItem(plot_args, 1, y_py);

            PyObject* res = PyObject_Call(plot, plot_args, kwargs);
            if (res) Py_DECREF(res);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("plot could not be called!\n");
        }

        show = PyObject_GetAttrString(matplotlib, "show");
        if (show==NULL)
            throw std::runtime_error("show string not be accessed!\n");

        if (PyCallable_Check(show)) {
            PyObject_CallObject(show, NULL);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("show could not be called!\n");
        }
    }
}