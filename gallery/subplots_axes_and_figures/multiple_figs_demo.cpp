// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/multiple_figs_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto x_ = xt::arange(0.0, 2.0, 0.01);
  auto s1_ = xt::sin(2 * M_PI * x_);
  auto s2_ = xt::sin(4 * M_PI * x_);
  vector<double> x(x_.begin(), x_.end()), s1(s1_.begin(), s1_.end()),
      s2(s2_.begin(), s2_.end());
  plt.figure(args_(1));
  plt.subplot(211);
  plt.plot(args_(x, s1));
  plt.subplot(212);
  plt.plot(args_(x, s2));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("multiple_figs_demo1.png"));
#endif
  plt.figure(args_(2));
  plt.plot(args_(x, s2));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("multiple_figs_demo2.png"));
#endif
  plt.figure(args_(2));
  plt.subplot(211);
  plt.plot(args_(x, s2, "s"));
  auto ax = plt.gca();
  ax.set_xticklabels(args_(py::list()));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("multiple_figs_demo3.png"));
#endif
  return 0;
}
