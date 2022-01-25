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
  }
  pybind11::module mod;
  pybind11::object plot;
  pybind11::object show;
  pybind11::object subplot_attr;
  pybind11::object subplots_attr;
  Axes subplot() { return Axes(subplot_attr()); }
  std::tuple<Figure, Axes> subplots() {
    // TODO: a lot of versions like subplots(111) or subplots(py::tuple(1,1,1))
    pybind11::list ret = subplots_attr();
    pybind11::object fig = ret[0], ax = ret[1];
    return {Figure(fig), Axes(ax)};
  }
  Figure figure() { return Figure(mod); }
  Axes axes() { return Axes(mod); }
};
