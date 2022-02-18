// example from
// https://matplotlib.org/stable/gallery/subplots_axes_and_figures/gridspec_multicolumn.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <vector>

namespace py = pybind11;
using namespace py::literals;

using namespace std;

using matplotlibcpp17::gridspec::GridSpec;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();

  auto fig = plt.figure(args_(), kwargs_("constrained_layout"_a = true));

  auto gs = GridSpec(3, 3, kwargs_("figure"_a = fig.unwrap()));
  vector<axes::Axes> axs;
  axs.push_back(fig.add_subplot(args_(gs(0, py::slice(0, 3, 1)).unwrap())));
  axs.push_back(fig.add_subplot(args_(gs(1, py::slice(0, 2, 1)).unwrap())));
  axs.push_back(fig.add_subplot(args_(gs(py::slice(1, 3, 1), 2).unwrap())));
  axs.push_back(fig.add_subplot(args_(gs(2, 0).unwrap())));
  axs.push_back(fig.add_subplot(args_(gs(2, 1).unwrap())));
  fig.suptitle(args_("GridSpec"));

  int cnt = 1;
  for (auto &ax : axs) {
    ax.text(args_(0.5, 0.5, string("ax" + to_string(cnt))),
            kwargs_("va"_a = "center", "ha"_a = "center"));
    ax.tick_params(args_(),
                   kwargs_("labelbottom"_a = false, "labelleft"_a = false));
    cnt++;
  }

#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("gridspec_multicolumn.png"));
#endif
}
