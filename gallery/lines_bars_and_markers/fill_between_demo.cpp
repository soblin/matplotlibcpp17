// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill_between_demo.html#sphx-glr-gallery-lines-bars-and-markers-fill-between-demo-py

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
  for (int i = 0; i < N; ++i) {
    xs[i] = val;
    ;
    val += h;
  }
  return xs;
}

using namespace std;

int main1() {
  py::initialize_interpreter();
  auto plt = matplotlib_cpp11::import();

  const auto x = arange(0.0, 2.0, 0.01);
  vector<double> y1, y2;
  for_each(x.begin(), x.end(),
           [&](auto val) { y1.push_back(sin(2 * M_PI * val)); });
  for_each(x.begin(), x.end(),
           [&](auto val) { y2.push_back(0.8 * sin(4 * M_PI * val)); });
  auto [figs, axes] =
      plt.subplots(3, 1,
                   pybind11::dict("sharex"_a = true,
                                  "figsize"_a = pybind11::make_tuple(6, 6)));
  plt.show();
  return 0;
}

int main() { main1(); }
