namespace text {

struct DECL_STRUCT_ATTR Text {
  Text(pybind11::object text) {
    self = text;
    load_attrs();
  }
  void load_attrs() { LOAD_VOID_ATTR(set_rotation, self); }
  pybind11::object self;
  pybind11::object set_rotation;
};

} // namespace text
