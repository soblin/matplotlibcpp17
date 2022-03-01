// example from https://matplotlib.org/stable/gallery/mplot3d/lines3d.html

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
  auto fig = plt.figure();
  auto ax = fig.add_subplot(args_(), kwargs_("projection"_a = "3d"));
  auto theta_ = xt::linspace(-4 * M_PI, 4 * M_PI, 100);
  auto z_ = xt::linspace(-2.0, 2.0, 100);
  auto r_ = 1.0 + xt::pow(z_, 2);
  auto x_ = r_ * xt::sin(theta_);
  auto y_ = r_ * xt::cos(theta_);
  vector<double> z(z_.begin(), z_.end());
  vector<double> r(r_.begin(), r_.end());
  vector<double> theta(theta_.begin(), theta_.end());
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end());
  ax.plot(args_(x, y, z), kwargs_("label"_a = "parametric curve"));
  ax.legend();
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("lines3d.png"));
#endif
}
