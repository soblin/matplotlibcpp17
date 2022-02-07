#ifndef MATPLOTLIBCPP17_CONTAINER_H
#define MATPLOTLIBCPP17_CONTAINER_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::container {

struct DECL_STRUCT_ATTR BarContainer {
  BarContainer(pybind11::object bar_container) { self = bar_container; }

  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }
};

} // namespace matplotlibcpp17::container

#endif /* MATPLOTLIBCPP17_CONTAINER_H */
