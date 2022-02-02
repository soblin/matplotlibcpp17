// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/scatter_with_legend.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <algorithm>
#include <vector>
#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17::util;

int main1() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::uniform_real_distribution<> dist(0.0, 1.0);
  for (auto &&color : {"tab:blue", "tab:orange", "tab:green"}) {
    int n = 750;
    vector<double> x, y, scale;
    for (int i = 0; i < n; ++i) {
      x.push_back(dist(engine));
      y.push_back(dist(engine));
      scale.push_back(200 * dist(engine));
    }
    ax.scatter(args_(x, y),
               kwargs_("s"_a = scale, "c"_a = color, "label"_a = color,
                       "alpha"_a = 0.3, "edgecolors"_a = "none"));
  }
  ax.legend();
  ax.grid(true);
#if USE_GUI
  plt.show();
#else
  plt.savefig("scatter_with_legend1.png");
#endif
  return 0;
}

int main2() {
  int N = 45;
  vector<double> x, y;
  vector<int> c, s;
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  {
    std::uniform_real_distribution<> dist(0.0, 1.0);
    for (int i = 0; i < N; ++i) {
      x.push_back(dist(engine));
      y.push_back(dist(engine));
    }
  }
  {
    std::uniform_int_distribution<> dist(1, 5);
    for (int i = 0; i < N; ++i) {
      c.push_back(dist(engine));
    }
  }
  {
    std::uniform_int_distribution<> dist(10, 220);
    for (int i = 0; i < N; ++i) {
      s.push_back(dist(engine));
    }
  }
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto scatter = ax.scatter(args_(x, y), kwargs_("c"_a = c, "s"_a = s));
  {
    auto [handles, labels] = scatter.legend_elements();
    auto legend1 =
        ax.legend(args_(handles, labels),
                  kwargs_("loc"_a = "lower left", "title"_a = "Classes"));
    ax.add_artist(legend1.unwrap());
  }
  {
    auto [handles, labels] = scatter.legend_elements(
        py::tuple(), kwargs_("prop"_a = "sizes", "alpha"_a = 0.6));
    auto legend2 =
        ax.legend(args_(handles, labels),
                  kwargs_("loc"_a = "upper right", "title"_a = "Sizes"));
  }
#if USE_GUI
  plt.show();
#else
  plt.savefig("scatter_with_legend2.png");
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main2();
}
