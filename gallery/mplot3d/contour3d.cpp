// example https://matplotlib.org/stable/gallery/mplot3d/contour3d.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <matplotlibcpp17/pyplot.h>
#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

// looks like vector<vector<T>> is naturally converted thanks to pybind11:
// https://github.com/pybind/pybind11/issues/1071
using mesh2D = vector<vector<double>>;

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

// from mpl_toolkits.axes3d.py
tuple<mesh2D, mesh2D, mesh2D> get_test_data(double delta = 0.05) {
  const vector<double> xs = arange(-3.0, 3.0, delta);
  const auto ys = xs;
  mesh2D X(ys.size()), Y(ys.size()), Z(ys.size());
  for (unsigned i = 0; i < ys.size(); ++i) {
    X[i].resize(xs.size());
    Y[i].resize(xs.size());
    Z[i].resize(xs.size());
  }
  for (unsigned i = 0; i < ys.size(); ++i) {
    for (unsigned j = 0; j < xs.size(); ++j) {
      const double x = xs[j], y = ys[i];
      const double z1 = exp(-(pow(x, 2) + pow(y, 2)) / 2.0) / (2 * M_PI);
      const double z2 =
          exp(-(pow((x - 1) / 1.5, 2) + pow((y - 1) / 0.5, 2)) / 2.0) /
          (2 * M_PI * 0.5 * 1.5);
      X[i][j] = x * 10;
      Y[i][j] = y * 10;
      Z[i][j] = (z2 - z1) * 500;
    }
  }
  return {X, Y, Z};
}

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(args_(), kwargs_("projection"_a = "3d"));
  auto [X, Y, Z] = get_test_data(0.05);
  // TODO: cmap=cm.coolwarm
  ax.contour(args_(X, Y, Z));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("contour3d.png"));
#endif
}
