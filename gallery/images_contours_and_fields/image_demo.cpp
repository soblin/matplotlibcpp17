// example from
// https://matplotlib.org/stable/gallery/images_contours_and_fields/image_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xview.hpp>

#include <vector>
#include <string>
#include <algorithm>

using namespace std;
using namespace matplotlibcpp17;

using mesh2D = vector<vector<double>>;

int main() {
  const double delta = 0.025;
  const auto x = xt::arange<double>(-3.0, 3.0, delta);
  auto [X_, Y_] = xt::meshgrid(x, x);
  auto Z1_ = xt::exp(-xt::pow(X_, 2) - xt::pow(Y_, 2));
  auto Z2_ = xt::exp(-xt::pow(X_ - 1, 2) - xt::pow(Y_ - 1, 2));
  auto Z_ = (Z1_ - Z2_) * 2.0;

  // to vector
  vector<double> X(X_.begin(), X_.end()), Y(Y_.begin(), Y_.end()),
      Z1(Z1_.begin(), Z1_.end()), Z2(Z2_.begin(), Z2_.end());
  // to vector<vector>
  const int xsz = x.shape()[0], ysz = x.shape()[0];
  mesh2D Z2D(xsz);
  for (int i = 0; i < xsz; ++i) {
    Z2D[i].resize(ysz);
    for (int j = 0; j < ysz; ++j) {
      Z2D[i][j] = Z_(i, j);
    }
  }

  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  const double vmax = *max_element(Z_.begin(), Z_.end()),
               vmin = *min_element(Z_.begin(), Z_.end());
  auto Zpy = py::array(py::cast(std::move(Z2D)));
  ax.imshow(Args(Zpy), Kwargs("interpolation"_a = "bilinear",
                              "cmap"_a = "RdYlGn", "origin"_a = "lower",
                              "extent"_a = py::make_tuple(-3, 3, -3, 3),
                              "vmax"_a = vmax, "vmin"_a = vmin));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("image_demo.png"));
#endif
  return 0;
}
