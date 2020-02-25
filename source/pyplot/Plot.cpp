//---------------------------------------------------------------------------//
// Copyright (c) 2019 Eleftherios Avramidis <el.avramidis@gmail.com>
//
// Distributed under The MIT License (MIT)
// See accompanying file LICENSE
//---------------------------------------------------------------------------//

#include "pyplot/Plot.hpp"
#include "pyplot/Kwargs.hpp"
#include "generic/PythonCalls.hpp"
#include "generic/ConvertToNumpy.hpp"
#include <stdexcept>
#include <numeric>

namespace cxxplot {

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(std::vector<inputType>& y, bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        initialize_x_default(y.size());
        draw(x_default, y);
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(std::vector<inputType>& x, std::vector<inputType>& y, bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x, y);
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(std::vector<inputType>& y, std::string fmt, bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        initialize_x_default(y.size());
        draw(x_default, y, fmt);
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt, bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x, y, fmt);
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::Plot(std::vector<inputType>& x, std::vector<inputType>& y,
            Kwargs& args, bool create_new_figure)
    {
        if (create_new_figure) {
            this->figure();
        }
        initialize();
        draw(x, y, args);
    }

    template<class inputType> CXXPLOT_EXPORT
    Plot<inputType>::~Plot()
    {
        Py_DECREF(plot);
    }

    template<class inputType>
    void
    Plot<inputType>::initialize_x_default(size_t x_size)
    {
        x_default.resize(x_size);
        std::iota(x_default.begin(), x_default.end(), inputType(0));
    }

    template<class inputType>
    void
    Plot<inputType>::initialize()
    {
        plot = PythonCalls::get_pyobject_function_by_string(this->matplotlib_pyplot, "plot");
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType>& x, std::vector<inputType>& y)
    {
        PyObject* args = generate_args_pytuple(x, y);

        PythonCalls::pyobject_callobject_with_checks(plot, args);
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType>& x, std::vector<inputType>& y,
            Kwargs& kwargs)
    {
        PyObject* args = generate_args_pytuple(x, y);

        PythonCalls::pyobject_call_with_checks(plot, args, kwargs.get_pydict());
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt)
    {
        PyObject* args = generate_args_pytuple(x, y, fmt);

        PythonCalls::pyobject_callobject_with_checks(plot, args);
    }

    template<class inputType>
    void
    Plot<inputType>::draw(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt,
            Kwargs& kwargs)
    {
        PyObject* args = generate_args_pytuple(x, y, fmt);

        PythonCalls::pyobject_call_with_checks(plot, args, kwargs.get_pydict());
    }

    template<class inputType>
    PyObject*
    Plot<inputType>::generate_args_pytuple(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt)
    {
        PyObject* x_py = ConvertToNumpy::vector_to_numpy(x);
        PyObject* y_py = ConvertToNumpy::vector_to_numpy(y);
        PyObject* fmt_py = PyUnicode_FromString(fmt.c_str());

        PyObject* args = PyTuple_New(3);
        PyTuple_SetItem(args, 0, x_py);
        PyTuple_SetItem(args, 1, y_py);
        PyTuple_SetItem(args, 2, fmt_py);
        return args;
    }

    template<class inputType>
    void
    Plot<inputType>::add_data(std::vector<inputType>& x, std::vector<inputType>& y)
    {
        draw(x, y);
    }

    template<class inputType>
    void
    Plot<inputType>::add_data(std::vector<inputType>& x, std::vector<inputType>& y,
            Kwargs& args)
    {
        draw(x, y, args);
    }

    template<class inputType>
    void
    Plot<inputType>::add_data(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt)
    {
        draw(x, y, fmt);
    }

    template<class inputType>
    void
    Plot<inputType>::add_data(std::vector<inputType>& x, std::vector<inputType>& y, std::string fmt,
            Kwargs& kwargs)
    {
        draw(x, y, fmt, kwargs);
    }

    template CXXPLOT_EXPORT
    class Plot<int>;

    template CXXPLOT_EXPORT
    class Plot<float>;

    template CXXPLOT_EXPORT
    class Plot<double>;
}