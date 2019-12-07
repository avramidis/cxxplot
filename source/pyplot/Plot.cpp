//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"
#include <stdexcept>
#include <iostream>

namespace cpppyplot {
    Plot::Plot() {


    }

    Plot::~Plot() {
        delete plot;
        delete show;
        delete show_fun;
        delete pValue;
    }

    int Plot::draw() {

        plot = PyObject_GetAttrString(matplotlib, "plot");
        if (plot == NULL)
            return -2;

        if (PyCallable_Check(plot)) {
            std::cout << "Callable!" << std::endl;

            int arg = 123;
            arglist = Py_BuildValue("(1)", arg);
            PyObject_CallObject(plot, arglist);
        } else {
            std::cout << "Not callable!" << std::endl;
            PyErr_Print();
        }

        show = PyObject_GetAttrString(matplotlib, "show");
        if (show == NULL)
            return -2;

        if (PyCallable_Check(show)) {
            std::cout << "Callable!" << std::endl;
            PyObject_CallObject(show, NULL);
        } else {
            std::cout << "Not callable!" << std::endl;
            PyErr_Print();
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