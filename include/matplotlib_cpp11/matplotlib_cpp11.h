#ifndef MATPLOTLIBCPP_11
#define MATPLOTLIBCPP_11

namespace matplotlib_cpp11 {

static bool g_imported = false;

class pyplot {
private:
  // functions
  pybind11::object plot_;
  pybind11::object show_;

public:
  template <class... Args> void plot(Args... args) { plot_(args...); }
  template <class... Args> void show(Args... args) { show_(args...); }

  // singleton class pattern
private:
  pyplot() = default;
  pybind11::module plt;

public:
  static pyplot &import() {
    static pyplot instance;
    if (not g_imported) {
      instance.plt = pybind11::module::import("matplotlib.pyplot");
      g_imported = true;
      instance.plot_ = instance.plt.attr("plot"); // TODO macro
      instance.show_ = instance.plt.attr("show");
    }
    return instance;
  }
};

} // namespace matplotlib_cpp11

#endif /* MATPLOTLIBCPP_11 */
