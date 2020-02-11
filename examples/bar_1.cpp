//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include <iostream>
#include "cxxplot.hpp"

int
main()
{
    std::cout << "Running bar_1 example" << std::endl;

    std::vector<std::pair<std::string, std::string>> args;
    args.emplace_back("color", "r");
    args.emplace_back("marker", "o");

    std::vector<double> x{1, 2, 3, 4};
    std::vector<double> height{1, 2, 3, 4};

    cxxplot::Bar<double> bar(x, height);
    bar.add_data(x, height, 0.8, height);
    bar.show_plot();

    return 0;
}