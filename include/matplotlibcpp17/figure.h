#ifndef MATPLOTLIBCPP17_FIGURE_H
#define MATPLOTLIBCPP17_FIGURE_H

#include <matplotlibcpp17/common.h>
#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/gridspec.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::figure {

struct DECL_STRUCT_ATTR Figure {
  Figure(pybind11::object figure) {
    self = figure;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(add_axes, self);
    LOAD_NONVOID_ATTR(add_gridspec, self);
    LOAD_NONVOID_ATTR(add_subplot, self);
    LOAD_VOID_ATTR(align_labels, self);
    LOAD_VOID_ATTR(colorbar, self);
    LOAD_VOID_ATTR(savefig, self);
    LOAD_VOID_ATTR(suptitle, self);
    LOAD_VOID_ATTR(tight_layout, self);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  // add_axes
  axes::Axes add_axes(const pybind11::tuple &args,
                      const pybind11::dict &kwargs);
  pybind11::object add_axes_attr;

  // add_gridspec
  gridspec::GridSpec add_gridspec(int nrow, int ncol,
                                  const pybind11::dict &kwargs);
  pybind11::object add_gridspec_attr;

  // add_subplot
  axes::Axes add_subplot(const pybind11::tuple &args,
                         const pybind11::dict &kwargs);
  pybind11::object add_subplot_attr;

  // align_labels
  pybind11::object align_labels;

  // colorbar
  pybind11::object colorbar;

  // savefig
  pybind11::object savefig;

  // suptitle
  pybind11::object suptitle;

  // tight_layout
  pybind11::object tight_layout;
};

// add_axes
axes::Axes Figure::add_axes(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = add_axes_attr(*args, **kwargs);
  return axes::Axes(obj);
}

// add_gridspec
gridspec::GridSpec
Figure::add_gridspec(int nrow, int ncol,
                     const pybind11::dict &kwargs = pybind11::dict()) {
  return gridspec::GridSpec(nrow, ncol, kwargs);
}

// add_subplot
axes::Axes
Figure::add_subplot(const pybind11::tuple &args = pybind11::tuple(),
                    const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = add_subplot_attr(*args, **kwargs);
  return axes::Axes(obj);
}
} // namespace matplotlibcpp17::figure

#endif /* MATPLOTLIBCPP17_FIGURE_H */
