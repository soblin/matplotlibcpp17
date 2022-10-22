// example from https://matplotlib.org/stable/gallery/mplot3d/lines3d.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/mplot3d.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  // this is required for "projection = 3d"
  matplotlibcpp17::mplot3d::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(Args(), Kwargs("projection"_a = "3d"));
  auto theta_ = xt::linspace(-4 * M_PI, 4 * M_PI, 100);
  auto z_ = xt::linspace(-2.0, 2.0, 100);
  auto r_ = 1.0 + xt::pow(z_, 2);
  auto x_ = r_ * xt::sin(theta_);
  auto y_ = r_ * xt::cos(theta_);
  vector<double> z(z_.begin(), z_.end());
  vector<double> r(r_.begin(), r_.end());
  vector<double> theta(theta_.begin(), theta_.end());
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end());
  ax.plot(Args(x, y, z), Kwargs("label"_a = "parametric curve"));
  ax.legend();
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("lines3d.png"));
#endif
}
