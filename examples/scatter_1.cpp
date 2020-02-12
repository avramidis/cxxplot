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
	std::cout << "Running scatter_1 example" << std::endl;

	std::vector<std::pair<std::string, std::string>> args;
	args.emplace_back("color", "r");
	args.emplace_back("marker", "o");

	std::vector<int> x_int{1, 2};
	std::vector<int> y_int{2, 3};

	cxxplot::Scatter<int> scatter_int(x_int, y_int, args);
	scatter_int.set_xlabel("x label");
	scatter_int.set_ylabel("y label");
    scatter_int.show();

    std::vector<float> x_float{1.0, 2.0};
    std::vector<float> y_float{2.0, 3.0};

    cxxplot::Scatter<float> scatter_float(x_float, y_float, args);
	scatter_float.set_xlabel("x label");
	scatter_float.set_ylabel("y label");
    scatter_float.show();

    std::vector<double> x_double{1.0, 2.0};
    std::vector<double> y_double{5.0, 3.0};

    cxxplot::Scatter<double> scatter_double(x_double, y_double, args);
	scatter_double.set_xlabel("x label");
	scatter_double.set_ylabel("y label");
	scatter_double.set_xlim(-10, 10);
	scatter_double.set_ylim(0, 8);
    scatter_double.show();

	return 0;
}