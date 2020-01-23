//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include <iostream>
#include <random>
#include "cxxplot.hpp"

int
main()
{
	std::cout << "Running histogram_1 example" << std::endl;

	std::random_device rd{};
	std::mt19937 gen{rd()};

	std::normal_distribution<double> d{0, 1};

	std::vector<double> x;
	for (int n = 0; n<10000; ++n) {
		x.push_back(d(gen));
	}

	cxxplot::Histogram<double> histogram(x);
	histogram.show_plot();

	return 0;
}