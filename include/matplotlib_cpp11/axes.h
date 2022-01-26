#include <vector>

struct __attribute__((visibility("hidden"))) Axes {
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(get_xticklabels, self);
    LOAD_VOID_ATTR(grid, self);
    LOAD_VOID_ATTR(plot, self);
    LOAD_VOID_ATTR(set, self);
    LOAD_VOID_ATTR(set_xlabel, self);
    LOAD_VOID_ATTR(set_ylabel, self);
  }
  pybind11::object self;

  // get_xticklabels
  std::vector<Text> get_xticklabels();
  pybind11::object get_xticklabels_attr;

  // grid
  pybind11::object grid;

  // plot
  pybind11::object plot;

  // set
  pybind11::object set;

  // set_xtabel
  pybind11::object set_xlabel;

  // set_ylabel
  pybind11::object set_ylabel;
};

// get_xticklabels
std::vector<Text> Axes::get_xticklabels() {
  pybind11::list ret = get_xticklabels_attr();
  std::vector<Text> texts;
  for (pybind11::size_t i = 0; i < ret.size(); ++i) {
    texts.push_back(Text(ret[i]));
  }
  return texts;
}
