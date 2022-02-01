namespace legend {

struct DECL_STRUCT_ATTR Legend {
  Legend(pybind11::object obj) {
    self = obj;
    load_attrs();
  }
  void load_attrs() { return; }

  pybind11::object self;

  pybind11::object unwrap() { return self; }
};
} // namespace legend
