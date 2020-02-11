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
    std::cout << "Running save_plot_1 example" << std::endl;

    cxxplot::Kwargs args;
    args.add_kwarg("color", "r");
    args.add_kwarg("marker", "o");

    std::vector<int> x_int{1, 2};
    std::vector<int> y_int{2, 3};

    cxxplot::Plot<int> plot_int(x_int, y_int, args);
    plot_int.set_xlabel("x label");
    plot_int.set_ylabel("y label");
    plot_int.savefig("save_plot_1.svg");

    return 0;
}