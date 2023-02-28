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
  Axes(const pybind11::object &axes) {
    self = axes;
    load_attrs();
  }
  Axes(pybind11::object &&axes) {
    self = std::move(axes);
    load_attrs();
  }

  // add_artist
  ObjectWrapper add_artist(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // add_collection
  ObjectWrapper add_collection(const pybind11::tuple &args = pybind11::tuple(),
                               const pybind11::dict &kwargs = pybind11::dict());

  // add_patch
  ObjectWrapper add_patch(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // axhline
  ObjectWrapper axhline(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // bar
  container::BarContainer bar(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // bar_label
  ObjectWrapper bar_label(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // barh
  container::BarContainer barh(const pybind11::tuple &args = pybind11::tuple(),
                               const pybind11::dict &kwargs = pybind11::dict());

  // cla
  ObjectWrapper cla(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict());

  // contour
  ObjectWrapper contour(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // contourf
  ObjectWrapper contourf(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // errorbar
  ObjectWrapper errorbar(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // fill
  ObjectWrapper fill(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // fill_between
  ObjectWrapper fill_between(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // fill_betweenx
  ObjectWrapper fill_betweenx(const pybind11::tuple &args = pybind11::tuple(),
                              const pybind11::dict &kwargs = pybind11::dict());

  // get_lines
  ObjectWrapper get_lines(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // get_xaxis_transform
  ObjectWrapper
  get_xaxis_transform(const pybind11::tuple &args = pybind11::tuple(),
                      const pybind11::dict &kwargs = pybind11::dict());

  // get_xlim
  std::tuple<double, double> get_xlim();

  // get_xticklabels
  std::vector<text::Text> get_xticklabels();

  // grid
  ObjectWrapper grid(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // hist
  HistType hist(const pybind11::tuple &args = pybind11::tuple(),
                const pybind11::dict &kwargs = pybind11::dict());

  // hist2d
  ObjectWrapper hist2d(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // imshow
  ObjectWrapper imshow(const pybind11::tuple &args = pybind11::tuple(),
                       const pybind11::dict &kwargs = pybind11::dict());

  // invert_yaxis
  ObjectWrapper invert_yaxis(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // legend
  legend::Legend legend(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // pcolormesh
  collections::QuadMesh
  pcolormesh(const pybind11::tuple &args = pybind11::tuple(),
             const pybind11::dict &kwargs = pybind11::dict());

  // plot
  ObjectWrapper plot(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // plot_surface
  ObjectWrapper plot_surface(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // plot_wireframe
  ObjectWrapper plot_wireframe(const pybind11::tuple &args = pybind11::tuple(),
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
  ObjectWrapper set(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict());

  // set_adjustable
  ObjectWrapper set_adjustable(const pybind11::tuple &args = pybind11::tuple(),
                               const pybind11::dict &kwargs = pybind11::dict());

  // set_aspect
  ObjectWrapper set_aspect(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_title
  ObjectWrapper set_title(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

  // set_xlabel
  ObjectWrapper set_xlabel(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_xlim
  ObjectWrapper set_xlim(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // set_xscale
  ObjectWrapper set_xscale(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_xticks
  ObjectWrapper set_xticks(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_xticklabels
  ObjectWrapper
  set_xticklabels(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict());

  // set_ylabel
  ObjectWrapper set_ylabel(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_ylim
  ObjectWrapper set_ylim(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // set_yscale
  ObjectWrapper set_yscale(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_yticks
  ObjectWrapper set_yticks(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_zlabel
  ObjectWrapper set_zlabel(const pybind11::tuple &args = pybind11::tuple(),
                           const pybind11::dict &kwargs = pybind11::dict());

  // set_zlim
  ObjectWrapper set_zlim(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // text
  ObjectWrapper text(const pybind11::tuple &args = pybind11::tuple(),
                     const pybind11::dict &kwargs = pybind11::dict());

  // tick_params
  ObjectWrapper tick_params(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict());

  // twinx
  Axes twinx(const pybind11::tuple &args = pybind11::tuple(),
             const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() {
    // NOTE: only when called with projection='3d', `plot_surface`,
    // `plot_wireframe`, `set_zlabel` prop exists.
    try {
      LOAD_FUNC_ATTR(plot_surface, self);
      LOAD_FUNC_ATTR(plot_wireframe, self);
      LOAD_FUNC_ATTR(set_zlabel, self);
      LOAD_FUNC_ATTR(set_zlim, self);
      INFO_MSG("Loaded Axes3D");
      projection_3d = true;
    } catch (...) {
      projection_3d = false;
    }
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
    LOAD_FUNC_ATTR(cla, self);
    LOAD_FUNC_ATTR(contour, self);
    LOAD_FUNC_ATTR(contourf, self);
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
    LOAD_FUNC_ATTR(imshow, self);
    LOAD_FUNC_ATTR(legend, self);
    LOAD_FUNC_ATTR(pcolormesh, self);
    LOAD_FUNC_ATTR(plot, self);
    LOAD_FUNC_ATTR(quiver, self);
    LOAD_FUNC_ATTR(quiverkey, self);
    LOAD_FUNC_ATTR(scatter, self);
    LOAD_FUNC_ATTR(set, self);
    LOAD_FUNC_ATTR(set_adjustable, self);
    LOAD_FUNC_ATTR(set_aspect, self);
    LOAD_FUNC_ATTR(set_title, self);
    LOAD_FUNC_ATTR(set_xlabel, self);
    LOAD_FUNC_ATTR(set_xlim, self);
    LOAD_FUNC_ATTR(set_xscale, self);
    LOAD_FUNC_ATTR(set_xticks, self);
    LOAD_FUNC_ATTR(set_xticklabels, self);
    LOAD_FUNC_ATTR(set_ylabel, self);
    LOAD_FUNC_ATTR(set_ylim, self);
    LOAD_FUNC_ATTR(set_yscale, self);
    LOAD_FUNC_ATTR(set_yticks, self);
    LOAD_FUNC_ATTR(text, self);
    LOAD_FUNC_ATTR(tick_params, self);
    LOAD_FUNC_ATTR(twinx, self);
  }
  pybind11::object add_artist_attr;
  pybind11::object add_collection_attr;
  pybind11::object add_patch_attr;
  pybind11::object axhline_attr;
  pybind11::object bar_attr;
  pybind11::object bar_label_attr;
  pybind11::object barh_attr;
  pybind11::object cla_attr;
  pybind11::object contour_attr;
  pybind11::object contourf_attr;
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
  pybind11::object imshow_attr;
  pybind11::object legend_attr;
  pybind11::object pcolormesh_attr;
  pybind11::object plot_attr;
  pybind11::object plot_surface_attr;
  pybind11::object plot_wireframe_attr;
  pybind11::object quiver_attr;
  pybind11::object quiverkey_attr;
  pybind11::object scatter_attr;
  pybind11::object set_attr;
  pybind11::object set_adjustable_attr;
  pybind11::object set_aspect_attr;
  pybind11::object set_title_attr;
  pybind11::object set_xlabel_attr;
  pybind11::object set_xlim_attr;
  pybind11::object set_xscale_attr;
  pybind11::object set_xticks_attr;
  pybind11::object set_xticklabels_attr;
  pybind11::object set_ylabel_attr;
  pybind11::object set_ylim_attr;
  pybind11::object set_yscale_attr;
  pybind11::object set_yticks_attr;
  pybind11::object set_zlabel_attr;
  pybind11::object set_zlim_attr;
  pybind11::object text_attr;
  pybind11::object tick_params_attr;
  pybind11::object twinx_attr;
  // 3d
  bool projection_3d;
};

// add_artist
ObjectWrapper Axes::add_artist(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = add_artist_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// add_collection
ObjectWrapper Axes::add_collection(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = add_collection_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// add_patch
ObjectWrapper Axes::add_patch(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = add_patch_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// axhline
ObjectWrapper Axes::axhline(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = axhline_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// bar
container::BarContainer Axes::bar(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = bar_attr(*args, **kwargs);
  return container::BarContainer(obj);
}

// bar_label
ObjectWrapper Axes::bar_label(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
#if MATPLOTLIB_MINOR_VER_GTE_4
  pybind11::object ret = bar_label_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
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

// cla
ObjectWrapper Axes::cla(const pybind11::tuple &args,
                        const pybind11::dict &kwargs) {
  pybind11::object ret = cla_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// contour
ObjectWrapper Axes::contour(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object ret = contour_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// contourf
ObjectWrapper Axes::contourf(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = contourf_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// errorbar
ObjectWrapper Axes::errorbar(const pybind11::tuple &args,
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
    pybind11::object ret = errorbar_attr(*args, **kwargs);
    return ObjectWrapper(std::move(ret));
  }
}

// fill
ObjectWrapper Axes::fill(const pybind11::tuple &args,
                         const pybind11::dict &kwargs) {
  pybind11::object ret = fill_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// fill_between
ObjectWrapper Axes::fill_between(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = fill_between_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// fill_betweenx
ObjectWrapper Axes::fill_betweenx(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object ret = fill_betweenx_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// get_lines
ObjectWrapper Axes::get_lines(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = get_lines_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// get_xaxis_transform
ObjectWrapper Axes::get_xaxis_transform(const pybind11::tuple &args,
                                        const pybind11::dict &kwargs) {
  pybind11::object ret = get_xaxis_transform_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
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
ObjectWrapper Axes::grid(const pybind11::tuple &args,
                         const pybind11::dict &kwargs) {
  pybind11::object ret = grid_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
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
ObjectWrapper Axes::hist2d(const pybind11::tuple &args,
                           const pybind11::dict &kwargs) {
  pybind11::object ret = hist2d_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// invert_yaxis
ObjectWrapper Axes::invert_yaxis(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = invert_yaxis_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// imshow
ObjectWrapper Axes::imshow(const pybind11::tuple &args,
                           const pybind11::dict &kwargs) {
  pybind11::object ret = imshow_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// legend
legend::Legend Axes::legend(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object obj = legend_attr(*args, **kwargs);
  return legend::Legend(obj);
}

// pcolormesh
collections::QuadMesh Axes::pcolormesh(const pybind11::tuple &args,
                                       const pybind11::dict &kwargs) {
  pybind11::object ret = pcolormesh_attr(*args, **kwargs);
  return collections::QuadMesh(ret);
}

// plot
ObjectWrapper Axes::plot(const pybind11::tuple &args,
                         const pybind11::dict &kwargs) {
  pybind11::object ret = plot_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// plot_surface
ObjectWrapper Axes::plot_surface(const pybind11::tuple &args,
                                 const pybind11::dict &kwargs) {
  pybind11::object ret = plot_surface_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// plot_wireframe
ObjectWrapper Axes::plot_wireframe(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = plot_wireframe_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
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
ObjectWrapper Axes::set(const pybind11::tuple &args,
                        const pybind11::dict &kwargs) {
  pybind11::object ret = set_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_adjustable
ObjectWrapper Axes::set_adjustable(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = set_adjustable_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_aspect
ObjectWrapper Axes::set_aspect(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_aspect_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_title
ObjectWrapper Axes::set_title(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = set_title_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_xlabel
ObjectWrapper Axes::set_xlabel(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_xlabel_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_xlim
ObjectWrapper Axes::set_xlim(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = set_xlim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_xscale
ObjectWrapper Axes::set_xscale(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_xscale_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_xticks
ObjectWrapper Axes::set_xticks(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_xticks_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_xticklabels
ObjectWrapper Axes::set_xticklabels(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = set_xticklabels_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_ylabel
ObjectWrapper Axes::set_ylabel(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_ylabel_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_ylim
ObjectWrapper Axes::set_ylim(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = set_ylim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_yscale
ObjectWrapper Axes::set_yscale(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_yscale_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_yticks
ObjectWrapper Axes::set_yticks(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_yticks_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_zlabel
ObjectWrapper Axes::set_zlabel(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = set_zlabel_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// set_zlim
ObjectWrapper Axes::set_zlim(const pybind11::tuple &args,
                             const pybind11::dict &kwargs) {
  pybind11::object ret = set_zlim_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// text
ObjectWrapper Axes::text(const pybind11::tuple &args,
                         const pybind11::dict &kwargs) {
  pybind11::object ret = text_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// tick_params
ObjectWrapper Axes::tick_params(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::object ret = tick_params_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// twinx
Axes Axes::twinx(const pybind11::tuple &args, const pybind11::dict &kwargs) {
  pybind11::object ret = twinx_attr(*args, **kwargs);
  return Axes(ret);
}

} // namespace matplotlibcpp17::axes

#endif /* MATPLOTLIBCPP17_AXES_H */
