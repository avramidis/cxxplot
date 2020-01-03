//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE.txt
//---------------------------------------------------------------------------//

#include <iostream>
#include "pyplot/Plot.hpp"

int
main()
{
    std::cout << "Running example_1" << std::endl;

    std::vector<double> x{1.0, 2.0};
    std::vector<double> y{2.0, 3.0};

    std::vector<std::pair<std::string, std::string>> args;
    args.emplace_back("color", "r");
    args.emplace_back("marker", "o");

    cxxplot::Plot plot_1(x, y, args);
    plot_1.set_xlabel("x label");
    plot_1.set_ylabel("y label");
    plot_1.show_plot();

    return 0;
}