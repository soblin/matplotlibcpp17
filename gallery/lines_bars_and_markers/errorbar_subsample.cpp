// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/errorbar_subsample.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  auto x_ = xt::arange(0.1, 4.0, 0.1);
  auto y1_ = xt::exp(-1.0 * x_);
  auto y2_ = xt::exp(-0.5 * x_);
  auto y1err_ = 0.1 + 0.1 * xt::sqrt(x_);
  auto y2err_ = 0.1 + 0.1 * xt::sqrt(x_ / 2.0);
  vector<double> x(x_.begin(), x_.end()), y1(y1_.begin(), y1_.end()),
      y2(y2_.begin(), y2_.end()), y1err(y1err_.begin(), y1err_.end()),
      y2err(y2err_.begin(), y2err_.end());

  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  auto [fig, axs] = plt.subplots(
      1, 3, Kwargs("sharex"_a = true, "figsize"_a = py::make_tuple(12, 6)));
  auto ax0 = axs[0], ax1 = axs[1], ax2 = axs[2];
  ax0.set_title(Args("all errorbars"));
  ax0.errorbar(Args(x, y1), Kwargs("yerr"_a = y1err));
  ax0.errorbar(Args(x, y1), Kwargs("yerr"_a = y2err));

  ax1.set_title(Args("only every 6th errorbar"));
  ax1.errorbar(Args(x, y1), Kwargs("yerr"_a = y1err, "errorevery"_a = 6));
  ax1.errorbar(Args(x, y2), Kwargs("yerr"_a = y2err, "errorevery"_a = 6));

  ax2.set_title(Args("second seris shifted by 3"));
  ax2.errorbar(Args(x, y1),
               Kwargs("yerr"_a = y1err, "errorevery"_a = py::make_tuple(0, 6)));
  ax2.errorbar(Args(x, y2),
               Kwargs("yerr"_a = y2err, "errorevery"_a = py::make_tuple(3, 6)));

  fig.suptitle(Args("Errorbar subsampling"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("erorbar_subsample.png"));
#endif
}
