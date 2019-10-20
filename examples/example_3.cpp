//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#define PY_SSIZE_T_CLEAN

#include <Python.h>

#include <iostream>

int
main(int argc, char *argv[]) {
    PyObject *matplotlib, *plot, *show, *show_fun, *pValue;

    Py_Initialize();
    PyRun_SimpleString("import sys\n"
                       "sys.argv.append('')\n"
                       "print(sys.argv)\n");

    matplotlib = PyImport_ImportModule("matplotlib.pyplot");
    if (matplotlib == NULL) {
        return -1;
    }

    plot = PyObject_GetAttrString(matplotlib, "plot");
    if (plot == NULL)
        return -2;

    if (PyCallable_Check(plot))
    {
        std::cout << "Callable!" << std::endl;
        PyObject_CallObject(plot, NULL);
    } else
    {
        std::cout << "Not callable!" << std::endl;
        PyErr_Print();
    }

    show = PyObject_GetAttrString(matplotlib, "show");
    if (show == NULL)
        return -2;

    if (PyCallable_Check(show))
    {
        std::cout << "Callable!" << std::endl;
        PyObject_CallObject(show, NULL);
    } else
    {
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

    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}