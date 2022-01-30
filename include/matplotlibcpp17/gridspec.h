namespace gridspec {

struct DECL_STRUCT_ATTR SubplotSpec {
  SubplotSpec(pybind11::object subplotspec) { self = subplotspec; }
  pybind11::object self;
  pybind11::object unwrap() { return self; }
};

struct DECL_STRUCT_ATTR GridSpec {
  GridSpec(int nrow_, int ncol_,
           const pybind11::dict &kwargs = pybind11::dict()) {
    nrow = nrow_;
    ncol = ncol_;
    gridspec_attr =
        pybind11::module::import("matplotlib.gridspec").attr("GridSpec");
    self = gridspec_attr(nrow, ncol, **kwargs);
    load_attrs();
  }
  void load_attrs() { return; }
  template <typename Rows, typename Cols>
  SubplotSpec operator()(const Rows &r, const Cols &c) {
    pybind11::object obj = self[pybind11::make_tuple(r, c)];
    return SubplotSpec(obj);
  }
  int nrow, ncol;
  pybind11::object self;
  pybind11::object gridspec_attr;
};

} // namespace gridspec
