// example https://matplotlib.org/stable/gallery/mplot3d/subplot3d.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/cm.h>
#include <matplotlibcpp17/mplot3d.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

// NOTE: looks like vector<vector<T>> is naturally converted thanks to pybind11
// ref: https://github.com/pybind/pybind11/issues/1071
using mesh2D = vector<vector<double>>;

// from mpl_toolkits.axes3d.py
tuple<mesh2D, mesh2D, mesh2D> get_test_data(double delta = 0.05) {
  const auto xs = xt::arange(-3.0, 3.0, delta);
  const auto ys = xt::arange(-3.0, 3.0, delta);
  const auto [X0, Y0] = xt::meshgrid(xs, ys); // 120x160
  const auto Z1 =
      xt::exp(-(xt::pow(X0, 2) + xt::pow(Y0, 2)) / 2.0) / (2 * M_PI);
  const auto Z2 =
      xt::exp(-(xt::pow((X0 - 1.0) / 1.5, 2) + xt::pow((Y0 - 1.0) / 0.5, 2)) /
              2) /
      (2 * M_PI * 0.5 * 1.5);
  const auto Z0 = Z2 - Z1;
  const auto X = X0 * 10;
  const auto Y = Y0 * 10;
  const auto Z = Z0 * 500;
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
  // this is required for "projection = 3d"
  matplotlibcpp17::mplot3d::import();
  auto [w, h] = plt.figaspect(Args(0.5));
  auto fig = plt.figure(Args(), Kwargs("figsize"_a = py::make_tuple(w, h)));
  {
    auto ax = fig.add_subplot(Args(1, 2, 1), Kwargs("projection"_a = "3d"));
    const auto xs = xt::arange(-5.0, 5.0, 0.25);
    const auto [X0, Y0] = xt::meshgrid(xs, xs);
    const auto R0 = xt::sqrt(xt::pow(X0, 2) + xt::pow(Y0, 2));
    const auto Z0 = xt::sin(R0);
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
    // NOTE: conversion to numpy array
    // ref: https://github.com/pybind/pybind11/issues/2066
    const auto X_ = py::array(py::cast(std::move(X)));
    const auto Y_ = py::array(py::cast(std::move(Y)));
    const auto Z_ = py::array(py::cast(std::move(Z)));
    auto surf = ax.plot_surface(
        Args(X_, Y_, Z_),
        Kwargs("rstride"_a = 1, "cstride"_a = 1, "linewidth"_a = 0,
               "antialiased"_a = false, "cmap"_a = cm::coolwarm));
    ax.set_zlim(Args(-1.01, 1.01));
    fig.colorbar(Args(surf.unwrap()),
                 Kwargs("shrink"_a = 0.5, "aspect"_a = 10));
  }
  {
    const auto ax =
        fig.add_subplot(Args(1, 2, 2), Kwargs("projection"_a = "3d"));
    const auto [X, Y, Z] = get_test_data(0.05);
    const auto X_ = py::array(py::cast(std::move(X)));
    const auto Y_ = py::array(py::cast(std::move(Y)));
    const auto Z_ = py::array(py::cast(std::move(Z)));
    ax.plot_wireframe(Args(X_, Y_, Z_),
                      Kwargs("rstride"_a = 10, "cstride"_a = 10));
  }
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("subplot3d.png"));
#endif
}
