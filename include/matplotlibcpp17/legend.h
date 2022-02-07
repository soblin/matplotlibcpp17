#ifndef MATPLOTLIBCPP17_LEGEND_H
#define MATPLOTLIBCPP17_LEGEND_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::legend {

struct DECL_STRUCT_ATTR Legend {
  Legend(pybind11::object obj) {
    self = obj;
    load_attrs();
  }
  void load_attrs() { return; }

  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }
};
} // namespace matplotlibcpp17::legend

#endif /* MATPLOTLIBCPP17_LEGEND_H */
