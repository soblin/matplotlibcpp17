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

int main() {
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
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig1, ax1] = plt.subplots();
  ax1.set_title("Arrows scale with plot width, not view");
  auto Q = ax1.quiver(args_(X, Y, U, V), kwargs_("units"_a = "width"));
  auto qk =
      ax1.quiverkey(args_(Q.unwrap(), 0.9, 0.9, 2, R"($2 \frac{m}{s}$)"),
                    kwargs_("labelpos"_a = "E", "coordinates"_a = "figure"));
  plt.show();
  return 0;
}
