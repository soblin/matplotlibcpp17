struct __attribute__((visibility("hidden"))) Figure {
  Figure(pybind11::object figure) {
    self = figure;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(add_subplot, self);
    LOAD_VOID_ATTR(align_labels, self);
    LOAD_VOID_ATTR(savefig, self);
  }
  pybind11::object self;

  // add_subplot
  Axes add_subplot(pybind11::object arg);
  pybind11::object add_subplot_attr;

  // align_labels
  pybind11::object align_labels;

  // savefig
  pybind11::object savefig;
};

// add_subplot
Axes Figure::add_subplot(pybind11::object arg) {
  pybind11::object obj = add_subplot_attr(arg);
  return Axes(obj);
}
