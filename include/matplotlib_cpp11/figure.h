struct __attribute__((visibility("hidden"))) Figure {
  Figure(pybind11::object figure) {
    self = figure;
    load_attrs();
  }
  void load_attrs() {
    LOAD_ATTR(savefig, self);
    LOAD_ATTR(add_subplot, self);
    LOAD_ATTR(align_labels, self);
  }
  pybind11::object self;
  pybind11::object savefig;
  pybind11::object add_subplot;
  pybind11::object align_labels;
};
