// example from https://matplotlib.org/stable/gallery/statistics/errorbar.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xrandom.hpp>

#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  auto x_ = xt::arange(0.1, 4.0, 0.5);
  auto y_ = xt::exp(-x_);
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end());

  auto [fig, ax] = plt.subplots();
  ax.errorbar(Args(x, y), Kwargs("xerr"_a = 0.2, "yerr"_a = 0.4));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("erorrbar.png"));
#endif
}
