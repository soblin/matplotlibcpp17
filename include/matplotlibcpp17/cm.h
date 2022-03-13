/**
 * @file cm.h
 * @brief corresponding header for matplotlib.cm
 **/

#ifndef MATPLOTLIBCPP17_CM_H
#define MATPLOTLIBCPP17_CM_H

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::cm {

pybind11::object coolwarm() {
  pybind11::object ret =
      pybind11::module::import("matplotlib.cm").attr("coolwarm");
  return ret;
}

pybind11::object PuBu_r() {
  pybind11::object ret =
      pybind11::module::import("matplotlib.cm").attr("PuBu_r");
  return ret;
}

} // namespace matplotlibcpp17::cm

#endif /* MATPLOTLIBCPP17_CM_H */
