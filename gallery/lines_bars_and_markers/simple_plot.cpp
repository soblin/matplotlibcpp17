#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlib_cpp11/matplotlib_cpp11.h>

#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;

template <typename T> std::vector<T> arange(T start, T end, T h) {
  int N = static_cast<int>((end - start) / h);
  std::vector<T> xs(N);
  T val = start;
  while (val <= end) {
    xs.push_back(val);
    val += h;
  }
  return xs;
}

using namespace std;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlib_cpp11::import();
  auto t = arange(0.0, 2.0, 0.01);
  decltype(t) s;
  for_each(t.begin(), t.end(),
           [&](auto val) { s.push_back(1.0 + sin(2 * M_PI * val)); });
  plt.plot(t, s, "color"_a = "red", "linewidth"_a = 1.5);
  plt.show();
}
