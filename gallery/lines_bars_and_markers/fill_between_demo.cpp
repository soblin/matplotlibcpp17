// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill_between_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xarray.hpp>
#include <xtensor/xio.hpp>

#include <vector>
#include <algorithm>

using namespace std;
using namespace matplotlibcpp17;

int main1() {
  const auto x_ = xt::arange(0.0, 2.0, 0.01);
  const auto y1_ = xt::sin(2 * M_PI * x_);
  const auto y2_ = 0.8 * xt::sin(4 * M_PI * x_);
  const vector<double> x(x_.begin(), x_.end()), y1(y1_.begin(), y1_.end()),
      y2(y2_.begin(), y2_.end());

  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axes] = plt.subplots(
      3, 1, Kwargs("sharex"_a = true, "figsize"_a = py::make_tuple(6, 6)));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];
  ax1.fill_between(Args(x, y1));
  ax1.set_title(Args("fill between y1 and 0"));

  ax2.fill_between(Args(x, y1, 1));
  ax2.set_title(Args("fill between y1 and 1"));

  ax3.fill_between(Args(x, y1, y2));
  ax3.set_title(Args("fill between y1 and y2"));
  ax3.set_xlabel(Args("x"));
  fig.tight_layout();
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("fill_between_demo_1.png"));
#endif
  return 0;
}

int main2() {
  auto plt = matplotlibcpp17::pyplot::import();

  const vector<double> x = {0, 1, 2, 3};
  const vector<double> y1 = {0.8, 0.8, 0.2, 0.2};
  const vector<double> y2 = {0, 0, 1, 1};
  auto [fig, axs] = plt.subplots(2, 1, Kwargs("sharex"_a = true));
  auto ax1 = axs[0], ax2 = axs[1];

  ax1.set_title(Args("interpolation=False"));
  ax1.plot(Args(x, y1, "o--"));
  ax1.plot(Args(x, y2, "o--"));
  vector<bool> where = {true, true, false, false};
  ax1.fill_between(Args(x, y1, y2), Kwargs("where"_a = where, "color"_a = "C0",
                                           "alpha"_a = 0.3));
  where = {false, false, true, true};
  ax1.fill_between(Args(x, y1, y2), Kwargs("where"_a = where, "color"_a = "C1",
                                           "alpha"_a = 0.3));

  ax2.set_title(Args("interpolation=True"));
  ax2.plot(Args(x, y1, "o--"));
  ax2.plot(Args(x, y2, "o--"));
  where = {true, true, false, false};
  ax2.fill_between(Args(x, y1, y2),
                   Kwargs("where"_a = where, "color"_a = "C0", "alpha"_a = 0.3,
                          "interpolate"_a = true));
  where = {false, false, true, true};
  ax2.fill_between(Args(x, y1, y2),
                   Kwargs("where"_a = where, "color"_a = "C1", "alpha"_a = 0.3,
                          "interpolate"_a = true));
  fig.tight_layout();
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("fill_between_demo_2.png"));
#endif
  return 0;
}

int main3() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();

  const auto x0 = xt::arange(0.0, 4 * M_PI, 0.01);
  const auto y0 = xt::sin(x0);
  vector<double> x(x0.begin(), x0.end()), y(y0.begin(), y0.end());
  ax.plot(Args(x, y), Kwargs("color"_a = "black"));
  const double threshold = 0.75;
  vector<bool> where;
  transform(y.begin(), y.end(), back_inserter(where),
            [&threshold](double y) { return y > threshold; });
  ax.fill_between(Args(x, 0, 1),
                  Kwargs("where"_a = where, "color"_a = "green",
                         "alpha"_a = 0.5,
                         "transform"_a = ax.get_xaxis_transform().unwrap()));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("fill_between_demo_3.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main2();
  main3();
}
