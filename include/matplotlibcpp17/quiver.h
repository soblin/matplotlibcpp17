namespace quiver {

struct DECL_STRUCT_ATTR Quiver {
  Quiver(pybind11::object q) { self = q; }
  pybind11::object self;

  pybind11::object unwrap() { return self; }
};

struct DECL_STRUCT_ATTR QuiverKey {
  QuiverKey(pybind11::object qk) { self = qk; }
  pybind11::object self;

  pybind11::object unwrap() { return self; }
};

} // namespace quiver
