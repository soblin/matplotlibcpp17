struct __attribute__((visibility("hidden"))) figure {
  // TODO: For "hidden" class does ctor/dtor works ?
  void init(pybind11::object instance_) {
    instance = instance_;
    savefig = instance.attr("savefig");
  }
  pybind11::object instance;
  pybind11::object savefig;
};
