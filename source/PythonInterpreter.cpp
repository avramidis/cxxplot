//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file License
//---------------------------------------------------------------------------//

#include "PythonInterpreter.hpp"
#include <Python.h>
#include <iostream>

namespace cxxplot {

    PythonInterpreter* PythonInterpreter::instance = nullptr;

    PythonInterpreter::PythonInterpreter() {
        Py_Initialize();
        PyRun_SimpleString("import sys\n"
                           "sys.argv.append('')\n");
        //"print(sys.argv)\n");
    }

    PythonInterpreter::~PythonInterpreter() {
        if (Py_FinalizeEx() < 0) {
            PyErr_Print();
            std::cout << "Warning: Python interpreter could not be finalized!" << std::endl;
        }
    }

    PythonInterpreter *PythonInterpreter::getInstance() {
        if (!instance) {
            instance = new PythonInterpreter();
        }
        return new PythonInterpreter();
    }
}
