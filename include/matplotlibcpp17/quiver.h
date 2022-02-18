/**
 * @file axes.h
 * @brief corresponding header for matplotlib.quiver
 **/

#ifndef MATPLOTLIBCPP17_QUIVER_H
#define MATPLOTLIBCPP17_QUIVER_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::quiver {

/**
 * @brief A wrapper class for matplotlib.quiver.Quiver
 **/
struct DECL_STRUCT_ATTR Quiver : public BaseWrapper {
public:
  Quiver(pybind11::object q) { self = q; }
};

/**
 * @brief A wrapper class for matplotlib.quiver.QuiverKey
 **/
struct DECL_STRUCT_ATTR QuiverKey : public BaseWrapper {
  QuiverKey(pybind11::object qk) { self = qk; }
};

} // namespace matplotlibcpp17::quiver

#endif /* MATPLOTLIBCPP17_QUIVER_H */
