//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file License
//---------------------------------------------------------------------------//

#include "PythonInterpreter.hpp"
#include <Python.h>
#include <iostream>
#include <stdexcept>

namespace cxxplot {

    PythonInterpreter* PythonInterpreter::instance = nullptr;

    PythonInterpreter::PythonInterpreter()
    {
        Py_Initialize();
        if (Py_IsInitialized()==0) {
            throw std::runtime_error("Python3 interpreter could not be initialized!");
        }

        if (PyRun_SimpleString("import sys\n"
                               "sys.argv.append('')\n")==-1) {
            //"print(sys.argv)\n");
            throw std::runtime_error("Python3 interpreter could not import sys!");
        }
    }

    PythonInterpreter::~PythonInterpreter()
    {
        if (Py_FinalizeEx()<0) {
            PyErr_Print();
            std::cout << "Warning: Python interpreter could not be finalized!" << std::endl;
        }
    }

    PythonInterpreter*
    PythonInterpreter::getInstance()
    {
        if (!instance) {
            instance = new PythonInterpreter();
        }
        return new PythonInterpreter();
    }
}
