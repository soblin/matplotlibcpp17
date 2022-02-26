// example from
// https://matplotlib.org/stable/gallery/mplot3d/lorenz_attractor.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <matplotlibcpp17/matplotlibcpp17.h>
#include <algorithm>
#include <vector>
#include <tuple>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

tuple<double, double, double> lorenz(double x, double y, double z,
                                     double s = 10, double r = 28,
                                     double b = 2.667) {
  double x_dot = s * (y - x);
  double y_dot = r * x - y - x * z;
  double z_dot = x * y - b * z;
  return {x_dot, y_dot, z_dot};
}

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(args_(), kwargs_("projection"_a = "3d"));

  const double dt = 0.01;
  const int num_steps = 10000;
  vector<double> xs, ys, zs;
  xs.push_back(0.0);
  ys.push_back(1.0);
  zs.push_back(1.05);
  for (int i = 0; i < num_steps; ++i) {
    auto [x_dot, y_dot, z_dot] = lorenz(xs[i], ys[i], zs[i]);
    xs.push_back(xs[i] + x_dot * dt);
    ys.push_back(ys[i] + y_dot * dt);
    zs.push_back(zs[i] + z_dot * dt);
  }
  ax.plot(args_(xs, ys, zs));
  ax.set_xlabel(args_("X Axis"));
  ax.set_ylabel(args_("Y Axis"));
  ax.set_zlabel(args_("Z Axis"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("lorenz_attractor.png"));
#endif
}
