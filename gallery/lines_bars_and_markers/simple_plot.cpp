// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/simple_plot.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  const auto t_ = xt::arange(0.0, 2.0, 0.01);
  const auto s_ = xt::sin(2 * M_PI * t_) + 1.0;
  const vector<double> t(t_.begin(), t_.end()), s(s_.begin(), s_.end());

  auto [fig, ax] = plt.subplots();
  ax.plot(Args(t, s), Kwargs("color"_a = "blue", "linewidth"_a = 1.0));
  ax.set(Args(), Kwargs("xlabel"_a = "time (s)", "ylabel"_a = "voltage (mV)",
                        "title"_a = "About as simple as it gets, folks"));
  ax.grid();

#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("simple_plot.png"));
#endif
  return 0;
}
