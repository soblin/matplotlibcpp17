namespace collections {

struct DECL_STRUCT_ATTR PathCollection {
  PathCollection(pybind11::object pathcollection) {
    self = pathcollection;
    load_attrs();
  }
  void load_attrs() {
    LOAD_NONVOID_ATTR(legend_elements, self);
  }
  pybind11::object self;

  pybind11::object unwrap() { return self; }

  // legend_elements
  pybind11::object legend_elements_attr;
  std::pair<pybind11::object, pybind11::object>
  legend_elements(const pybind11::tuple &args, const pybind11::dict &kwargs);
};

// legend_elements
/// NOTE: this func does not return list of Line2Ds(handles) and list of
/// strs(labels) unlike original python func
std::pair<pybind11::object, pybind11::object> PathCollection::legend_elements(
    const pybind11::tuple &args = pybind11::tuple(),
    const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::list ret = legend_elements_attr(*args, **kwargs);
  pybind11::object handles = ret[0];
  pybind11::object labels = ret[1];
  return {handles, labels};
}

struct DECL_STRUCT_ATTR PatchCollection {
  PatchCollection(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict()) {
    pybind11::object attr = pybind11::module::import("matplotlib.collections")
                                .attr("PatchCollection");
    self = attr(*args, **kwargs);
    load_attrs();
  }
  void load_attrs() { LOAD_VOID_ATTR(set_array, self); }
  pybind11::object self;

  pybind11::object unwrap() { return self; }

  // set_array
  pybind11::object set_array;
};

} // namespace collections
