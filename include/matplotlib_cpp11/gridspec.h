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
  pybind11::object operator()(int r, int c) {
    // if r == -1 or c == -1, do slice
    if (r == -1) {
      if (c == -1) {
        return self;
      }
      auto rs = pybind11::slice(0, nrow, 1);
      return self[pybind11::make_tuple(rs, c)];
    } else if (c == -1) {
      auto cs = pybind11::slice(0, ncol, 1);
      return self[pybind11::make_tuple(r, cs)];
    } else
      return self[pybind11::make_tuple(r, c)];
  }
  int nrow, ncol;
  pybind11::object self;
  pybind11::object gridspec_attr;
};
