// example from https://matplotlib.org/stable/gallery/statistics/hist.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main1() {
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
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] =
      plt.subplots(1, 2, kwargs_("sharey"_a = true, "tight_layout"_a = true));
  auto ax1 = axs[0], ax2 = axs[1];
  auto [N, bins, patches] = ax1.hist(args_(dist1), kwargs_("bins"_a = n_bins));
  // TODO: patches.patches are list of patches::Rectangle.
  ax2.hist(args_(dist2), kwargs_("bins"_a = n_bins));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("hist1.png"));
#endif
  return 0;
}

// int main2() // pass

int main3() {
  int N_points = 100000;
  std::random_device seed_gen;
  std::default_random_engine engine(seed_gen());
  std::normal_distribution<> dist(0.0, 1.0);
  std::vector<double> dist1, dist2;
  for (int i = 0; i < N_points; ++i) {
    dist1.push_back(dist(engine));
    dist2.push_back(0.4 * dist(engine) + 5);
  }

  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, axs] = plt.subplots(1, 1,
                                 kwargs_("figsize"_a = py::make_tuple(5, 5),
                                         "sharex"_a = true, "sharey"_a = true,
                                         "tight_layout"_a = true));
  auto ax1 = axs[0];
  ;
  // We can increase the number of bins on each axis
  ax1.hist2d(args_(dist1, dist2), kwargs_("bins"_a = 40));
  // TODO: more examples
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("hist3.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main3();
  return 0;
}
