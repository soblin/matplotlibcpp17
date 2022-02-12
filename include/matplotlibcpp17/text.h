#ifndef MATPLOTLIBCPP17_TEXT_H
#define MATPLOTLIBCPP17_TEXT_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::text {

struct DECL_STRUCT_ATTR Text {
  Text(pybind11::object text) {
    self = text;
    load_attrs();
  }
  void load_attrs() { LOAD_FUNC_ATTR(set_rotation, self); }
  pybind11::object self;
  pybind11::object set_rotation;
};

} // namespace matplotlibcpp17::text

#endif /* MATPLOTLIBCPP17_TEXT_H */
