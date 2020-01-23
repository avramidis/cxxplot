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

	std::vector<std::pair<std::string, std::string>> args_1;
	args_1.emplace_back("color", "r");
	args_1.emplace_back("marker", "o");

	std::vector<int> x_int_1{1, 2};
	std::vector<int> y_int_1{2, 3};

	cxxplot::Plot<int> plot_int(x_int_1, y_int_1, args_1);
	plot_int.set_xlabel("x label");
	plot_int.set_ylabel("y label");

	std::vector<std::pair<std::string, std::string>> args_2;
	args_2.emplace_back("color", "k");
	args_2.emplace_back("marker", ".");

	std::vector<int> x_int_2{1, 2};
	std::vector<int> y_int_2{0, 4};

	plot_int.add_data(x_int_2, y_int_2, args_2);

	plot_int.show_plot();

	return 0;
}