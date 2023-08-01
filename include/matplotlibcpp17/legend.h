/**
 * @file legend.h
 * @brief corresponding header for matplotlib.legend
 **/
#pragma once

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::legend {

/**
 * @brief A wrapper class for matplotlib.legend.Legend
 **/
struct DECL_STRUCT_ATTR Legend : public BaseWrapper {
public:
  Legend(const pybind11::object &obj) { self = obj; }
  Legend(pybind11::object &&obj) { self = std::move(obj); }
};

} // namespace matplotlibcpp17::legend
