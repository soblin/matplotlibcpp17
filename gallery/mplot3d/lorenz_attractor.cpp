// example from
// https://matplotlib.org/stable/gallery/mplot3d/lorenz_attractor.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/mplot3d.h>

#include <vector>

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
  // this is required for "projection = 3d"
  matplotlibcpp17::mplot3d::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(Args(), Kwargs("projection"_a = "3d"));

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
  ax.plot(Args(xs, ys, zs));
  ax.set_xlabel(Args("X Axis"));
  ax.set_ylabel(Args("Y Axis"));
  ax.set_zlabel(Args("Z Axis"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("lorenz_attractor.png"));
#endif
}
