#ifndef MATPLOTLIBCPP_11_H
#define MATPLOTLIBCPP_11_H

#include <pybind11/pybind11.h>

namespace matplotlib_cpp11 {

static bool g_imported = false;

#define LOAD_ATTR(attr_, mod_)                                                 \
  do {                                                                         \
    attr_ = mod_.attr(#attr_);                                                 \
  } while (0)

#include "axes.h"
#include "figure.h"
#include "pyplot.h"

static pyplot &import() {
  static pyplot g_pyplot;
  static Figure g_figure;
  static Axes g_axes;
  if (not g_imported) {
    g_imported = true;
    // pyplot singleton
    auto mod = pybind11::module::import("matplotlib.pyplot");
    g_pyplot = pyplot(mod);
  }
  return g_pyplot;
}

} // namespace matplotlib_cpp11

#endif /* MATPLOTLIBCPP_11_H */
