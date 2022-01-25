#include <vector>

struct __attribute__((visibility("hidden"))) Axes {
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }
  void load_attrs() {
    LOAD_ATTR(plot, self);
    LOAD_ATTR(set, self);
    LOAD_ATTR(grid, self);
    LOAD_ATTR(set_xlabel, self);
    LOAD_ATTR(set_ylabel, self);
    get_xticklabels_attr = self.attr("get_xticklabels");
  }
  pybind11::object self;
  pybind11::object plot;
  pybind11::object set;
  pybind11::object grid;
  pybind11::object set_xlabel;
  pybind11::object set_ylabel;
  pybind11::object get_xticklabels_attr;
  std::vector<Text> get_xticklabels() {
    pybind11::list ret = get_xticklabels_attr();
    std::vector<Text> texts;
    for (pybind11::size_t i = 0; i < ret.size(); ++i) {
      texts.push_back(Text(ret[i]));
    }
    return texts;
  }
};
