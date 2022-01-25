#ifndef MATPLOTLIBCPP_11
#define MATPLOTLIBCPP_11

namespace matplotlib_cpp11 {

static bool g_imported = false;

struct __attribute__((visibility("hidden"))) figure {
  // TODO: For "hidden" class does ctor/dtor works ?
  void init(pybind11::object instance_) {
    instance = instance_;
    savefig = instance.attr("savefig");
  }
  pybind11::object instance;
  pybind11::object savefig;
};

struct __attribute__((visibility("hidden"))) axes {
  // TODO: For "hidden" class does ctor/dtor works ?
  void init(pybind11::object instance_) {
    instance = instance_;
    plot = instance.attr("plot");
    set = instance.attr("set");
    grid = instance.attr("grid");
  }
  pybind11::object instance;
  pybind11::object plot;
  pybind11::object set;
  pybind11::object grid;
};

struct __attribute__((visibility("hidden"))) pyplot {
  pybind11::module mod;
  pybind11::object plot;
  pybind11::object show;
  pybind11::object subplot_attr;
  pybind11::object subplots_attr;
  axes subplot() {
    auto ret = subplot_attr();
    axes ax;
    ax.init(ret);
    return ax;
  }
  std::tuple<figure, axes> subplots() {
    // TODO: a lot of versions like subplots(111) or subplots(py::tuple(1,1,1))
    pybind11::list ret = subplots_attr();
    figure fig;
    fig.init(ret[0]);
    axes ax;
    ax.init(ret[1]);
    return {fig, ax};
  }
};

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
