//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Pyplot.hpp"

namespace cxxplot {

    template<class inputType>
    Pyplot<inputType>::Pyplot() { };

    template<class inputType>
    Pyplot<inputType>::~Pyplot() { };

    template<class inputType>
    void
    Pyplot<inputType>::set_xlabel(std::string const& label, std::map<std::string, std::string> const& args)
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

    template<class inputType>
    void
    Pyplot<inputType>::set_ylabel(std::string const& label, std::map<std::string, std::string> const& args)
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

    template<class inputType>
    void
    Pyplot<inputType>::show_plot()
    {
        show = PyObject_GetAttrString(matplotlib_pyplot, "show");
        if (show==NULL)
            throw std::runtime_error("show string not be accessed!\n");

        if (PyCallable_Check(show)) {
            PyObject* res = PyObject_CallObject(show, NULL);
            if (res) Py_DECREF(res);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("show could not be called!\n");
        }
    }

    template<class inputType>
    void
    Pyplot<inputType>::savefig(std::string const& fname)
    {
        PyObject* savefig = PyObject_GetAttrString(matplotlib_pyplot, "savefig");
        if (PyCallable_Check(savefig)) {
            PyObject* py_fname = PyUnicode_FromString(fname.c_str());

            PyObject* savefig_args = PyTuple_New(1);
            PyTuple_SetItem(savefig_args, 0, py_fname);

            PyObject* kwargs = PyDict_New();
            PyObject_Call(savefig, savefig_args, kwargs);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("savefig could not be called!\n");
        }
    }

    template class Pyplot<int>;
    template class Pyplot<float>;
    template class Pyplot<double>;
}
