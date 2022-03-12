// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill_betweenx_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xarray.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main1() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto y_ = xt::arange(0.0, 2.0, 0.01);
  auto x1_ = xt::sin(2 * M_PI * y_);
  auto x2_ = 1.2 * xt::sin(4 * M_PI * y_);
  vector<double> y(y_.begin(), y_.end()), x1(x1_.begin(), x1_.end()),
      x2(x2_.begin(), x2_.end());

  auto [fig, axes] = plt.subplots(
      1, 3, Kwargs("sharey"_a = true, "figsize"_a = py::make_tuple(6, 6)));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];

  ax1.fill_betweenx(Args(y, 0, x1));
  ax1.set_title(Args("between (x1, 0)"));

  ax2.fill_betweenx(Args(y, x1, 1));
  ax2.set_title(Args("between (x1, 1)"));
  ax2.set_xlabel(Args("x"));

  ax3.fill_betweenx(Args(y, x1, x2));
  ax3.set_title(Args("between (x1, x2)"));

#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("fill_betweenx_demo.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
}
