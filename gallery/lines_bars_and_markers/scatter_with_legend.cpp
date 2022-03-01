// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/scatter_with_legend.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xrandom.hpp>
#include <xtensor/xview.hpp>

#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main1() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  for (auto &&color : {"tab:blue", "tab:orange", "tab:green"}) {
    int n = 750;
    auto xy = xt::random::rand<double>({2, n});
    auto x_ = xt::view(xy, 0, xt::all()), y_ = xt::view(xy, 1, xt::all());
    auto scale_ = xt::random::rand<double>({n}) * 200;
    vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end()),
        scale(scale_.begin(), scale_.end());
    ax.scatter(Args(x, y),
               Kwargs("s"_a = scale, "c"_a = color, "label"_a = color,
                      "alpha"_a = 0.3, "edgecolors"_a = "none"));
  }
  ax.legend();
  ax.grid(Args(true));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("scatter_with_legend1.png"));
#endif
  return 0;
}

int main2() {
  int N = 45;
  auto x_ = xt::random::rand<double>({N}, 0.0, 1.0);
  auto y_ = xt::random::rand<double>({N}, 0.0, 1.0);
  auto c_ = xt::random::randint({N}, 1, 5);
  auto s_ = xt::random::randint({N}, 10, 220);
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end());
  vector<int> c(c_.begin(), c_.end()), s(s_.begin(), s_.end());
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto scatter = ax.scatter(Args(x, y), Kwargs("c"_a = c, "s"_a = s));
  {
    auto [handles, labels] = scatter.legend_elements();
    auto legend1 =
        ax.legend(Args(handles, labels),
                  Kwargs("loc"_a = "lower left", "title"_a = "Classes"));
    ax.add_artist(Args(legend1.unwrap()));
  }
  {
    auto [handles, labels] = scatter.legend_elements(
        Args(), Kwargs("prop"_a = "sizes", "alpha"_a = 0.6));
    auto legend2 =
        ax.legend(Args(handles, labels),
                  Kwargs("loc"_a = "upper right", "title"_a = "Sizes"));
  }
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("scatter_with_legend2.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main2();
}
