# matplotlib-cpp11

This project aims to replace [matplotlibcpp](https://github.com/lava/matplotlib-cpp) using [pybind11](https://github.com/pybind/pybind11) as backend.

## Dependencies

- pybind11(https://github.com/pybind/pybind11) >= version2.9.0

## Usage

Just add include path to `include` directory of this project.

```cpp

#include <matplotlibcpp11/matplotlibcpp11.h>
#include <pybind11/pybind11.h>

int main(){
   pybind11::interpreter guard{};
   matplotlibcpp11::plt plt;
   plt.show(...)
}
```
