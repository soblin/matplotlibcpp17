/**
 * @file axes.h
 * @brief corresponding header for matplotlib.axes
 **/

#ifndef MATPLOTLIBCPP17_AXES_H
#define MATPLOTLIBCPP17_AXES_H

#include <vector>
#include <tuple>

#include <matplotlibcpp17/common.h>
#include <matplotlibcpp17/collections.h>
#include <matplotlibcpp17/container.h>
#include <matplotlibcpp17/legend.h>
#include <matplotlibcpp17/quiver.h>
#include <matplotlibcpp17/text.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::axes {

/**
 * @brief Return type for hist()
 **/
using HistType = std::tuple<std::vector<double>, std::vector<double>,
                            container::BarContainer>;

/**
 * @brief A wrapper class for matplotlib.axes.Axes
 **/
struct DECL_STRUCT_ATTR Axes : public BaseWrapper {
public:
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }

  // add_artist
  pybind11::object add_artist(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // add_collection
  pybind11::object
  add_collection(const pybind11::tuple &args = pybind11::tuple(),
                 const pybind11::dict &kwargs = pybind11::dict());

  // add_patch
  pybind11::object add_patch(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // axhline
  pybind11::object axhline(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // bar
  container::BarContainer bar(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // bar_label
  pybind11::object bar_label(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // barh
  container::BarContainer barh(const pybind11::tuple &args = pybind11::tuple(),
                               const pybind11::dict &kwargs = pybind11::dict());

  // contour
  pybind11::object contour(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // errorbar
  pybind11::object errorbar(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // fill
  pybind11::object fill(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // fill_between
  pybind11::object
  fill_between(const pybind11::tuple &args = pybind11::tuple(),
               const pybind11::dict &kwargs = pybind11::dict());

  // fill_betweenx
  pybind11::object
  fill_betweenx(const pybind11::tuple &args = pybind11::tuple(),
                const pybind11::dict &kwargs = pybind11::dict());

  // get_lines
  pybind11::object get_lines(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // get_xaxis_transform
  pybind11::object
  get_xaxis_transform(const pybind11::tuple &args = pybind11::tuple(),
                      const pybind11::dict &kwargs = pybind11::dict());

  // get_xlim
  std::tuple<double, double> get_xlim();

  // get_xticklabels
  std::vector<text::Text> get_xticklabels();

  // grid
  pybind11::object grid(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // hist
  HistType hist(const pybind11::tuple &args = pybind11::tuple(),
                const pybind11::dict &kwargs = pybind11::dict());

  // hist2d
  pybind11::object hist2d(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // invert_yaxis
  pybind11::object
  invert_yaxis(const pybind11::tuple &args = pybind11::tuple(),
               const pybind11::dict &kwargs = pybind11::dict());

  // legend
  legend::Legend legend(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // plot
  pybind11::object plot(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // plot_surface
  pybind11::object
  plot_surface(const pybind11::tuple &args = pybind11::tuple(),
               const pybind11::dict &kwargs = pybind11::dict());

  // plot_wireframe
  pybind11::object
  plot_wireframe(const pybind11::tuple &args = pybind11::tuple(),
                 const pybind11::dict &kwargs = pybind11::dict());

  // quiver
  quiver::Quiver quiver(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // quiverkey
  quiver::QuiverKey quiverkey(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // scatter
  collections::PathCollection
  scatter(const pybind11::tuple &args = pybind11::tuple(),
          const pybind11::dict &kwargs = pybind11::dict());

  // set
  pybind11::object set(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // set_aspect
  pybind11::object set_aspect(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_title
  pybind11::object set_title(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // set_xlabel
  pybind11::object set_xlabel(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_xlim
  pybind11::object set_xlim(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // set_xticks
  pybind11::object set_xticks(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_xticklabels
  pybind11::object
  set_xticklabels(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict());

  // set_ylabel
  pybind11::object set_ylabel(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_ylim
  pybind11::object set_ylim(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // set_yticks
  pybind11::object set_yticks(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_zlabel
  pybind11::object set_zlabel(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // set_zlim
  pybind11::object set_zlim(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // text
  pybind11::object text(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // tick_params
  pybind11::object tick_params(const pybind11::tuple &args = pybind11::tuple(),
                               const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() {
    LOAD_FUNC_ATTR(add_artist, self);
    LOAD_FUNC_ATTR(add_collection, self);
    LOAD_FUNC_ATTR(add_patch, self);
    LOAD_FUNC_ATTR(axhline, self);
    LOAD_FUNC_ATTR(bar, self);
#if MATPLOTLIB_MINOR_VER_GTE_4
    LOAD_FUNC_ATTR(bar_label, self);
#else
    WARN_MSG("Not loading bar_label because matplotlib version is < 3.4.0");
#endif
    LOAD_FUNC_ATTR(barh, self);
    LOAD_FUNC_ATTR(contour, self);
    LOAD_FUNC_ATTR(errorbar, self);
    LOAD_FUNC_ATTR(fill, self);
    LOAD_FUNC_ATTR(fill_between, self);
    LOAD_FUNC_ATTR(fill_betweenx, self);
    LOAD_FUNC_ATTR(get_lines, self);
    LOAD_FUNC_ATTR(get_xaxis_transform, self);
    LOAD_FUNC_ATTR(get_xlim, self);
    LOAD_FUNC_ATTR(get_xticklabels, self);
    LOAD_FUNC_ATTR(grid, self);
    LOAD_FUNC_ATTR(hist, self);
    LOAD_FUNC_ATTR(hist2d, self);
    LOAD_FUNC_ATTR(invert_yaxis, self);
    LOAD_FUNC_ATTR(legend, self);
    LOAD_FUNC_ATTR(plot, self);
    // NOTE: only when called with projection='3d', `plot_surface`, `plot_wireframe`, `set_zlabel` prop exists.
    try {
      plot_surface_attr = self.attr("plot_surface");
      plot_wireframe_attr = self.attr("plot_wireframe");
      set_zlabel_attr = self.attr("set_zlabel");
      INFO_MSG("Loaded Axes3D");
      projection_3d = true;
    } catch (...) {
      projection_3d = false;
    }
    LOAD_FUNC_ATTR(quiver, self);
    LOAD_FUNC_ATTR(quiverkey, self);
    LOAD_FUNC_ATTR(scatter, self);
    LOAD_FUNC_ATTR(set, self);
    LOAD_FUNC_ATTR(set_aspect, self);
    LOAD_FUNC_ATTR(set_title, self);
    LOAD_FUNC_ATTR(set_xlabel, self);
    LOAD_FUNC_ATTR(set_xlim, self);
    LOAD_FUNC_ATTR(set_xticks, self);
    LOAD_FUNC_ATTR(set_xticklabels, self);
    LOAD_FUNC_ATTR(set_ylabel, self);
    LOAD_FUNC_ATTR(set_ylim, self);
    LOAD_FUNC_ATTR(set_yticks, self);
    LOAD_FUNC_ATTR(set_zlim, self);
    LOAD_FUNC_ATTR(text, self);
    LOAD_FUNC_ATTR(tick_params, self);
  }
  pybind11::object add_artist_attr;
  pybind11::object add_collection_attr;
  pybind11::object add_patch_attr;
  pybind11::object axhline_attr;
  pybind11::object bar_attr;
  pybind11::object bar_label_attr;
  pybind11::object barh_attr;
  pybind11::object contour_attr;
  pybind11::object errorbar_attr;
  pybind11::object fill_attr;
  pybind11::object fill_between_attr;
  pybind11::object fill_betweenx_attr;
  pybind11::object get_lines_attr;
  pybind11::object get_xaxis_transform_attr;
  pybind11::object get_xlim_attr;
  pybind11::object get_xticklabels_attr;
  pybind11::object grid_attr;
  pybind11::object hist_attr;
  pybind11::object hist2d_attr;
  pybind11::object invert_yaxis_attr;
  pybind11::object legend_attr;
  pybind11::object plot_attr;
  pybind11::object plot_surface_attr;
  pybind11::object plot_wireframe_attr;
  pybind11::object quiver_attr;
  pybind11::object quiverkey_attr;
  pybind11::object scatter_attr;
  pybind11::object set_attr;
  pybind11::object set_aspect_attr;
  pybind11::object set_title_attr;
  pybind11::object set_xlabel_attr;
  pybind11::object set_xlim_attr;
  pybind11::object set_xticks_attr;
  pybind11::object set_xticklabels_attr;
  pybind11::object set_ylabel_attr;
  pybind11::object set_ylim_attr;
  pybind11::object set_yticks_attr;
  pybind11::object set_zlabel_attr;
  pybind11::object set_zlim_attr;
  pybind11::object text_attr;
  pybind11::object tick_params_attr;
  bool projection_3d;
};

// add_artist
pybind11::object Axes::add_artist(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = add_artist_attr(*args, **kwargs);
  return ret;
}

// add_collection
pybind11::object Axes::add_collection(const pybind11::tuple &args,
                                      const pybind11::dict &kwargs) {
  pybind11::object ret = add_collection_attr(*args, **kwargs);
  return ret;
}

// add_patch
pybind11::object Axes::add_patch(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = add_patch_attr(*args, **kwargs);
  return ret;
}

// axhline
pybind11::object Axes::axhline(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = axhline_attr(*args, **kwargs);
  return ret;
}

// bar
container::BarContainer Axes::bar(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = bar_attr(*args, **kwargs);
  return container::BarContainer(obj);
}

// bar_label
pybind11::object Axes::bar_label(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
#if MATPLOTLIB_MINOR_VER_GTE_4
  pybind11::object ret = bar_label_attr(*args, **kwargs);
  return ret;
#else
  ERROR_MSG(
      "Call to bar_label is invalid because matplotlib version is < 3.4.0");
  std::exit(0);
#endif
}

// barh
container::BarContainer Axes::barh(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object obj = barh_attr(*args, **kwargs);
  return container::BarContainer(obj);
}

// contour
pybind11::object Axes::contour(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object obj = contour_attr(*args, **kwargs);
  return obj;
}

// errorbar
pybind11::object Axes::errorbar(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  if (projection_3d) {
#if MATPLOTLIB_MINOR_VER_GTE_4
    pybind11::object obj = errorbar_attr(*args, **kwargs);
    return obj;
#else
    ERROR_MSG("Call to errorbar with projection='3d' is invalid because "
              "matplotlib version is < 3.4.0");
    std::exit(0);
#endif
  } else {
    pybind11::object obj = errorbar_attr(*args, **kwargs);
    return obj;
  }
}

// fill
pybind11::object Axes::fill(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = fill_attr(*args, **kwargs);
  return ret;
}

// fill_between
pybind11::object Axes::fill_between(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = fill_between_attr(*args, **kwargs);
  return ret;
}

// fill_betweenx
pybind11::object Axes::fill_betweenx(const pybind11::tuple &args,
                                     const pybind11::dict &kwargs) {
  pybind11::object ret = fill_betweenx_attr(*args, **kwargs);
  return ret;
}

// get_lines
pybind11::object Axes::get_lines(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = get_lines_attr(*args, **kwargs);
  return ret;
}

// get_xaxis_transform
pybind11::object Axes::get_xaxis_transform(const pybind11::tuple &args,
                                           const pybind11::dict &kwargs) {
  pybind11::object ret = get_xaxis_transform_attr(*args, **kwargs);
  return ret;  
}

// get_xlim
std::tuple<double, double> Axes::get_xlim() {
  pybind11::list ret = get_xlim_attr();
  double x1 = ret[0].cast<double>();
  double x2 = ret[1].cast<double>();
  return {x1, x2};
}

// get_xticklabels
std::vector<text::Text> Axes::get_xticklabels() {
  pybind11::list ret = get_xticklabels_attr();
  std::vector<text::Text> texts;
  for (pybind11::size_t i = 0; i < ret.size(); ++i) {
    texts.push_back(text::Text(ret[i]));
  }
  return texts;
}

// grid
pybind11::object Axes::grid(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = grid_attr(*args, **kwargs);
  return ret;
}

// hist
std::tuple<std::vector<double>, std::vector<double>, container::BarContainer>
Axes::hist(const pybind11::tuple &args, const pybind11::dict &kwargs) {
  pybind11::list ret = hist_attr(*args, **kwargs);
  // parse N, bins, patches
  pybind11::list N_obj = ret[0], bins_obj = ret[1];
  pybind11::object patches_obj = ret[2];
  std::vector<double> N, bins;
  for (auto it = N_obj.begin(); it != N_obj.end(); it++) {
    N.push_back(it->cast<double>());
  }
  for (auto it = bins_obj.begin(); it != bins_obj.end(); it++) {
    bins.push_back(it->cast<double>());
  }
  return {N, bins, container::BarContainer(patches_obj)};
}

// hist2d
pybind11::object Axes::hist2d(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = hist2d_attr(*args, **kwargs);
  return ret;
}

// invert_yaxis
pybind11::object Axes::invert_yaxis(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = invert_yaxis_attr(*args, **kwargs);
  return ret;
}

// legend
legend::Legend Axes::legend(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object obj = legend_attr(*args, **kwargs);
  return legend::Legend(obj);
}

// plot
pybind11::object Axes::plot(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = plot_attr(*args, **kwargs);
  return ret;
}

// plot_surface
pybind11::object Axes::plot_surface(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = plot_surface_attr(*args, **kwargs);
  return ret;
}

// plot_wireframe
pybind11::object Axes::plot_wireframe(const pybind11::tuple &args,
                                      const pybind11::dict &kwargs) {
  pybind11::object ret = plot_wireframe_attr(*args, **kwargs);
  return ret;
}

// quiver
quiver::Quiver Axes::quiver(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object obj = quiver_attr(*args, **kwargs);
  return quiver::Quiver(obj);
}

// quiverkey
quiver::QuiverKey Axes::quiverkey(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = quiverkey_attr(*args, **kwargs);
  return quiver::QuiverKey(obj);
}

// scatter
collections::PathCollection Axes::scatter(const pybind11::tuple &args,
                                          const pybind11::dict &kwargs) {
  pybind11::object obj = scatter_attr(*args, **kwargs);
  return collections::PathCollection(obj);
}

// set
pybind11::object Axes::set(const pybind11::tuple &args,
                           const pybind11::dict &kwargs) {
  pybind11::object ret = set_attr(*args, **kwargs);
  return ret;
}

// set_aspect
pybind11::object Axes::set_aspect(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_aspect_attr(*args, **kwargs);
  return ret;
}

// set_title
pybind11::object Axes::set_title(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = set_title_attr(*args, **kwargs);
  return ret;
}

// set_xlabel
pybind11::object Axes::set_xlabel(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_xlabel_attr(*args, **kwargs);
  return ret;
}

// set_xlim
pybind11::object Axes::set_xlim(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = set_xlim_attr(*args, **kwargs);
  return ret;
}

// set_xticks
pybind11::object Axes::set_xticks(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_xticks_attr(*args, **kwargs);
  return ret;
}

// set_xticklabels
pybind11::object Axes::set_xticklabels(const pybind11::tuple &args,
                                       const pybind11::dict &kwargs) {
  pybind11::object ret = set_xticklabels_attr(*args, **kwargs);
  return ret;
}

// set_ylabel
pybind11::object Axes::set_ylabel(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_ylabel_attr(*args, **kwargs);
  return ret;
}

// set_ylim
pybind11::object Axes::set_ylim(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = set_ylim_attr(*args, **kwargs);
  return ret;
}

// set_yticks
pybind11::object Axes::set_yticks(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_yticks_attr(*args, **kwargs);
  return ret;
}

// set_zlabel
pybind11::object Axes::set_zlabel(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = set_zlabel_attr(*args, **kwargs);
  return ret;
}

// set_zlim
pybind11::object Axes::set_zlim(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = set_zlim_attr(*args, **kwargs);
  return ret;
}

// text
pybind11::object Axes::text(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = text_attr(*args, **kwargs);
  return ret;
}

// tick_params
pybind11::object Axes::tick_params(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = tick_params_attr(*args, **kwargs);
  return ret;
}

} // namespace matplotlibcpp17::axes

#endif /* MATPLOTLIBCPP17_AXES_H */
