struct __attribute__((visibility("hidden"))) pyplot {
  pyplot() {}
  pyplot(pybind11::module mod_) {
    mod = mod_;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(axes, mod);
    LOAD_NONVOID_ATTR(figure, mod);
    LOAD_VOID_ATTR(plot, mod);
    LOAD_VOID_ATTR(show, mod);
    LOAD_NONVOID_ATTR(subplot, mod);
    LOAD_NONVOID_ATTR(subplots, mod);
  }
  pybind11::module mod;

  // axes
  Axes axes(const pybind11::dict &kwargs);
  pybind11::object axes_attr;

  // figure
  Figure figure(const pybind11::dict &kwargs);
  pybind11::object figure_attr;

  // plot
  /// TODO: should implement overloaded functions for plot like plot(x, y,
  /// **kwargs) and plot(x, **kwargs) and set plot_attr?
  pybind11::object plot;

  // show
  pybind11::object show;

  // subplot
  Axes subplot(const pybind11::dict &kwargs);
  pybind11::object subplot_attr;

  // subplots
  std::tuple<std::vector<Figure>, std::vector<Axes>>
  subplots(int n, int m, const pybind11::dict &kwargs);
  pybind11::object subplots_attr;
};

// axes
Axes pyplot::axes(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object ax_obj = axes_attr(**kwargs);
  return Axes(ax_obj);
}

// figure
Figure pyplot::figure(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object fig_obj = figure_attr(**kwargs);
  return Figure(fig_obj);
}

// subplot
Axes pyplot::subplot(const pybind11::dict &kwargs = pybind11::dict()) {
  return Axes(subplot_attr(**kwargs));
}

// subplots
std::tuple<std::vector<Figure>, std::vector<Axes>>
pyplot::subplots(int n = 1, int m = 1,
                 const pybind11::dict &args = pybind11::dict()) {
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
