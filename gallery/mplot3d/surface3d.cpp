// example from https://matplotlib.org/stable/gallery/mplot3d/surface3d.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/cm.h>
#include <matplotlibcpp17/mplot3d.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

using mesh2D = vector<vector<double>>;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  // this is required for "projection = 3d"
  matplotlibcpp17::mplot3d::import();
  auto [fig, ax] =
      plt.subplots(Kwargs("subplot_kw"_a = py::dict("projection"_a = "3d")));

  auto xs = xt::arange(-5.0, 5.0, 0.25);
  auto [X0, Y0] = xt::meshgrid(xs, xs);
  auto R0 = xt::sqrt(xt::pow(X0, 2) + xt::pow(Y0, 2));
  auto Z0 = xt::sin(R0);
  // to vector<vector>
  const int sz = xs.shape()[0];
  mesh2D X(sz), Y(sz), Z(sz);
  for (int i = 0; i < sz; ++i) {
    X[i].resize(sz);
    Y[i].resize(sz);
    Z[i].resize(sz);
    for (int j = 0; j < sz; ++j) {
      X[i][j] = X0(i, j);
      Y[i][j] = Y0(i, j);
      Z[i][j] = Z0(i, j);
    }
  }
  // to numpy array (vector<vector> is converted to list of list)
  auto X_ = py::array(py::cast(std::move(X)));
  auto Y_ = py::array(py::cast(std::move(Y)));
  auto Z_ = py::array(py::cast(std::move(Z)));
  auto surf = ax.plot_surface(Args(X_, Y_, Z_),
                              Kwargs("rstride"_a = 1, "cstride"_a = 1,
                                     "linewidth"_a = 0, "antialiased"_a = false,
                                     "cmap"_a = cm::coolwarm));
  ax.set_zlim(Args(-1.01, 1.01));
  // TODO
  // auto locator = ticker::LinearLocator(Args(10));
  // ax.zaxis.set_major_locator(Args(locator.unwrap()));
  // ax.zaxis.set_major_formatter(Args("{x:.02f}"));
  fig.colorbar(Args(surf.unwrap()), Kwargs("shrink"_a = 0.5, "aspect"_a = 5));
  plt.show();
}
