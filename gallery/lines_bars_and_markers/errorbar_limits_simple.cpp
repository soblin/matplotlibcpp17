// example
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/errorbar_limits_simple.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  auto fig = plt.figure();
  auto x_ = xt::arange(0.0, 10.0, 1.0);
  auto y_ = 2.5 * xt::sin(x_ / 20 * M_PI);
  auto y1_ = y_ + 1.0, y2_ = y_ + 2.0, y3_ = y_ + 3.0;
  auto yerr_ = xt::linspace(0.05, 0.2, 10);
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end()),
      yerr(yerr_.begin(), yerr_.end()), y3(y3_.begin(), y3_.end()),
      y2(y2_.begin(), y2_.end()), y1(y1_.begin(), y1_.end());
  plt.errorbar(Args(x, y3),
               Kwargs("yerr"_a = yerr, "label"_a = "both limits (default)"));
  plt.errorbar(Args(x, y2), Kwargs("yerr"_a = yerr, "uplims"_a = true,
                                   "label"_a = "uplims=True"));
  plt.errorbar(Args(x, y1),
               Kwargs("yerr"_a = yerr, "uplims"_a = true, "lolims"_a = true,
                      "label"_a = "uplims=True, lolims=True"));

  vector<bool> upperlimits, lowerlimits;
  for (auto i : {0, 1, 2, 3, 4}) {
    upperlimits.push_back(true);
    upperlimits.push_back(false);
    lowerlimits.push_back(false);
    lowerlimits.push_back(true);
  }
  plt.errorbar(Args(x, y), Kwargs("yerr"_a = yerr, "uplims"_a = upperlimits,
                                  "lolims"_a = lowerlimits,
                                  "label"_a = "subsets of uplims and lolims"));
  plt.legend(Args(), Kwargs("loc"_a = "lower right"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("errorbar_limits_simple.png"));
#endif
}
