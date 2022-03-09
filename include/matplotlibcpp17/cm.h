/**
 * @file cm.h
 * @brief corresponding header for matplotlib.animation
 **/

#ifndef MATPLOTLIBCPP17_CM_H
#define MATPLOTLIBCPP17_CM_H

#include <pybind11/pybind11.h>

#include <matplotlibcpp17/common.h>

namespace matplotlibcpp17::cm {

pybind11::object coolwarm() {
  pybind11::object ret =
      pybind11::module::import("matplotlib.cm").attr("coolwarm");
  return ret;
}

} // namespace matplotlibcpp17::cm

#endif /* MATPLOTLIBCPP17_CM_H */
