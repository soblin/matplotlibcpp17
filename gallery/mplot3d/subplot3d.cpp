// example https://matplotlib.org/stable/gallery/mplot3d/subplot3d.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>
#include <matplotlibcpp17/matplotlibcpp17.h>
#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

// NOTE: looks like vector<vector<T>> is naturally converted thanks to pybind11
// ref: https://github.com/pybind/pybind11/issues/1071
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

tuple<mesh2D, mesh2D> meshgrid(const vector<double> &x,
                               const vector<double> &y) {
  mesh2D X(y.size()), Y(y.size());
  for (unsigned i = 0; i < y.size(); ++i) {
    X[i].resize(x.size());
    Y[i].resize(x.size());
  }
  for (unsigned i = 0; i < y.size(); ++i) {
    for (unsigned j = 0; j < x.size(); ++j) {
      const double x0 = x[j], y0 = y[i];
      X[i][j] = x0;
      Y[i][j] = y0;
    }
  }
  return {X, Y};
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
  auto [w, h] = plt.figaspect(args_(0.5));
  auto fig = plt.figure(args_(), kwargs_("figsize"_a = py::make_tuple(w, h)));
  {
    auto ax = fig.add_subplot(args_(1, 2, 1), kwargs_("projection"_a = "3d"));
    vector<double> xs = arange(-5.0, 5.0, 0.25);
    vector<double> ys = xs;
    auto [X, Y] = meshgrid(xs, ys);
    mesh2D Z(X.size());
    for (unsigned j = 0; j < ys.size(); ++j)
      Z[j].resize(xs.size());
    for (unsigned j = 0; j < ys.size(); ++j) {
      for (unsigned i = 0; i < xs.size(); ++i) {
        const double x = xs[i], y = ys[j];
        Z[j][i] = sin(sqrt(x * x + y * y));
      }
    }
    // NOTE: conversion to numpy array
    // ref: https://github.com/pybind/pybind11/issues/2066
    auto X_ = py::array(py::cast(std::move(X)));
    auto Y_ = py::array(py::cast(std::move(Y)));
    auto Z_ = py::array(py::cast(std::move(Z)));
    auto surf = ax.plot_surface(
        args_(X_, Y_, Z_), kwargs_("rstride"_a = 1, "cstride"_a = 1,
                                   "linewidth"_a = 0, "antialiased"_a = false));
  }
  {
    auto ax = fig.add_subplot(args_(1, 2, 2), kwargs_("projection"_a = "3d"));
    auto [X, Y, Z] = get_test_data(0.05);
    auto X_ = py::array(py::cast(std::move(X)));
    auto Y_ = py::array(py::cast(std::move(Y)));
    auto Z_ = py::array(py::cast(std::move(Z)));
    ax.plot_wireframe(args_(X_, Y_, Z_),
                      kwargs_("rstride"_a = 10, "cstride"_a = 10));
  }
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("subplot3d.png"));
#endif
}
