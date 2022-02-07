#ifndef MATPLOTLIBCPP_17_H
#define MATPLOTLIBCPP_17_H

#include <matplotlibcpp17/animation.h>
#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/collections.h>
#include <matplotlibcpp17/figure.h>
#include <matplotlibcpp17/gridspec.h>
#include <matplotlibcpp17/legend.h>
#include <matplotlibcpp17/patches.h>
#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/quiver.h>

namespace matplotlibcpp17 {

template <typename... Args> pybind11::tuple args_(Args &&... args) {
  return pybind11::make_tuple(std::forward<Args>(args)...);
}

using kwargs_ = pybind11::dict;

} // namespace matplotlibcpp17

#endif /* MATPLOTLIBCPP_17_H */
