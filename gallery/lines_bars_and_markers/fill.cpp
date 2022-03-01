// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xarray.hpp>

#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  const double scale = 10;
  const xt::xarray<double> angles = {90.0, 210.0, 330.0};
  auto x0 = scale / sqrt(3.0) * xt::cos(angles / 360.0 * 2 * M_PI);
  auto y0 = scale / sqrt(3.0) * xt::sin(angles / 360.0 * 2 * M_PI);
  vector<double> x(x0.begin(), x0.end());
  vector<double> y(y0.begin(), y0.end());

  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axes] =
      plt.subplots(1, 3,
                   Kwargs("figsize"_a = py::make_tuple(9, 3),
                          "subplot_kw"_a = py::dict("aspect"_a = "equal")));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];
  ax1.fill(Args(x, y));
  ax2.fill(Args(x, y), Kwargs("facecolor"_a = "lightsalmon",
                              "edgecolor"_a = "orangered", "linewidth"_a = 3));
  ax3.fill(Args(x, y), Kwargs("facecolor"_a = "none", "edgecolor"_a = "purple",
                              "linewidth"_a = 3));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("fill.png"));
#endif
  return 0;
}
