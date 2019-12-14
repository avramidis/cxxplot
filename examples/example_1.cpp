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

//    cpppyplot::Graph graph_1;
//    std::vector<double> vector{1 ,2, 3, 4};
//    graph_1.vector_2_numpy(vector);

    std::vector<double> x{1.0, 2.0};
    std::vector<double> y{2.0, 3.0};

    std::vector<std::pair<std::string, std::string>> args;
    args.emplace_back("color", "r");
    args.emplace_back("marker", "o");

    cpppyplot::Plot plot_1(x, y, args);

    return 0;
}