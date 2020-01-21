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
	std::cout << "Running plot_block example" << std::endl;

	std::vector<std::pair<std::string, std::string>> args;
	args.emplace_back("color", "r");
	args.emplace_back("marker", "o");

    std::vector<double> x_double{1.0, 2.0};
    std::vector<double> y_double{5.0, 3.0};

    cxxplot::Plot<double> plot_double(x_double, y_double, args);
    plot_double.set_xlabel("x label");
    plot_double.set_ylabel("y label");
	plot_double.set_xlim(-10, 10);
	plot_double.set_ylim(0, 8);
    plot_double.show_plot(false);

    cxxplot::Pyplot<float> pyplot;
    pyplot.figure();

    std::vector<float> x_float{1.0, 2.0};
    std::vector<float> y_float{2.0, 3.0};

    cxxplot::Plot<float> plot_float(x_float, y_float, args);
    plot_float.set_xlabel("x label");
    plot_float.set_ylabel("y label");
    plot_float.show_plot();

	return 0;
}