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
	std::cout << "Running plot_1 example" << std::endl;

	cxxplot::Kwargs args;
	args.add_kwarg("color", "r");
	args.add_kwarg("marker", "o");

	std::vector<std::vector<double>> x_double(10, std::vector<double>(10, 0));
	std::vector<std::vector<double>> y_double(10, std::vector<double>(10, 10));

	cxxplot::Plot<double> plot_double;
	plot_double.set_xlabel("x label");
	plot_double.set_ylabel("y label");

	for (unsigned long i = 0; i<10; i++) {
		for (unsigned long j = 0; j<x_double.size(); j++) {
			x_double[i][j] = static_cast<double>(j);
			y_double[i][j] += static_cast<double>(i);
		}
		plot_double.add_data(x_double[i], y_double[i], args);
	}

    plot_double.show();

	return 0;
}