struct __attribute__((visibility("hidden"))) Axes {
  Axes() {}
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }
  Axes(pybind11::module mod) {
    self = mod.attr("axes");
    load_attrs();
  }
  void load_attrs() {
    LOAD_ATTR(plot, self);
    LOAD_ATTR(set, self);
    LOAD_ATTR(grid, self);
  }
  pybind11::object self;
  pybind11::object plot;
  pybind11::object set;
  pybind11::object grid;
};
