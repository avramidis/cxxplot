//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#ifndef CPPPYPLOT_PLOT_HPP
#define CPPPYPLOT_PLOT_HPP

#include "Pyplot.hpp"
#include "Kwargs.hpp"
#include <string>
#include <map>

namespace cxxplot {
	template<class inputType>
	class CXXPLOT_EXPORT Plot : public Pyplot<inputType> {
	private:
		PyObject* plot;
		std::vector<inputType> x_default;

	public:
		explicit Plot(bool create_new_figure=true);
		explicit Plot(std::vector<inputType>& y, bool create_new_figure=true);
		explicit Plot(std::vector<inputType>& x, std::vector<inputType>& y, bool create_new_figure=true);
		explicit Plot(std::vector<inputType>& y, std::string fmt, bool create_new_figure=true);
		explicit Plot(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt, bool create_new_figure=true);
		explicit Plot(std::vector<inputType>& x, std::vector<inputType>& y, Kwargs& args, bool create_new_figure=true);
		~Plot();

		void add_data(std::vector<inputType>& x, std::vector<inputType>& y);
		void add_data(std::vector<inputType>& x, std::vector<inputType>& y,
				Kwargs& args);
		void add_data(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt);
		void add_data(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt,
				Kwargs& kwargs);
	private:
		void
		initialize_x_default(int x_size);

		void
		initialize();

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y);

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y,
				Kwargs& args);

		void draw(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt);

		void
		draw(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt,
                Kwargs& kwargs);

		PyObject* generate_args_pytuple(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt = "");
	};
}

#endif
