// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/align_labels_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>

#include <vector>

using namespace std;
using matplotlibcpp17::gridspec::GridSpec;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure(Args(), Kwargs("tight_layout"_a = true));
  auto gs = GridSpec(2, 2);
  // instead of gs[0, :]
  auto ax = fig.add_subplot(Args(gs(0, py::slice(0, 2, 1)).unwrap()));
  const auto tmp_ = xt::arange(0, 1000000, 10000);
  vector<double> tmp(tmp_.begin(), tmp_.end());
  ax.plot(Args(tmp));
  ax.set_ylabel(Args("YLabel0"));
  ax.set_xlabel(Args("XLabel0"));
  for (auto i : {0, 1}) {
    ax = fig.add_subplot(Args(gs(1, i).unwrap()));
    const auto ys_ = xt::arange(1.0, 0.0, -0.1);
    const auto xs_ = ys_ * 2000;
    const vector<double> xs(xs_.begin(), xs_.end()), ys(ys_.begin(), ys_.end());
    ax.plot(Args(xs, ys));
    ax.set_ylabel(Args(string("YLabel1 " + to_string(i))));
    ax.set_xlabel(Args(string("XLabel1 " + to_string(i))));
    if (i == 0) {
      for (auto &&tick : ax.get_xticklabels())
        tick.set_rotation(Args(55));
    }
  }
  fig.align_labels();
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("align_labels_demo.png"));
#endif
}
