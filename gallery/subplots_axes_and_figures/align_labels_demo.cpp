// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/align_labels_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlib_cpp11/matplotlib_cpp11.h>

#include <algorithm>
#include <iostream>
#include <vector>

namespace py = pybind11;
using namespace py::literals;

template <typename T> std::vector<T> arange(T start, T end, T h) {
  int N = static_cast<int>((end - start) / h);
  std::vector<T> xs(N);
  T val = start;
  for (int i = 0; i < N; ++i) {
    xs[i] = val;
    val += h;
  }
  return xs;
}

using namespace std;
using matplotlib_cpp11::gridspec::GridSpec;

int main() {
  py::initialize_interpreter();
  auto plt = matplotlib_cpp11::pyplot::import();
  auto fig = plt.figure(py::dict("tight_layout"_a = true));
  auto gs = GridSpec(2, 2);
  // instead of gs[0, :], use gs(0, -1) for slicing
  auto ax = fig.add_subplot(py::make_tuple(gs(0, -1)));
  ax.plot(arange(0, 1000000, 10000));
  ax.set_ylabel("YLabel0");
  ax.set_xlabel("XLabel0");
  for (auto i : {0, 1}) {
    // TODO: in the future gs(r, c) are supposed to return `class SubplotSpec`
    // So `.object()` method will be necessary for all wrapper classes to be
    // passed to the interpreter as internal python objects.
    ax = fig.add_subplot(py::make_tuple(gs(1, i)));
    auto ys = arange(1.0, 0.0, -0.1);
    decltype(ys) xs;
    transform(ys.begin(), ys.end(), back_inserter(xs),
              [](double x) { return x * 2000; });
    ax.plot(xs, ys);
    ax.set_ylabel(string("YLabel1 " + to_string(i)));
    ax.set_xlabel(string("XLabel1 " + to_string(i)));
    if (i == 0) {
      for (auto &&tick : ax.get_xticklabels())
        tick.set_rotation(55);
    }
  }
  fig.align_labels();
  plt.show();
}
