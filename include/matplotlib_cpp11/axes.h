namespace axes {

struct __attribute__((visibility("hidden"))) Axes {
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }
  void load_attrs() {
    LOAD_VOID_ATTR(axhline, self);
    LOAD_VOID_ATTR(fill, self);
    LOAD_VOID_ATTR(fill_between, self);
    LOAD_VOID_ATTR(fill_betweenx, self);
    LOAD_VOID_ATTR(get_xaxis_transform, self);
    LOAD_NONVOID_ATTR(get_xticklabels, self);
    LOAD_VOID_ATTR(grid, self);
    LOAD_VOID_ATTR(plot, self);
    LOAD_VOID_ATTR(set, self);
    LOAD_VOID_ATTR(set_title, self);
    LOAD_VOID_ATTR(set_xlabel, self);
    LOAD_VOID_ATTR(set_ylabel, self);
  }
  pybind11::object self;

  // axhline
  pybind11::object axhline;

  // fill
  pybind11::object fill;

  // fill_between
  pybind11::object fill_between;

  // fill_betweenx
  pybind11::object fill_betweenx;

  // get_xaxis_transform
  /// TODO: currently returns py::object
  pybind11::object get_xaxis_transform;

  // get_xticklabels
  std::vector<text::Text> get_xticklabels();
  pybind11::object get_xticklabels_attr;

  // grid
  pybind11::object grid;

  // plot
  pybind11::object plot;

  // set
  pybind11::object set;

  // set_title
  pybind11::object set_title;

  // set_xtabel
  pybind11::object set_xlabel;

  // set_ylabel
  pybind11::object set_ylabel;
};

// get_xticklabels
std::vector<text::Text> Axes::get_xticklabels() {
  pybind11::list ret = get_xticklabels_attr();
  std::vector<text::Text> texts;
  for (pybind11::size_t i = 0; i < ret.size(); ++i) {
    texts.push_back(text::Text(ret[i]));
  }
  return texts;
}

} // namespace axes
