#ifndef MATPLOTLIBCPP_17_H
#define MATPLOTLIBCPP_17_H

#include <pybind11/pybind11.h>

namespace matplotlibcpp17 {

#include "common.h"

#include "animation.h"
#include "text.h"
#include "container.h"
#include "collections.h"
#include "legend.h"
#include "quiver.h"
#include "axes.h"
#include "gridspec.h"
#include "figure.h"
#include "patches.h"
#include "pyplot.h"

template <typename... Args> pybind11::tuple args_(Args &&... args) {
  return pybind11::make_tuple(std::forward<Args>(args)...);
}

using kwargs_ = pybind11::dict;

} // namespace matplotlibcpp17

#endif /* MATPLOTLIBCPP_17_H */
