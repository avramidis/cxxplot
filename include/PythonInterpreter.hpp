//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file License
//---------------------------------------------------------------------------//

#ifndef CXXPLOT_PYTHONINTERPRETER_HPP
#define CXXPLOT_PYTHONINTERPRETER_HPP

#include "cxxplot_export.h"

namespace cxxplot {

    class PythonInterpreter;

    class CXXPLOT_EXPORT PythonInterpreter {
    private:
        static PythonInterpreter *instance;

        PythonInterpreter();

    public:
        static PythonInterpreter *getInstance();

        ~PythonInterpreter();
    };
}

#endif //CXXPLOT_PYTHONINTERPRETER_HPP