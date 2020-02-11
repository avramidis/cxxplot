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
    std::cout << "Running axis_1 example" << std::endl;

    cxxplot::Kwargs args;
    args.add_kwarg("color", "r");
    args.add_kwarg("marker", "o");

    std::vector<double> x{1.0, 2.0};
    std::vector<double> y{5.0, 3.0};

    cxxplot::Plot<double> plot(x, y, args);
    plot.set_xlabel("x label");
    plot.set_ylabel("y label");
    plot.set_xlim(-10, 10);
    plot.set_ylim(0, 8);

    //cxxplot::Axis axis(cxxplot::Axis_option::square);
    cxxplot::Axis axis(0, 100, 0, 100);

    plot.show_plot();

    return 0;
}