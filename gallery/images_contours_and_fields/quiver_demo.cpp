// example from
// https://matplotlib.org/stable/gallery/images_contours_and_fields/quiver_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <vector>
#include <algorithm>
#include <string>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17::util;

int main1() {
  vector<double> X, Y;
  for (double x = 0; x <= 2 * M_PI; x += 0.2) {
    for (double y = 0; y <= 2 * M_PI; y += 0.2) {
      X.push_back(x);
      Y.push_back(y);
    }
  }
  vector<double> U, V;
  transform(X.begin(), X.end(), back_inserter(U),
            [](double x) { return cos(x); });
  transform(Y.begin(), Y.end(), back_inserter(V),
            [](double y) { return sin(y); });
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig1, ax1] = plt.subplots();
  ax1.set_title("Arrows scale with plot width, not view");
  auto Q = ax1.quiver(args_(X, Y, U, V), kwargs_("units"_a = "width"));
  auto qk =
      ax1.quiverkey(args_(Q.unwrap(), 0.9, 0.9, 2, R"($2 \frac{m}{s}$)"),
                    kwargs_("labelpos"_a = "E", "coordinates"_a = "figure"));
#if USE_GUI
  plt.show();
#else
  plt.savefig("quiver_demo_1.png");
#endif
  return 0;
}

int main2() {
  vector<double> X, Y;
  for (double x = 0; x <= 2 * M_PI; x += 0.6) {
    for (double y = 0; y <= 2 * M_PI; y += 0.6) {
      X.push_back(x);
      Y.push_back(y);
    }
  }
  vector<double> U, V;
  transform(X.begin(), X.end(), back_inserter(U),
            [](double x) { return cos(x); });
  transform(Y.begin(), Y.end(), back_inserter(V),
            [](double y) { return sin(y); });
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig1, ax1] = plt.subplots();
  ax1.set_title("pivot='mid'; every third arrow; units='inches'");
  auto Q = ax1.quiver(args_(X, Y, U, V),
                      kwargs_("pivot"_a = "mid", "units"_a = "inches"));
  auto qk =
      ax1.quiverkey(args_(Q.unwrap(), 0.9, 0.9, 1, R"($1 \frac{m}{s}$)"),
                    kwargs_("labelpos"_a = "E", "coordinates"_a = "figure"));
  ax1.scatter(args_(X, Y), kwargs_("color"_a = "r", "s"_a = 5));

#if USE_GUI
  plt.show();
#else
  plt.savefig("quiver_demo_2.png");
#endif
  return 0;
}

int main3() {
  vector<double> X, Y;
  for (double x = 0; x <= 2 * M_PI; x += 0.2) {
    for (double y = 0; y <= 2 * M_PI; y += 0.2) {
      X.push_back(x);
      Y.push_back(y);
    }
  }
  vector<double> U, V, M;
  transform(X.begin(), X.end(), back_inserter(U),
            [](double x) { return cos(x); });
  transform(Y.begin(), Y.end(), back_inserter(V),
            [](double y) { return sin(y); });
  for (unsigned i = 0; i < U.size(); ++i) {
    M.push_back(hypot(U[i], V[i]));
  }
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig1, ax1] = plt.subplots();
  ax1.set_title("pivot='tip'; scales with x view");
  auto Q = ax1.quiver(args_(X, Y, U, V, M),
                      kwargs_("units"_a = "x", "pivot"_a = "tip",
                              "width"_a = 0.022, "scale"_a = 1.0 / 0.15));
  auto qk =
      ax1.quiverkey(args_(Q.unwrap(), 0.9, 0.9, 1, R"($1 \frac{m}{s}$)"),
                    kwargs_("labelpos"_a = "E", "coordinates"_a = "figure"));
  ax1.scatter(args_(X, Y), kwargs_("color"_a = "0.5", "s"_a = 1));

#if USE_GUI
  plt.show();
#else
  plt.savefig("quiver_demo_3.png");
#endif

  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main2();
  main3();
}
