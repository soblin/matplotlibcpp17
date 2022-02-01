// example from https://matplotlib.org/stable/gallery/statistics/hist.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17::util;

int main() {
  int N_points = 100000;
  int n_bins = 20;
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::normal_distribution<> dist(0.0, 1.0);
  std::vector<double> dist1, dist2;
  for (int i = 0; i < N_points; ++i) {
    dist1.push_back(dist(engine));
    dist2.push_back(0.4 * dist(engine) + 5);
  }
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] =
      plt.subplots(1, 2, kwargs_("sharey"_a = true, "tight_layout"_a = true));
  auto ax1 = axs[0], ax2 = axs[1];
  ax1.hist(dist1, "bins"_a = n_bins);
  ax2.hist(dist2, "bins"_a = n_bins);
  plt.show();
  return 0;
}
