//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Pyplot.hpp"
#include "generic/PythonCalls.hpp"

namespace cxxplot {

    template<class inputType>
    Pyplot<inputType>::Pyplot() { };

    template<class inputType>
    Pyplot<inputType>::~Pyplot() { };

    template<class inputType>
    void
    Pyplot<inputType>::set_xlabel(std::string const& label, std::map<std::string, std::string> const& args)
    {
        xlabel = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "xlabel");

        PyObject* py_label = PyUnicode_FromString(label.c_str());

        PyObject* label_args = PyTuple_New(1);
        PyTuple_SetItem(label_args, 0, py_label);

        PyObject* kwargs = PyDict_New();
        for (auto const& v:args) {
            PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        PyObject_Call(xlabel, label_args, kwargs);
    }

    template<class inputType>
    void
    Pyplot<inputType>::set_ylabel(std::string const& label, std::map<std::string, std::string> const& args)
    {
        ylabel = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "ylabel");

        PyObject* py_label = PyUnicode_FromString(label.c_str());

        PyObject* label_args = PyTuple_New(1);
        PyTuple_SetItem(label_args, 0, py_label);

        PyObject* kwargs = PyDict_New();
        for (auto const& v:args) {
            PyDict_SetItemString(kwargs, v.first.c_str(), PyUnicode_FromString(v.second.c_str()));
        }

        PyObject_Call(ylabel, label_args, kwargs);

    }

    template<class inputType>
    void
    Pyplot<inputType>::show_plot()
    {
        show = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "show");

        PyObject* res = PyObject_CallObject(show, NULL);
        if (res) Py_DECREF(res);
    }

    template<class inputType>
    void
    Pyplot<inputType>::savefig(std::string const& fname)
    {
        PyObject* savefig = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "savefig");

        PyObject* py_fname = PyUnicode_FromString(fname.c_str());

        PyObject* savefig_args = PyTuple_New(1);
        PyTuple_SetItem(savefig_args, 0, py_fname);

        PyObject* kwargs = PyDict_New();
        PyObject_Call(savefig, savefig_args, kwargs);
    }

    template class Pyplot<int>;
    template class Pyplot<float>;
    template class Pyplot<double>;
}
