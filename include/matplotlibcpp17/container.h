/**
 * @file container.h
 * @brief corresponding header for matplotlib.axes
 **/

#ifndef MATPLOTLIBCPP17_CONTAINER_H
#define MATPLOTLIBCPP17_CONTAINER_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::container {

/**
 * @brief A wrapper class for matplotlib.container.BarContainer
 **/
struct DECL_STRUCT_ATTR BarContainer {
public:
  BarContainer(pybind11::object bar_container) { self = bar_container; }

  /**
   * @fn unwrap()
   * @brief return python object for passing this wrapper class to plotting
   *function
   **/
  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
};

} // namespace matplotlibcpp17::container

#endif /* MATPLOTLIBCPP17_CONTAINER_H */
