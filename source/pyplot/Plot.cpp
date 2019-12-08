//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"
#include <iostream>
#include <stdexcept>
#include <numpy/arrayobject.h>

namespace cpppyplot {
    Plot::Plot()
    {
        plot = PyObject_GetAttrString(matplotlib, "plot");
        Py_INCREF(plot);
        if (plot==NULL) {
            PyErr_Print();
            throw std::runtime_error("Could not get plot attribute!\n");
        }
    }

    Plot::~Plot()
    {
        Py_DECREF(plot);
//        Py_DECREF(show);
//        Py_DECREF(show_fun);
//        Py_DECREF(pValue);
    }

    int
    Plot::draw()
    {
        if(PyArray_API == NULL)
        {
            import_array();
        }

        if (PyCallable_Check(plot)) {
            std::cout << "Callable!" << std::endl;

            PyObject* kwargs = PyDict_New();

            std::vector<double> x_vector{1.0, 2.0};
            std::vector<double> y_vector{2.0, 3.0};
            PyObject* x = vector_2_numpy(x_vector);
            PyObject* y = vector_2_numpy(y_vector);

            PyObject* plot_args = PyTuple_New(2);
            PyTuple_SetItem(plot_args, 0, x);
            PyTuple_SetItem(plot_args, 1, y);

//            arglist = Py_BuildValue("(i)", 100);
            PyObject* res = PyObject_Call(plot, plot_args, kwargs);
            if (res) Py_DECREF(res);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("plot could not be called!\n");
        }

        show = PyObject_GetAttrString(matplotlib, "show");
        if (show==NULL)
            return -2;

        if (PyCallable_Check(show)) {
            std::cout << "Callable!" << std::endl;
            PyObject_CallObject(show, NULL);
        }
        else {
            PyErr_Print();
            throw std::runtime_error("show could not be called!\n");
        }


//    show = PyObject_Call(plot, NULL, NULL);
//    if (show == NULL)
//        return -2;

//    show_fun = PyObject_Call(show, NULL, NULL);
//
//    if (show_fun != NULL) {
//       std::cout << "Worked!" << std::endl;
//    }

//        Py_Initialize();
//        PyRun_SimpleString("import sys\n"
//                           "sys.argv.append('')\n"
//                           "print(sys.argv)\n");
//
//        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
//        std::cout << matplotlib->ob_type << std::endl;
//        if (matplotlib == NULL) {
//            throw std::runtime_error("Error: Cannot import matplotlib.pyplot!\n");
//        }
//
//        plot = PyObject_GetAttrString(matplotlib, "plot");
//        if (plot == NULL) {
//            throw std::runtime_error("Error: Cannot import matplotlib!\n");
//        }
//
//        if (PyCallable_Check(plot)) {
//            PyObject_CallObject(plot, NULL);
//        } else {
//            PyErr_Print();
//            throw std::runtime_error("Error: matplotlib.pyplot.plot is not callable!\n");
//        }
//
//        show = PyObject_GetAttrString(matplotlib, "show");
//        if (show == NULL) {
//            throw std::runtime_error("Error: Cannot import show!\n");
//        }
//
//        if (PyCallable_Check(show)) {
//            std::cout << "Callable!" << std::endl;
//            PyObject_CallObject(show, NULL);
//            throw std::runtime_error("Error: show is not callable!\n");
//        } else {
//            std::cout << "Not callable!" << std::endl;
//            PyErr_Print();
//        }
//
////        if (Py_FinalizeEx() < 0) {
////            std::cout << "Cannot Py_FinalizeEx()!" << std::endl;
//////            throw std::runtime_error("Error: Cannot finalize Python interpreter!\n");
////        }
//
//        if (Py_FinalizeEx() < 0) {
//
//        }




//        Py_Initialize();
//        PyRun_SimpleString("import sys\n"
//                           "sys.argv.append('')\n"
//                           "print(sys.argv)\n");
//
//        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
//        if (matplotlib == NULL) {
//            std::cout << "Problem" << std::endl;
//        }
//
//        plot = PyObject_GetAttrString(matplotlib, "plot");
//        if (plot == NULL) {
//            std::cout << "Problem" << std::endl;
//        }
//
//        if (PyCallable_Check(plot))
//        {
//            std::cout << "plot is Callable!" << std::endl;
//            PyObject * result = PyObject_CallObject(plot, NULL);
//            if (result == NULL) {
//                std::cout << "failed to call plot!" << std::endl;
//            }
//        } else
//        {
//            std::cout << "plot is Not callable!" << std::endl;
//            PyErr_Print();
//        }
//
//        show = PyObject_GetAttrString(matplotlib, "show");
//        if (show == NULL)
//
//
//        if (PyCallable_Check(show))
//        {
//            std::cout << "show is Callable!" << std::endl;
//            PyObject_CallObject(show, NULL);
//        } else
//        {
//            std::cout << "show is Not callable!" << std::endl;
//            PyErr_Print();
//        }


//    show = PyObject_Call(plot, NULL, NULL);
//    if (show == NULL)
//        return -2;

//    show_fun = PyObject_Call(show, NULL, NULL);
//
//    if (show_fun != NULL) {
//       std::cout << "Worked!" << std::endl;
//    }
    }
}