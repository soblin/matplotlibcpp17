/**
 * @file gridspec.h
 * @brief corresponding header for matplotlib.axes
 **/

#ifndef MATPLOTLIBCPP17_GRIDSPEC_H
#define MATPLOTLIBCPP17_GRIDSPEC_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::gridspec {

/**
 * @brief A wrapper class for matplotlib.gridspec.SubplotSpec
 **/
struct DECL_STRUCT_ATTR SubplotSpec {
public:
  SubplotSpec(pybind11::object subplotspec) { self = subplotspec; }

  /**
   * @fn unwrap()
   * @brief return python object for passing this wrapper class to plotting
   *function
   **/
  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
};

/**
 * @brief A wrapper class for matplotlib.gridspec.Gridspec
 **/
struct DECL_STRUCT_ATTR GridSpec {
public:
  GridSpec(int nrow_, int ncol_,
           const pybind11::dict &kwargs = pybind11::dict()) {
    nrow = nrow_;
    ncol = ncol_;
    gridspec_attr =
        pybind11::module::import("matplotlib.gridspec").attr("GridSpec");
    self = gridspec_attr(nrow, ncol, **kwargs);
  }
  template <typename Rows, typename Cols>
  SubplotSpec operator()(const Rows &r, const Cols &c) {
    pybind11::object obj = self[pybind11::make_tuple(r, c)];
    return SubplotSpec(obj);
  }

private:
  int nrow, ncol;
  pybind11::object self;
  pybind11::object gridspec_attr;
};

} // namespace matplotlibcpp17::gridspec

#endif /* MATPLOTLIBCPP17_GRIDSPEC_H */
