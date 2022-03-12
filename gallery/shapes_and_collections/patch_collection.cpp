// example from
// https://matplotlib.org/stable/gallery/shapes_and_collections/patch_collection.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/patches.h>

#include <xtensor/xrandom.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17::patches;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();

  const int resolution = 50;
  const int N = 3;
  xt::xarray<double> x = xt::random::rand<double>({N});
  xt::xarray<double> y = xt::random::rand<double>({N});
  xt::xarray<double> radii = 0.1 * xt::random::rand<double>({N});
  py::list patches; // instead of patches = []
  for (int i = 0; i < N; ++i) {
    const double x1 = x[i], y1 = y[i], r = radii[i];
    auto circle = patches::Circle(Args(py::make_tuple(x1, y1), r));
    patches.append(circle.unwrap());
  }

  x = xt::random::rand<double>({N});
  y = xt::random::rand<double>({N});
  radii = 0.1 * xt::random::rand<double>({N});
  xt::xarray<double> theta1 = 360.0 * xt::random::rand<double>({N});
  xt::xarray<double> theta2 = 360.0 * xt::random::rand<double>({N});
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

  for (int i = 0; i < N; ++i) {
    auto poly__ = xt::random::rand<double>({N, 2});
    vector<vector<double>> poly_(N);
    // to vector<vector>>
    for (int j = 0; j < N; ++j) {
      poly_[j].resize(2);
      poly_[j][0] = poly__(j, 0);
      poly_[j][1] = poly__(j, 1);
    }
    // to numpy array
    auto poly = py::array(py::cast(std::move(poly_)));
    auto polygon = Polygon(Args(poly, true));
    patches.append(polygon.unwrap());
  }

  auto colors__ = 100.0 * xt::random::rand<double>({patches.size()});
  vector<double> colors_(colors__.begin(), colors__.end());
  py::array colors = py::cast(colors_);
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
