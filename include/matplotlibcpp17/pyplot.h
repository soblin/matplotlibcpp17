/**
 * @file pyplot.h
 * @brief corresponding header for matplotlib.pyplot
 **/
#pragma once

#include <tuple>

#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/common.h>
#include <matplotlibcpp17/figure.h>

#include <pybind11/embed.h>
#include <pybind11/numpy.h>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

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
  ObjectWrapper axis(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // cla
  ObjectWrapper cla(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict());

  // clf
  ObjectWrapper clf(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict());

  // clim
  ObjectWrapper clim(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // colorbar
  ObjectWrapper colorbar(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // errorbar
  ObjectWrapper errorbar(const pybind11::tuple &args = pybind11::tuple(),
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

  // gci
  ObjectWrapper gci(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict());

  // grid
  ObjectWrapper grid(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // imshow
  ObjectWrapper imshow(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // legend
  ObjectWrapper legend(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // pause
  ObjectWrapper pause(const pybind11::tuple &args = pybind11::tuple(),
                      const pybind11::dict &kwargs = pybind11::dict());

  // plot
  ObjectWrapper plot(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // quiver
  ObjectWrapper quiver(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // savefig
  ObjectWrapper savefig(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // scatter
  ObjectWrapper scatter(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // show
  ObjectWrapper show(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // step
  ObjectWrapper step(const pybind11::tuple &args = pybind11::tuple(),
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
  ObjectWrapper title(const pybind11::tuple &args = pybind11::tuple(),
                      const pybind11::dict &kwargs = pybind11::dict());

  // xlabel
  ObjectWrapper xlabel(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // xlim
  ObjectWrapper xlim(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // ylabel
  ObjectWrapper ylabel(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // ylim
  ObjectWrapper ylim(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() {
    LOAD_FUNC_ATTR(axes, mod);
    LOAD_FUNC_ATTR(axis, mod);
    LOAD_FUNC_ATTR(cla, mod);
    LOAD_FUNC_ATTR(clf, mod);
    LOAD_FUNC_ATTR(clim, mod);
    LOAD_FUNC_ATTR(colorbar, mod);
    LOAD_FUNC_ATTR(errorbar, mod);
    LOAD_FUNC_ATTR(figaspect, mod);
    LOAD_FUNC_ATTR(figure, mod);
    LOAD_FUNC_ATTR(gca, mod);
    LOAD_FUNC_ATTR(gcf, mod);
    LOAD_FUNC_ATTR(gci, mod);
    LOAD_FUNC_ATTR(grid, mod);
    LOAD_FUNC_ATTR(imshow, mod);
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
  pybind11::object clim_attr;
  pybind11::object colorbar_attr;
  pybind11::object errorbar_attr;
  pybind11::object figaspect_attr;
  pybind11::object figure_attr;
  pybind11::object gca_attr;
  pybind11::object gcf_attr;
  pybind11::object gci_attr;
  pybind11::object grid_attr;
  pybind11::object imshow_attr;
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
inline axes::Axes PyPlot::axes(const pybind11::dict &kwargs) {
  pybind11::object ax_obj = axes_attr(**kwargs);
  return axes::Axes(ax_obj);
}

// axis
inline ObjectWrapper PyPlot::axis(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = axis_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// cla
inline ObjectWrapper PyPlot::cla(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = cla_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// clf
inline ObjectWrapper PyPlot::clf(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = clf_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// clim
inline ObjectWrapper PyPlot::clim(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = clim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// colorbar
inline ObjectWrapper PyPlot::colorbar(const pybind11::tuple &args,
                                      const pybind11::dict &kwargs) {
  pybind11::object ret = colorbar_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// errorbar
inline ObjectWrapper PyPlot::errorbar(const pybind11::tuple &args,
                                      const pybind11::dict &kwargs) {
  pybind11::object ret = errorbar_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// figaspect
inline std::tuple<double, double>
PyPlot::figaspect(const pybind11::tuple &args, const pybind11::dict &kwargs) {
  pybind11::list l = figaspect_attr(*args, **kwargs);
  double width = l[0].cast<double>();
  double height = l[1].cast<double>();
  return {width, height};
}

// figure
inline figure::Figure PyPlot::figure(const pybind11::tuple &args,
                                     const pybind11::dict &kwargs) {
  pybind11::object fig_obj = figure_attr(*args, **kwargs);
  return figure::Figure(fig_obj);
}

// gca
inline axes::Axes PyPlot::gca(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object obj = gca_attr(*args, **kwargs);
  return axes::Axes(obj);
}

// gcf
inline figure::Figure PyPlot::gcf(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = gcf_attr(*args, **kwargs);
  return figure::Figure(obj);
}

// gci
inline ObjectWrapper PyPlot::gci(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object obj = gci_attr(*args, **kwargs);
  return obj;
}

// grid
inline ObjectWrapper PyPlot::grid(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = grid_attr(*args, **kwargs);
  return obj;
}

// imshow
inline ObjectWrapper PyPlot::imshow(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object obj = imshow_attr(*args, **kwargs);
  return obj;
}

// legend
inline ObjectWrapper PyPlot::legend(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = legend_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// pause
inline ObjectWrapper PyPlot::pause(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = pause_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// plot
inline ObjectWrapper PyPlot::plot(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = plot_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// quiver
inline ObjectWrapper PyPlot::quiver(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = quiver_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// scatter
inline ObjectWrapper PyPlot::scatter(const pybind11::tuple &args,
                                     const pybind11::dict &kwargs) {
  pybind11::object ret = scatter_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// savefig
inline ObjectWrapper PyPlot::savefig(const pybind11::tuple &args,
                                     const pybind11::dict &kwargs) {
  pybind11::object ret = savefig_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// show
inline ObjectWrapper PyPlot::show(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = show_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// step
inline ObjectWrapper PyPlot::step(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = step_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// subplot
inline axes::Axes PyPlot::subplot(const pybind11::dict &kwargs) {
  return axes::Axes(subplot_attr(**kwargs));
}

inline axes::Axes PyPlot::subplot(int cri) {
  pybind11::object obj = subplot_attr(cri);
  return axes::Axes(obj);
}

// subplots
inline std::tuple<figure::Figure, axes::Axes>
PyPlot::subplots(const pybind11::dict &kwargs) {
  pybind11::list ret = subplots_attr(**kwargs);
  pybind11::object fig = ret[0];
  pybind11::object ax = ret[1];
  return {figure::Figure(fig), axes::Axes(ax)};
}

inline std::tuple<figure::Figure, std::vector<axes::Axes>>
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
inline ObjectWrapper PyPlot::title(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = title_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// xlabel
inline ObjectWrapper PyPlot::xlabel(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = xlabel_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// xlim
inline ObjectWrapper PyPlot::xlim(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = xlim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// ylabel
inline ObjectWrapper PyPlot::ylabel(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = ylabel_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// ylim
inline ObjectWrapper PyPlot::ylim(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = ylim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

inline PyPlot import() {
  auto mod = pybind11::module::import("matplotlib.pyplot");
  auto g_pyplot = PyPlot(mod);
  return g_pyplot;
}

} // namespace matplotlibcpp17::pyplot

// Args & Kwargs
template <typename... ArgsT> pybind11::tuple Args(ArgsT &&...args) {
  return pybind11::make_tuple(std::forward<ArgsT>(args)...);
}

using Kwargs = pybind11::dict;

// Export this
namespace py = pybind11;
using namespace py::literals;
