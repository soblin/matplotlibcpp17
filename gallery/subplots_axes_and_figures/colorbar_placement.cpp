// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/colorbar_placement.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xrandom.hpp>

#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main1() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] = plt.subplots(2, 2);
  const vector<string> cmaps = {"RdBu_r", "viridis"};
  for (auto col : {0, 1}) {
    for (auto row : {0, 1}) {
      auto x_ = xt::random::randn<double>({20, 20}) * (col + 1.0);
      vector<vector<double>> x(20);
      for (int i = 0; i < 20; ++i) {
        x[i].resize(20);
        for (int j = 0; j < 20; ++j)
          x[i][j] = x_(i, j);
      }
      auto &ax = axs[col + row * 2];
      auto pcm = ax.pcolormesh(Args(x), Kwargs("cmap"_a = cmaps[col]));
      fig.colorbar(Args(pcm.unwrap()),
                   Kwargs("ax"_a = ax.unwrap(), "shrink"_a = 0.6));
    }
  }
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("colorbar_placement1.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
}
