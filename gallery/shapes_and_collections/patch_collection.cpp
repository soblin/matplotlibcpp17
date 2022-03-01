// example from
// https://matplotlib.org/stable/gallery/shapes_and_collections/patch_collection.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/patches.h>

#include <algorithm>
#include <iostream>
#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();

  const int N = 3;
  vector<double> x = {0.7003673, 0.74275081, 0.70928001},
                 y = {0.56674552, 0.97778533, 0.70633485},
                 radii = {0.02479158, 0.01578834, 0.06976985};
  py::list patches; // instead of patches = []
  for (int i = 0; i < N; ++i) {
    const double x1 = x[i], y1 = y[i], r = radii[i];
    auto circle = patches::Circle(Args(py::make_tuple(x1, y1), r));
    patches.append(circle.unwrap());
  }
  x = {0.71995667, 0.25774443, 0.34154678};
  y = {0.96876117, 0.6945071, 0.46638326};
  radii = {0.07028127, 0.05117859, 0.09287414};
  vector<double> theta1 = {266.3169476, 224.07805212, 234.5563688},
                 theta2 = {142.85074015, 195.56618216, 287.96383014};
  for (int i = 0; i < N; ++i) {
    const double x1 = x[i], y1 = y[i], r = radii[i], th1 = theta1[i],
                 th2 = theta2[i];
    auto wedge = patches::Wedge(Args(py::make_tuple(x1, y1), r, th1, th2));
    patches.append(wedge.unwrap());
  }
  patches.append(
      patches::Wedge(Args(py::make_tuple(0.3, 0.7), 0.1, 0, 360)).unwrap());
  patches.append(patches::Wedge(Args(py::make_tuple(0.7, 0.8), 0.2, 0, 360),
                                Kwargs("width"_a = 0.05))
                     .unwrap());
  patches.append(
      patches::Wedge(Args(py::make_tuple(0.8, 0.3), 0.2, 0, 45)).unwrap());
  patches.append(patches::Wedge(Args(py::make_tuple(0.8, 0.3), 0.2, 45, 90),
                                Kwargs("width"_a = 0.10))
                     .unwrap());
  // NOTE: Polygon take numpy array as argument, so skip it
  vector<double> colors_ = {90.63036451, 16.10182093, 74.36211347, 63.29741618,
                            32.41800177, 92.23765324, 23.72264387, 82.39455709,
                            75.06071403, 11.37844527};
  py::list colors = py::cast(colors_);
  auto p = collections::PatchCollection(Args(patches), Kwargs("alpha"_a = 0.4));
  p.set_array(Args(colors));
  ax.add_collection(Args(p.unwrap()));
  fig.colorbar(Args(p.unwrap()), Kwargs("ax"_a = ax.unwrap()));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("patch_collection.png"));
#endif
  return 0;
}
