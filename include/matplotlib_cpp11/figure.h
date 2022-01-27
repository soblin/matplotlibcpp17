struct __attribute__((visibility("hidden"))) Figure {
  Figure(pybind11::object figure) {
    self = figure;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(add_subplot, self);
    LOAD_VOID_ATTR(align_labels, self);
    LOAD_VOID_ATTR(savefig, self);
    LOAD_VOID_ATTR(tight_layout, self);
  }
  pybind11::object self;

  // add_subplot
  Axes add_subplot(const pybind11::tuple &args, const pybind11::dict &kwargs);
  pybind11::object add_subplot_attr;

  // align_labels
  pybind11::object align_labels;

  // savefig
  pybind11::object savefig;

  // tight_layout
  pybind11::object tight_layout;
};

// add_subplot
Axes Figure::add_subplot(const pybind11::tuple &args = pybind11::tuple(),
                         const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = add_subplot_attr(*args, **kwargs);
  return Axes(obj);
}
