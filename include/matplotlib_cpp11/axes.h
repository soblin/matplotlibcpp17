struct __attribute__((visibility("hidden"))) axes {
  // TODO: For "hidden" class does ctor/dtor works ?
  void init(pybind11::object instance_) {
    instance = instance_;
    plot = instance.attr("plot");
    set = instance.attr("set");
    grid = instance.attr("grid");
  }
  pybind11::object instance;
  pybind11::object plot;
  pybind11::object set;
  pybind11::object grid;
};
