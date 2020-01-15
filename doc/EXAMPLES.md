# Examples of how to use cxxplot

## Link cxxplot using CMake

To link cxxplot in your cmake project after installing cxxplot use the following CMake code

```bash
find_package(Python3 COMPONENTS Development NumPy)
find_package(cxxplot REQUIRED)
target_link_libraries(your_target PRIVATE cxxplot::cxxplot Python3::Python Python3::NumPy)
```

## Code examples

C++ source code examples can be found in the examples folder in the main repository directory.

### Simple plot example

```c++
#include "cxxplot.hpp"
int main()
{
    std::vector<std::pair<std::string, std::string>> args;
    args.emplace_back("color", "r");
    args.emplace_back("marker", "o");
    
    std::vector<int> x_int{1, 2};
    std::vector<int> y_int{2, 3};
    
    cxxplot::Plot<int> plot_int(x_int, y_int, args);
    plot_int.set_xlabel("x label");
    plot_int.set_ylabel("y label");
    plot_int.show_plot();
}
```