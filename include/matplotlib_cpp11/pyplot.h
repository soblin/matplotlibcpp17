struct __attribute__((visibility("hidden"))) pyplot {
  pyplot() {}
  pyplot(pybind11::module mod_) {
    mod = mod_;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(axes, mod);
    LOAD_NONVOID_ATTR(figure, mod);
    LOAD_VOID_ATTR(legend, mod);
    LOAD_VOID_ATTR(plot, mod);
    LOAD_VOID_ATTR(scatter, mod);
    LOAD_VOID_ATTR(show, mod);
    LOAD_NONVOID_ATTR(subplot, mod);
    LOAD_NONVOID_ATTR(subplots, mod);
    LOAD_VOID_ATTR(xlabel, mod);
    LOAD_VOID_ATTR(ylabel, mod);
  }
  pybind11::module mod;

  // axes
  Axes axes(const pybind11::dict &kwargs);
  pybind11::object axes_attr;

  // figure
  Figure figure(const pybind11::dict &kwargs);
  pybind11::object figure_attr;

  // legend
  pybind11::object legend;

  // plot
  /// TODO: should implement overloaded functions for plot like plot(x, y,
  /// **kwargs) and plot(x, **kwargs) and set plot_attr?
  pybind11::object plot;

  // scatter
  pybind11::object scatter;

  // show
  pybind11::object show;

  // subplot
  Axes subplot(const pybind11::dict &kwargs);
  pybind11::object subplot_attr;

  // subplots
  std::tuple<Figure, Axes> subplots(const pybind11::dict &kwargs);
  std::tuple<Figure, std::vector<Axes>> subplots(int r, int c,
                                                 const pybind11::dict &kwargs);
  pybind11::object subplots_attr;

  // xlabel
  pybind11::object xlabel;

  // ylabel
  pybind11::object ylabel;
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
std::tuple<Figure, Axes>
pyplot::subplots(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::list ret = subplots_attr(**kwargs);
  pybind11::object fig = ret[0];
  pybind11::object ax = ret[1];
  return {Figure(fig), Axes(ax)};
}

std::tuple<Figure, std::vector<Axes>>
pyplot::subplots(int r, int c, const pybind11::dict &kargs = pybind11::dict()) {
  pybind11::tuple args = pybind11::make_tuple(r, c);
  pybind11::list ret = subplots_attr(*args, **args);
  std::vector<Axes> axes;
  pybind11::object fig = ret[0];
  Figure figure(fig);
  if (r == 1 and c == 1) {
    pybind11::object ax = ret[1];
    axes.push_back(Axes(ax));
  } else {
    pybind11::list axs = ret[1];
    for (pybind11::size_t i = 0; i < axs.size(); ++i) {
      axes.push_back(Axes(axs[i]));
    }
  }
  return {figure, axes};
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
