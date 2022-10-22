/**
 * @file figure.h
 * @brief corresponding header for matplotlib.figure
 **/

#ifndef MATPLOTLIBCPP17_FIGURE_H
#define MATPLOTLIBCPP17_FIGURE_H

#include <matplotlibcpp17/common.h>
#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/gridspec.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::figure {

/**
 * @brief A wrapper class for matplotlib.figure.Figure
 **/
struct DECL_STRUCT_ATTR Figure : public BaseWrapper {
public:
  Figure(const pybind11::object &figure) {
    self = figure;
    load_attrs();
  }
  Figure(pybind11::object &&figure) {
    self = std::move(figure);
    load_attrs();
  }
  // add_axes
  axes::Axes add_axes(const pybind11::tuple &args = pybind11::tuple(),
                      const pybind11::dict &kwargs = pybind11::dict());

  // add_gridspec
  gridspec::GridSpec
  add_gridspec(int nrow, int ncol,
               const pybind11::dict &kwargs = pybind11::dict());

  // add_subplot
  axes::Axes add_subplot(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // align_labels
  ObjectWrapper align_labels(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

  // colorbar
  ObjectWrapper colorbar(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // savefig
  ObjectWrapper savefig(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

  // suptitle
  ObjectWrapper suptitle(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict());

  // tight_layout
  ObjectWrapper tight_layout(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() {
    LOAD_FUNC_ATTR(add_axes, self);
    LOAD_FUNC_ATTR(add_gridspec, self);
    LOAD_FUNC_ATTR(add_subplot, self);
    LOAD_FUNC_ATTR(align_labels, self);
    LOAD_FUNC_ATTR(colorbar, self);
    LOAD_FUNC_ATTR(savefig, self);
    LOAD_FUNC_ATTR(suptitle, self);
    LOAD_FUNC_ATTR(tight_layout, self);
  }
  pybind11::object add_axes_attr;
  pybind11::object add_gridspec_attr;
  pybind11::object add_subplot_attr;
  pybind11::object align_labels_attr;
  pybind11::object colorbar_attr;
  pybind11::object savefig_attr;
  pybind11::object suptitle_attr;
  pybind11::object tight_layout_attr;
};

// add_axes
axes::Axes Figure::add_axes(const pybind11::tuple &args,
                            const pybind11::dict &kwargs) {
  pybind11::object obj = add_axes_attr(*args, **kwargs);
  return axes::Axes(obj);
}

// add_gridspec
gridspec::GridSpec Figure::add_gridspec(int nrow, int ncol,
                                        const pybind11::dict &kwargs) {
  return gridspec::GridSpec(nrow, ncol, kwargs);
}

// add_subplot
axes::Axes Figure::add_subplot(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object obj = add_subplot_attr(*args, **kwargs);
  return axes::Axes(obj);
}

// align_labels
ObjectWrapper Figure::align_labels(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = align_labels_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// colorbar
ObjectWrapper Figure::colorbar(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = colorbar_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// savefig
ObjectWrapper Figure::savefig(const pybind11::tuple &args,
                              const pybind11::dict &kwargs) {
  pybind11::object ret = savefig_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// suptitle
ObjectWrapper Figure::suptitle(const pybind11::tuple &args,
                               const pybind11::dict &kwargs) {
  pybind11::object ret = suptitle_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

// tight_layout
ObjectWrapper Figure::tight_layout(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object ret = tight_layout_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

} // namespace matplotlibcpp17::figure

#endif /* MATPLOTLIBCPP17_FIGURE_H */
