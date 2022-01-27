struct __attribute__((visibility("hidden"))) BarContainer {
  BarContainer(pybind11::object bar_container) { self = bar_container; }

  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }
};
