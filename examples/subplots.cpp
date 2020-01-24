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
	std::cout << "Running subplots example" << std::endl;

	cxxplot::Subplot subplots(2,1);

	std::vector<double> y_1{5.0, 3.2, 10.0, 12.4, 39.2};
	cxxplot::Plot<double> plot_1(y_1, false);
	plot_1.set_xlabel("x label");
	plot_1.set_ylabel("y label");

	subplots.set_subplot_index(2);
	std::vector<double> y_2{5.0*2, 3.2*2, 10.0*2, 12.4, 39.2};
	cxxplot::Plot<double> plot_2(y_2, false);
	plot_2.set_xlabel("x label");
	plot_2.set_ylabel("y label");
	plot_2.show_plot();

	return 0;
}