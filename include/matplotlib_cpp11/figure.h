struct __attribute__((visibility("hidden"))) Figure {
  Figure() {}
  Figure(pybind11::object figure) {
    self = figure;
    load_attrs();
  }
  Figure(pybind11::module mod) {
    self = mod.attr("figure");
    load_attrs();
  }
  void load_attrs() { LOAD_ATTR(savefig, self); }
  pybind11::object self;
  pybind11::object savefig;
  pybind11::object add_subplot;
};
