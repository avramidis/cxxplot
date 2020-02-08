//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file License
//---------------------------------------------------------------------------//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "PythonInterpreter.hpp"

TEST_CASE("Test Python3 interpreter")
{
    SECTION("Load Python3 interpreter") {
        REQUIRE_NOTHROW(cxxplot::PythonInterpreter::getInstance());
    }
}