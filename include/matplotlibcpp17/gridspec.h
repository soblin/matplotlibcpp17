namespace gridspec {

struct __attribute__((visibility("hidden"))) SubplotSpec {
  SubplotSpec(pybind11::object subplotspec) { self = subplotspec; }
  pybind11::object self;
  pybind11::object unwrap() { return self; }
};

struct __attribute__((visibility("hidden"))) GridSpec {
  GridSpec(int nrow_, int ncol_) {
    nrow = nrow_;
    ncol = ncol_;
    load_attrs();
  }
  void load_attrs() {
    gridspec_attr =
        pybind11::module::import("matplotlib.gridspec").attr("GridSpec");
    self = gridspec_attr(nrow, ncol);
  }
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
