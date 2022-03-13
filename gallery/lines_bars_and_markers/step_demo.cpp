// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/step_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();

  auto x_ = xt::arange(14) * 1.0;
  auto y_ = xt::sin(x_ / 2.0);
  auto y1_ = y_ + 1.0, y2_ = y_ + 2.0;
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end()),
      y1(y1_.begin(), y1_.end()), y2(y2_.begin(), y2_.end());

  plt.step(Args(x, y2), Kwargs("label"_a = "pre (default)"));
  plt.plot(Args(x, y2, "o--"), Kwargs("color"_a = "grey", "alpha"_a = 0.3));

  plt.step(Args(x, y1), Kwargs("where"_a = "mid", "label"_a = "mid"));
  plt.plot(Args(x, y1, "o--"), Kwargs("color"_a = "grey", "alpha"_a = 0.3));

  plt.step(Args(x, y), Kwargs("where"_a = "post", "label"_a = "post"));
  plt.plot(Args(x, y, "o--"), Kwargs("color"_a = "grey", "alpha"_a = 0.3));

  plt.grid(Args(), Kwargs("axis"_a = "x", "color"_a = "0.95"));
  plt.legend(Args(), Kwargs("title"_a = "Parameter where:"));
  plt.title(Args("plt.step(where...)"));
  plt.show();
}
