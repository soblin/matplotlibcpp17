struct __attribute__((visibility("hidden"))) pyplot {
  pyplot() {}
  pyplot(pybind11::module mod_) {
    mod = mod_;
    load_attrs();
  }
  void load_attrs() {
    LOAD_ATTR(plot, mod);
    LOAD_ATTR(show, mod);
    subplot_attr = mod.attr("subplot");
    subplots_attr = mod.attr("subplots");
    LOAD_ATTR(figure, mod);
    LOAD_ATTR(axes, mod);
  }
  pybind11::module mod;
  pybind11::object plot;
  pybind11::object show;
  pybind11::object subplot_attr;
  pybind11::object subplots_attr;
  Axes subplot() { return Axes(subplot_attr()); }
  std::tuple<Figure, Axes> subplots() {
    pybind11::list ret = subplots_attr();
    pybind11::object fig = ret[0], ax = ret[1];
    return {Figure(fig), Axes(ax)};
  }
  std::tuple<std::vector<Figure>, std::vector<Axes>>
  subplots(int n, int m, pybind11::dict args) {
    pybind11::list ret = subplots_attr(n, m, **args);
    std::vector<Figure> figures;
    std::vector<Axes> axes;
    if (m == 1) {
      pybind11::object fig = ret[0];
      figures.push_back(Figure(fig));
    } else {
      pybind11::list figs = ret[0];
      for (pybind11::size_t i = 0; i < figs.size(); ++i) {
        figures.push_back(Figure(figs[i]));
      }
    }
    if (n == 1) {
      pybind11::object ax = ret[1];
      axes.push_back(Axes(ax));
    } else {
      pybind11::list axs = ret[1];
      for (pybind11::size_t i = 0; i < axs.size(); ++i) {
        axes.push_back(Axes(axs[i]));
      }
    }
    return {figures, axes};
  }
  pybind11::object figure;
  pybind11::object axes;
};

static bool g_imported = false;

static pyplot &import() {
  static pyplot g_pyplot;
  if (not g_imported) {
    g_imported = true;
    // pyplot singleton
    auto mod = pybind11::module::import("matplotlib.pyplot");
    g_pyplot = pyplot(mod);
  }
  return g_pyplot;
}
