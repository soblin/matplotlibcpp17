// example from https://matplotlib.org/stable/gallery/statistics/hist.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xrandom.hpp>

#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main1() {
  int N_points = 100000;
  int n_bins = 20;
  auto dist1_ = xt::random::randn<double>({N_points});
  auto dist2_ = 0.4 * xt::random::randn<double>({N_points}) + 5.0;
  vector<double> dist1(dist1_.begin(), dist1_.end()),
      dist2(dist2_.begin(), dist2_.end());
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] =
      plt.subplots(1, 2, Kwargs("sharey"_a = true, "tight_layout"_a = true));
  auto ax1 = axs[0], ax2 = axs[1];
  auto [N, bins, patches] = ax1.hist(Args(dist1), Kwargs("bins"_a = n_bins));
  // TODO: patches.patches are list of patches::Rectangle.
  ax2.hist(Args(dist2), Kwargs("bins"_a = n_bins));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("hist1.png"));
#endif
  return 0;
}

// int main2() // pass

int main3() {
  int N_points = 100000;
  auto dist1_ = xt::random::randn<double>({N_points});
  auto dist2_ = 0.4 * xt::random::randn<double>({N_points}) + 5.0;
  vector<double> dist1(dist1_.begin(), dist1_.end()),
      dist2(dist2_.begin(), dist2_.end());

  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] =
      plt.subplots(1, 1,
                   Kwargs("figsize"_a = py::make_tuple(5, 5), "sharex"_a = true,
                          "sharey"_a = true, "tight_layout"_a = true));
  auto ax1 = axs[0];
  ;
  // We can increase the number of bins on each axis
  ax1.hist2d(Args(dist1, dist2), Kwargs("bins"_a = 40));
  // TODO: more examples
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("hist3.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main3();
  return 0;
}
