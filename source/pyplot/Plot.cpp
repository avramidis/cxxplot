//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"

namespace cpppyplot {
    Plot::Plot() {
        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
        if (matplotlib == NULL) {
            //return -1;
        }
    }

    void Plot::draw() {
//        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
//        if (matplotlib == NULL) {
//            return -1;
//        }
//
//        plot = PyObject_GetAttrString(matplotlib, "plot");
//        if (plot == NULL)
//            return -2;
//
//        if (PyCallable_Check(plot)) {
//            std::cout << "Callable!" << std::endl;
//            PyObject_CallObject(plot, NULL);
//        } else {
//            std::cout << "Not callable!" << std::endl;
//            PyErr_Print();
//        }
//
//        show = PyObject_GetAttrString(matplotlib, "show");
//        if (show == NULL)
//            return -2;
//
//        if (PyCallable_Check(show)) {
//            std::cout << "Callable!" << std::endl;
//            PyObject_CallObject(show, NULL);
//        } else {
//            std::cout << "Not callable!" << std::endl;
//            PyErr_Print();
//        }
    }
}