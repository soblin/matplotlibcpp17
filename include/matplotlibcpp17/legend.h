/**
 * @file legend.h
 * @brief corresponding header for matplotlib.legend
 **/

#ifndef MATPLOTLIBCPP17_LEGEND_H
#define MATPLOTLIBCPP17_LEGEND_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::legend {

/**
 * @brief A wrapper class for matplotlib.legend.Legend
 **/
struct DECL_STRUCT_ATTR Legend {
public:
  Legend(pybind11::object obj) {
    self = obj;
  }

  /**
   * @fn unwrap()
   * @brief return python object for passing this wrapper class to plotting
   *function
   **/
  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
};

} // namespace matplotlibcpp17::legend

#endif /* MATPLOTLIBCPP17_LEGEND_H */
