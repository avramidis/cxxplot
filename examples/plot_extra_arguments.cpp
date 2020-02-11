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
    std::cout << "Running plot_extra_arguments example" << std::endl;

    std::vector<double> y{5.0, 3.2, 10.0, 12.4, 39.2};
    cxxplot::Plot<double> plot_1(y);
    plot_1.set_xlabel("x label");
    plot_1.set_ylabel("y label");
    plot_1.show_plot();

    cxxplot::Plot<double> plot_2(y, "ro");
    plot_2.set_xlabel("x label");
    plot_2.set_ylabel("y label");
    plot_2.show_plot();

    cxxplot::Kwargs args;
    args.add_kwarg("color", "k");
    args.add_kwarg("marker", "+");
    std::vector<double> x{1.0, 2.0, 4, 6, 9};
    cxxplot::Plot<double> plot_3(x, y, args);
    plot_3.set_xlabel("x label");
    plot_3.set_ylabel("y label");
    plot_3.set_xlim(0, 12);
    plot_3.set_ylim(3, 60);
    plot_3.show_plot();

    return 0;
}