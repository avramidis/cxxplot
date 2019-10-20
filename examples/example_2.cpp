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
    PyObject *matplotlib, *cls, *cls2, *pValue;

    Py_Initialize();

    matplotlib = PyImport_ImportModule("time");
    if (matplotlib == NULL) {
        return -1;
    }

    cls = PyObject_GetAttrString(matplotlib, "time");
    if (cls == NULL)
        return -2;

    pValue = PyObject_CallObject(cls, 0);

    if (pValue != NULL) {
        printf("Result of call: %ld\n", PyLong_AsLong(pValue));
        Py_DECREF(pValue);
    }

    if (Py_FinalizeEx() < 0) {
        return 120;
    }
    return 0;
}