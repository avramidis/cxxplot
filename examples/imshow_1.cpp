//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "cxxplot.hpp"
#include <iostream>

int main() {
    std::cout << "Running imshow_1 example" << std::endl;

    std::vector<std::vector<double>> x_float{{10, 20, 12}, {1, 2, 5}};

    cxxplot::Imshow<double> imshow_float(x_float);

    imshow_float.show();

    return 0;
}