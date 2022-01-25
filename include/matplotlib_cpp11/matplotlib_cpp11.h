#ifndef MATPLOTLIBCPP_11
#define MATPLOTLIBCPP_11

namespace matplotlib_cpp11 {

static bool g_imported = false;

#include "axes.h"
#include "figure.h"
#include "pyplot.h"

static pyplot &import() {
  static pyplot g_pyplot;
  static figure g_figure;
  static axes g_axes;
  if (not g_imported) {
    g_imported = true;

    // pyplot singleton
    g_pyplot.mod = pybind11::module::import("matplotlib.pyplot");
    g_pyplot.plot = g_pyplot.mod.attr("plot");
    g_pyplot.show = g_pyplot.mod.attr("show");
    g_pyplot.subplot_attr = g_pyplot.mod.attr("subplot");
    g_pyplot.subplots_attr = g_pyplot.mod.attr("subplots");

    // figure singleton
    // g_figure.mod = pybind11::module::import("matplotlib.figure");

    // axes singleton
  }
  return g_pyplot;
}

} // namespace matplotlib_cpp11

#endif /* MATPLOTLIBCPP_11 */
