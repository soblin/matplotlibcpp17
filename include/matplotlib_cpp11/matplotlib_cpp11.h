#ifndef MATPLOTLIBCPP_11
#define MATPLOTLIBCPP_11

namespace matplotlib_cpp11 {

static bool g_imported = false;

// class Figure {};
// class Axes {};

struct __attribute__((visibility("hidden"))) PyPlot {
  pybind11::module pyplot;
  pybind11::object plot;
  pybind11::object show;
  // Figure figure();
  // Axes axes();
};

static PyPlot &import() {
  static PyPlot instance;
  if (not g_imported) {
    instance.pyplot = pybind11::module::import("matplotlib.pyplot");
    g_imported = true;
    instance.plot = instance.pyplot.attr("plot");
    instance.show = instance.pyplot.attr("show");
  }
  return instance;
}

} // namespace matplotlib_cpp11

#endif /* MATPLOTLIBCPP_11 */
