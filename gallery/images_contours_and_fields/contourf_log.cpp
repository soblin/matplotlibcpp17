// example from
// https://matplotlib.org/stable/gallery/images_contours_and_fields/contourf_log.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/cm.h>
#include <matplotlibcpp17/ticker.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xview.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;
using namespace xt::placeholders;

using mesh2D = vector<vector<double>>;

int main() {
  const int N = 100;
  auto x_ = xt::linspace(-3.0, 3.0, N);
  auto y_ = xt::linspace(-2.0, 2.0, N);

  auto [X_, Y_] = xt::meshgrid(x_, y_);
  auto Z1_ = xt::exp(-xt::pow(X_, 2) - xt::pow(Y_, 2));
  auto Z2_ = xt::exp(-xt::pow(X_ * 10, 2) - xt::pow(Y_ * 10, 2));
  xt::xarray<double> z_ = Z1_ + 50 * Z2_;
  // instead of x[:5, :5] = -1.0
  auto v = xt::view(z_, xt::range(_, 5), xt::range(_, 5));
  v = 0.0;
  // to vector<vector>>
  const int xsz = x_.shape()[0], ysz = y_.shape()[0];
  mesh2D X(xsz), Y(xsz), z(xsz);
  for (int i = 0; i < xsz; ++i) {
    X[i].resize(ysz);
    Y[i].resize(ysz);
    z[i].resize(ysz);
    for (int j = 0; j < ysz; ++j) {
      X[i][j] = X_(i, j);
      Y[i][j] = Y_(i, j);
      z[i][j] = z_(i, j);
    }
  }

  py::scoped_interpreter guard{};
  // to numpy array
  auto Xpy = py::array(py::cast(std::move(X)));
  auto Ypy = py::array(py::cast(std::move(Y)));
  auto zpy = py::array(py::cast(std::move(z)));
  auto plt = pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto cs = ax.contourf(Args(Xpy, Ypy, zpy),
                        Kwargs("locator"_a = ticker::LogLocator().unwrap(),
                               "cmap"_a = cm::PuBu_r));
  fig.colorbar(Args(cs));
  plt.show();
}
