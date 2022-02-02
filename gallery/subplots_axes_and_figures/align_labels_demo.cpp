// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/align_labels_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

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

using matplotlibcpp17::gridspec::GridSpec;
using namespace matplotlibcpp17::util;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure(kwargs_("tight_layout"_a = true));
  auto gs = GridSpec(2, 2);
  // instead of gs[0, :]
  auto ax = fig.add_subplot(args_(gs(0, py::slice(0, 2, 1)).unwrap()));
  ax.plot(arange(0, 1000000, 10000));
  ax.set_ylabel("YLabel0");
  ax.set_xlabel("XLabel0");
  for (auto i : {0, 1}) {
    ax = fig.add_subplot(args_(gs(1, i).unwrap()));
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
#if USE_GUI
  plt.show();
#else
  plt.savefig("align_labels_demo.png");
#endif
}
