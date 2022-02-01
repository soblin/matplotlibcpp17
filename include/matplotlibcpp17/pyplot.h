namespace pyplot {

struct DECL_STRUCT_ATTR PyPlot {
  PyPlot() {}
  PyPlot(pybind11::module mod_) {
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
  axes::Axes axes(const pybind11::dict &kwargs);
  pybind11::object axes_attr;

  // figure
  figure::Figure figure(const pybind11::dict &kwargs);
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
  axes::Axes subplot(const pybind11::dict &kwargs);
  pybind11::object subplot_attr;

  // subplots
  std::tuple<figure::Figure, axes::Axes> subplots(const pybind11::dict &kwargs);
  std::tuple<figure::Figure, std::vector<axes::Axes>>
  subplots(int r, int c, const pybind11::dict &kwargs);
  pybind11::object subplots_attr;

  // xlabel
  pybind11::object xlabel;

  // ylabel
  pybind11::object ylabel;
};

// axes
axes::Axes PyPlot::axes(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object ax_obj = axes_attr(**kwargs);
  return axes::Axes(ax_obj);
}

// figure
figure::Figure PyPlot::figure(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object fig_obj = figure_attr(**kwargs);
  return figure::Figure(fig_obj);
}

// subplot
axes::Axes PyPlot::subplot(const pybind11::dict &kwargs = pybind11::dict()) {
  return axes::Axes(subplot_attr(**kwargs));
}

// subplots
std::tuple<figure::Figure, axes::Axes>
PyPlot::subplots(const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::list ret = subplots_attr(**kwargs);
  pybind11::object fig = ret[0];
  pybind11::object ax = ret[1];
  return {figure::Figure(fig), axes::Axes(ax)};
}

std::tuple<figure::Figure, std::vector<axes::Axes>>
PyPlot::subplots(int r, int c,
                 const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::tuple args = pybind11::make_tuple(r, c);
  pybind11::list ret = subplots_attr(*args, **kwargs);
  std::vector<axes::Axes> axes;
  pybind11::object fig = ret[0];
  figure::Figure figure(fig);
  if (r == 1 and c == 1) {
    pybind11::object ax = ret[1];
    axes.push_back(axes::Axes(ax));
  } else {
    pybind11::list axs = ret[1];
    for (pybind11::size_t i = 0; i < axs.size(); ++i) {
      axes.push_back(axes::Axes(axs[i]));
    }
  }
  return {figure, axes};
}

PyPlot import() {
  // PyPlot singleton
  auto mod = pybind11::module::import("matplotlib.pyplot");
  auto g_pyplot = PyPlot(mod);
  return g_pyplot;
}

} // namespace pyplot
