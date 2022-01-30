// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;

using namespace std;
using namespace matplotlibcpp17::util;

int main() {
  const double scale = 10;
  const vector<double> angles = {90.0, 210.0, 330.0};
  vector<double> x;
  transform(angles.begin(), angles.end(), back_inserter(x),
            [&scale](double angle) {
              return scale / sqrt(3.0) * cos(angle / 360.0 * 2 * M_PI);
            });
  vector<double> y;
  transform(angles.begin(), angles.end(), back_inserter(y),
            [&scale](double angle) {
              return scale / sqrt(3.0) * sin(angle / 360.0 * 2 * M_PI);
            });

  py::scoped_interpreter gurad{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axes] =
      plt.subplots(1, 3,
                   kwargs_("figsize"_a = py::make_tuple(9, 3),
                           "subplot_kw"_a = py::dict("aspect"_a = "equal")));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];
  ax1.fill(x, y);
  ax2.fill(x, y, "facecolor"_a = "lightsalmon", "edgecolor"_a = "orangered",
           "linewidth"_a = 3);
  ax3.fill(x, y, "facecolor"_a = "none", "edgecolor"_a = "purple",
           "linewidth"_a = 3);
  plt.show();
  return 0;
}
