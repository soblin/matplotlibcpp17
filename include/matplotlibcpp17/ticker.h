/**
 * @file ticker.h
 * @brief corresponding header for matplotlib.ticker
 **/
#pragma once

#include <pybind11/pybind11.h>

#include <matplotlibcpp17/common.h>

namespace matplotlibcpp17::ticker {

struct DECL_STRUCT_ATTR LogLocator : public BaseWrapper {
public:
  LogLocator() {
    pybind11::object attr =
        pybind11::module::import("matplotlib.ticker").attr("LogLocator");
    self = attr();
  }
};

} // namespace matplotlibcpp17::ticker
