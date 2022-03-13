/**
 * @file pyplot.h
 * @brief corresponding header for matplotlib.pyplot
 **/

#ifndef MATPLOTLIBCPP17_PYPLOT_H
#define MATPLOTLIBCPP17_PYPLOT_H

#include <tuple>

#include <matplotlibcpp17/common.h>
#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/figure.h>

#include <pybind11/pybind11.h>
#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <pybind11/numpy.h>

namespace matplotlibcpp17::pyplot {

/**
 * @brief A class corresponding to pyplot module
 **/
struct DECL_STRUCT_ATTR PyPlot {
public:
  PyPlot() {}
  PyPlot(pybind11::module mod_) {
    mod = mod_;
    load_attrs();
  }
  // axes
  axes::Axes axes(const pybind11::dict &kwargs = pybind11::dict());

  // axis
  pybind11::object axis(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // cla
  pybind11::object cla(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // clf
  pybind11::object clf(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // errorbar
  pybind11::object errorbar(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // figaspect
  std::tuple<double, double>
  figaspect(const pybind11::tuple &args = pybind11::tuple(),
            const pybind11::dict &kwargs = pybind11::dict());

  // figure
  figure::Figure figure(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // gca
  axes::Axes gca(const pybind11::tuple &args = pybind11::tuple(),
                 const pybind11::dict &kwargs = pybind11::dict());

  // gcf
  figure::Figure gcf(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // grid
  pybind11::object grid(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // legend
  pybind11::object legend(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // pause
  pybind11::object pause(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // plot
  pybind11::object plot(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // quiver
  pybind11::object quiver(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // savefig
  pybind11::object savefig(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // scatter
  pybind11::object scatter(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // show
  pybind11::object show(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // step
  pybind11::object step(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // subplot
  axes::Axes subplot(const pybind11::dict &kwargs = pybind11::dict());
  axes::Axes subplot(int cri);

  // subplots
  std::tuple<figure::Figure, axes::Axes>
  subplots(const pybind11::dict &kwargs = pybind11::dict());
  std::tuple<figure::Figure, std::vector<axes::Axes>>
  subplots(int r, int c, const pybind11::dict &kwargs = pybind11::dict());

  // title
  pybind11::object title(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // xlabel
  pybind11::object xlabel(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // xlim
  pybind11::object xlim(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // ylabel
  pybind11::object ylabel(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // ylim
  pybind11::object ylim(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() {
    LOAD_FUNC_ATTR(axes, mod);
    LOAD_FUNC_ATTR(axis, mod);
    LOAD_FUNC_ATTR(cla, mod);
    LOAD_FUNC_ATTR(clf, mod);
    LOAD_FUNC_ATTR(errorbar, mod);
    LOAD_FUNC_ATTR(figaspect, mod);
    LOAD_FUNC_ATTR(figure, mod);
    LOAD_FUNC_ATTR(gca, mod);
    LOAD_FUNC_ATTR(gcf, mod);
    LOAD_FUNC_ATTR(grid, mod);
    LOAD_FUNC_ATTR(legend, mod);
    LOAD_FUNC_ATTR(pause, mod);
    LOAD_FUNC_ATTR(plot, mod);
    LOAD_FUNC_ATTR(quiver, mod);
    LOAD_FUNC_ATTR(savefig, mod);
    LOAD_FUNC_ATTR(scatter, mod);
    LOAD_FUNC_ATTR(show, mod);
    LOAD_FUNC_ATTR(step, mod);
    LOAD_FUNC_ATTR(subplot, mod);
    LOAD_FUNC_ATTR(subplots, mod);
    LOAD_FUNC_ATTR(title, mod);
    LOAD_FUNC_ATTR(xlabel, mod);
    LOAD_FUNC_ATTR(xlim, mod);
    LOAD_FUNC_ATTR(ylabel, mod);
    LOAD_FUNC_ATTR(ylim, mod);
  }
  pybind11::module mod;
  pybind11::object axes_attr;
  pybind11::object axis_attr;
  pybind11::object cla_attr;
  pybind11::object clf_attr;
  pybind11::object errorbar_attr;
  pybind11::object figaspect_attr;
  pybind11::object figure_attr;
  pybind11::object gca_attr;
  pybind11::object gcf_attr;
  pybind11::object grid_attr;
  pybind11::object legend_attr;
  pybind11::object pause_attr;
  pybind11::object plot_attr;
  pybind11::object quiver_attr;
  pybind11::object savefig_attr;
  pybind11::object scatter_attr;
  pybind11::object show_attr;
  pybind11::object step_attr;
  pybind11::object subplot_attr;
  pybind11::object subplots_attr;
  pybind11::object title_attr;
  pybind11::object xlabel_attr;
  pybind11::object xlim_attr;
  pybind11::object ylabel_attr;
  pybind11::object ylim_attr;
};

// axes
axes::Axes PyPlot::axes(const pybind11::dict &kwargs) {
  pybind11::object ax_obj = axes_attr(**kwargs);
  return axes::Axes(ax_obj);
}

// axis
pybind11::object PyPlot::axis(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = axis_attr(*args, **kwargs);
  return ret;
}

// cla
pybind11::object PyPlot::cla(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = cla_attr(*args, **kwargs);
  return ret;
}

// clf
pybind11::object PyPlot::clf(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = clf_attr(*args, **kwargs);
  return ret;
}

// errorbar
pybind11::object PyPlot::errorbar(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = errorbar_attr(*args, **kwargs);
  return ret;
}

// figaspect
std::tuple<double, double> PyPlot::figaspect(const pybind11::tuple &args,
                                             const pybind11::dict &kwargs) {
  pybind11::list l = figaspect_attr(*args, **kwargs);
  double width = l[0].cast<double>();
  double height = l[1].cast<double>();
  return {width, height};
}

// figure
figure::Figure PyPlot::figure(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object fig_obj = figure_attr(*args, **kwargs);
  return figure::Figure(fig_obj);
}

// gca
axes::Axes PyPlot::gca(const pybind11::tuple &args,
                       const pybind11::dict &kwargs) {
  pybind11::object obj = gca_attr(*args, **kwargs);
  return axes::Axes(obj);
}

// gcf
figure::Figure PyPlot::gcf(const pybind11::tuple &args,
                           const pybind11::dict &kwargs) {
  pybind11::object obj = gcf_attr(*args, **kwargs);
  return figure::Figure(obj);
}

// grid
pybind11::object PyPlot::grid(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object obj = grid_attr(*args, **kwargs);
  return obj;
}

// legend
pybind11::object PyPlot::legend(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = legend_attr(*args, **kwargs);
  return ret;
}

// pause
pybind11::object PyPlot::pause(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = pause_attr(*args, **kwargs);
  return ret;
}

// plot
pybind11::object PyPlot::plot(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = plot_attr(*args, **kwargs);
  return ret;
}

// quiver
pybind11::object PyPlot::quiver(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = quiver_attr(*args, **kwargs);
  return ret;
}

// scatter
pybind11::object PyPlot::scatter(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = scatter_attr(*args, **kwargs);
  return ret;
}

// savefig
pybind11::object PyPlot::savefig(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = savefig_attr(*args, **kwargs);
  return ret;
}

// show
pybind11::object PyPlot::show(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = show_attr(*args, **kwargs);
  return ret;
}

// step
pybind11::object PyPlot::step(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = step_attr(*args, **kwargs);
  return ret;
}

// subplot
axes::Axes PyPlot::subplot(const pybind11::dict &kwargs) {
  return axes::Axes(subplot_attr(**kwargs));
}

axes::Axes PyPlot::subplot(int cri) {
  pybind11::object obj = subplot_attr(cri);
  return axes::Axes(obj);
}

// subplots
std::tuple<figure::Figure, axes::Axes>
PyPlot::subplots(const pybind11::dict &kwargs) {
  pybind11::list ret = subplots_attr(**kwargs);
  pybind11::object fig = ret[0];
  pybind11::object ax = ret[1];
  return {figure::Figure(fig), axes::Axes(ax)};
}

std::tuple<figure::Figure, std::vector<axes::Axes>>
PyPlot::subplots(int r, int c, const pybind11::dict &kwargs) {
  // subplots() returns [][] (if r > 1 && c > 1) else []
  // return []axes in row-major
  // NOTE: equal to Axes.flat
  pybind11::tuple args = pybind11::make_tuple(r, c);
  pybind11::list ret = subplots_attr(*args, **kwargs);
  std::vector<axes::Axes> axes;
  pybind11::object fig = ret[0];
  figure::Figure figure(fig);
  if (r == 1 and c == 1) {
    // python returns Axes
    axes.push_back(axes::Axes(ret[1]));
  } else if (r == 1 or c == 1) {
    // python returns []Axes
    pybind11::list axs = ret[1];
    for (int i = 0; i < r * c; ++i)
      axes.push_back(axes::Axes(axs[i]));
  } else {
    // python returns [][]Axes
    pybind11::list axs = ret[1];
    for (pybind11::size_t i = 0; i < axs.size(); ++i) {
      pybind11::list axsi = axs[i];
      for (unsigned j = 0; j < axsi.size(); ++j)
        axes.push_back(axes::Axes(axsi[j]));
    }
  }
  return {figure, axes};
}

// title
pybind11::object PyPlot::title(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = title_attr(*args, **kwargs);
  return ret;
}

// xlabel
pybind11::object PyPlot::xlabel(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = xlabel_attr(*args, **kwargs);
  return ret;
}

// xlim
pybind11::object PyPlot::xlim(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = xlim_attr(*args, **kwargs);
  return ret;
}

// ylabel
pybind11::object PyPlot::ylabel(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = ylabel_attr(*args, **kwargs);
  return ret;
}

// ylim
pybind11::object PyPlot::ylim(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = ylim_attr(*args, **kwargs);
  return ret;
}

PyPlot import() {
  auto mod = pybind11::module::import("matplotlib.pyplot");
  auto g_pyplot = PyPlot(mod);
  return g_pyplot;
}

} // namespace matplotlibcpp17::pyplot

// Args & Kwargs
template <typename... ArgsT> pybind11::tuple Args(ArgsT &&... args) {
  return pybind11::make_tuple(std::forward<ArgsT>(args)...);
}

using Kwargs = pybind11::dict;

// Export this
namespace py = pybind11;
using namespace py::literals;

#endif /* MATPLOTLIBCPP17_PYPLOT_H */
