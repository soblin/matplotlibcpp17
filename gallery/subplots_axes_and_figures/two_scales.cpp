// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/two_scales.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  auto t_ = xt::arange(0.01, 10.0, 0.01);
  const auto data1_ = xt::exp(t_);
  const auto data2_ = xt::sin(2 * M_PI * t_);
  const vector<double> t(t_.begin(), t_.end()),
      data1(data1_.begin(), data1_.end()), data2(data2_.begin(), data2_.end());

  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  auto [fig, ax1] = plt.subplots();

  auto color = "tab:red";
  ax1.set_xlabel(Args("time (s)"));
  ax1.set_ylabel(Args("exp"), Kwargs("color"_a = color));
  ax1.plot(Args(t, data1), Kwargs("color"_a = color));
  ax1.tick_params(Args(), Kwargs("axis"_a = "y", "labelcolor"_a = color));

  auto ax2 =
      ax1.twinx(); // instantiate a second axes that shares the same x-axis

  color = "tab:blue";
  ax2.set_ylabel(Args("sin"), Kwargs("color"_a = color));
  ax2.plot(Args(t, data2), Kwargs("color"_a = color));
  ax2.tick_params(Args(), Kwargs("axis"_a = "y", "labelcolor"_a = color));

  fig.tight_layout();
  plt.show();
}
