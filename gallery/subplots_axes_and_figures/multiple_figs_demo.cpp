// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/multiple_figs_demo.html

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
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  vector<double> t = arange(0.0, 2.0, 0.01);
  vector<double> s1, s2;
  transform(t.begin(), t.end(), back_inserter(s1),
            [](double x) { return sin(2 * M_PI * x); });
  transform(t.begin(), t.end(), back_inserter(s2),
            [](double x) { return sin(4 * M_PI * x); });
  plt.figure(args_(1));
  plt.subplot(211);
  plt.plot(t, s1);
  plt.subplot(212);
  plt.plot(t, s2);
#if USE_GUI
  plt.show();
#else
  plt.savefig("multiple_figs_demo1.png");
#endif
  plt.figure(args_(2));
  plt.plot(t, s2);
#if USE_GUI
  plt.show();
#else
  plt.savefig("multiple_figs_demo2.png");
#endif
  plt.figure(args_(2));
  plt.subplot(211);
  plt.plot(t, s2, "s");
  auto ax = plt.gca();
  ax.set_xticks(args_());
#if USE_GUI
  plt.show();
#else
  plt.savefig("multiple_figs_demo3.png");
#endif
  return 0;
}
