//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include "Graph.hpp"
#include <iostream>

namespace cpppyplot {
    Graph::Graph()
    {
        Py_Initialize();
        PyRun_SimpleString("import sys\n"
                           "sys.argv.append('')\n"
                           "print(sys.argv)\n");

        matplotlib = PyImport_ImportModule("matplotlib.pyplot");
        Py_INCREF(matplotlib);
        if (matplotlib==NULL) {
            std::cout << "Error!" << std::endl;
        }

        std::cout << "Graph init done!" << std::endl;
    }

    Graph::~Graph()
    {
        Py_DECREF(matplotlib);
        if (Py_FinalizeEx()<0) {
            std::cout << "Error!" << std::endl;
        }

        std::cout << "Graph end done!" << std::endl;
    }
}