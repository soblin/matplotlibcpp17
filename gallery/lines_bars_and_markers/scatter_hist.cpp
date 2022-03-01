// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/scatter_hist.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xrandom.hpp>
#include <xtensor/xmath.hpp>

#include <vector>
#include <algorithm>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  int N = 1000;
  auto x_ = xt::random::randn<double>({N});
  auto y_ = xt::random::randn<double>({N});
  vector<double> x(x_.begin(), x_.end()), y(y_.begin(), y_.end());
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  // cell1
  {
    const double left = 0.1, width = 0.65;
    const double bottom = 0.1, height = 0.65;
    const double spacing = 0.005;
    const vector<double> rect_scatter = {left, bottom, width, height};
    const vector<double> rect_histx = {left, bottom + height + spacing, width,
                                       0.2};
    const vector<double> rect_histy = {left + width + spacing, bottom, 0.2,
                                       height};
    auto fig = plt.figure(args_(), kwargs_("figsize"_a = py::make_tuple(8, 8)));
    auto ax = fig.add_axes(args_(rect_scatter));
    auto ax_histx =
        fig.add_axes(args_(rect_histx), kwargs_("sharex"_a = ax.unwrap()));
    auto ax_histy =
        fig.add_axes(args_(rect_histy), kwargs_("sharey"_a = ax.unwrap()));
    ax_histx.tick_params(args_(), kwargs_("axis"_a = "x", "labelbottom"_a = false));
    ax_histy.tick_params(args_(), kwargs_("axis"_a = "y", "labelleft"_a = false));
    ax.scatter(args_(x, y));
    const double binwidth = 0.25;
    auto xi = xt::amax(xt::fabs(x_), {0}), yi = xt::amax(xt::fabs(y_), {0});
    const double xymax = max(fabs(x_[xi]), fabs(y_[yi]));
    const double lim = (static_cast<int>(xymax / binwidth) + 1) * binwidth;
    auto bins_ = xt::arange(-lim, lim + binwidth, binwidth);
    vector<double> bins(bins_.begin(), bins_.end());
    ax_histx.hist(args_(x), kwargs_("bins"_a = bins));
    ax_histy.hist(args_(y),
                  kwargs_("bins"_a = bins, "orientation"_a = "horizontal"));
#if USE_GUI
    plt.show();
#else
    plt.savefig(args_("scatter_hist1.png"));
#endif
  }
  // cell2
  {
    auto fig = plt.figure(args_(), kwargs_("figsize"_a = py::make_tuple(8, 8)));
    auto gs = fig.add_gridspec(2, 2,
                               kwargs_("width_ratios"_a = py::make_tuple(7, 2),
                                       "height_ratios"_a = py::make_tuple(2, 7),
                                       "left"_a = 0.1, "right"_a = 0.9,
                                       "bottom"_a = 0.1, "top"_a = 0.9,
                                       "wspace"_a = 0.05, "hspace"_a = 0.05));
    auto ax = fig.add_subplot(args_(gs(1, 0).unwrap()));
    auto ax_histx = fig.add_subplot(args_(gs(0, 0).unwrap()),
                                    kwargs_("sharex"_a = ax.unwrap()));
    auto ax_histy = fig.add_subplot(args_(gs(1, 1).unwrap()),
                                    kwargs_("sharey"_a = ax.unwrap()));
    ax_histx.tick_params(args_(), kwargs_("axis"_a = "x", "labelbottom"_a = false));
    ax_histy.tick_params(args_(), kwargs_("axis"_a = "y", "labelleft"_a = false));
    ax.scatter(args_(x, y));
    const double binwidth = 0.25;
    auto xi = xt::amax(xt::fabs(x_), {0}), yi = xt::amax(xt::fabs(y_), {0});
    const double xymax = max(fabs(x_[xi]), fabs(y_[yi]));
    const double lim = (static_cast<int>(xymax / binwidth) + 1) * binwidth;
    auto bins_ = xt::arange(-lim, lim + binwidth, binwidth);
    vector<double> bins(bins_.begin(), bins_.end());
    ax_histx.hist(args_(x), kwargs_("bins"_a = bins));
    ax_histy.hist(args_(y),
                  kwargs_("bins"_a = bins, "orientation"_a = "horizontal"));
#if USE_GUI
    plt.show();
#else
    plt.savefig(args_("scatter_hist2.png"));
#endif
  }
  return 0;
}
