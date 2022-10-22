// example https://matplotlib.org/stable/gallery/mplot3d/contour3d.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/cm.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

// looks like vector<vector<T>> is naturally converted thanks to pybind11:
// https://github.com/pybind/pybind11/issues/1071
using mesh2D = vector<vector<double>>;

// from mpl_toolkits.axes3d.py
tuple<mesh2D, mesh2D, mesh2D> get_test_data(double delta = 0.05) {
  auto xs = xt::arange(-3.0, 3.0, delta);
  auto ys = xt::arange(-3.0, 3.0, delta);
  auto [X0, Y0] = xt::meshgrid(xs, ys); // 120x160
  auto Z1 = xt::exp(-(xt::pow(X0, 2) + xt::pow(Y0, 2)) / 2.0) / (2 * M_PI);
  auto Z2 =
      xt::exp(-(xt::pow((X0 - 1.0) / 1.5, 2) + xt::pow((Y0 - 1.0) / 0.5, 2)) /
              2) /
      (2 * M_PI * 0.5 * 1.5);
  auto Z0 = Z2 - Z1;
  auto X = X0 * 10;
  auto Y = Y0 * 10;
  auto Z = Z0 * 500;
  const int szx = xs.shape()[0], szy = ys.shape()[0];
  mesh2D X_(szx), Y_(szx), Z_(szx);
  for (int i = 0; i < szx; ++i) {
    X_[i].resize(szy);
    Y_[i].resize(szy);
    Z_[i].resize(szy);
    for (int j = 0; j < szy; ++j) {
      X_[i][j] = X(i, j);
      Y_[i][j] = Y(i, j);
      Z_[i][j] = Z(i, j);
    }
  }
  return {X_, Y_, Z_};
}

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(Args(), Kwargs("projection"_a = "3d"));
  auto [X, Y, Z] = get_test_data(0.05);
  ax.contour(Args(X, Y, Z), Kwargs("cmap"_a = cm::coolwarm));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("contour3d.png"));
#endif
}
