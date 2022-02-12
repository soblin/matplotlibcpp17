#ifndef MATPLOTLIBCPP17_COLLECTIONS_H
#define MATPLOTLIBCPP17_COLLECTIONS_H

#include <utility>

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::collections {

struct DECL_STRUCT_ATTR PathCollection {
public:
  PathCollection(pybind11::object pathcollection) {
    self = pathcollection;
    load_attrs();
  }
  pybind11::object unwrap() { return self; }

  // legend_elements
  std::pair<pybind11::object, pybind11::object>
  legend_elements(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(legend_elements, self); }
  pybind11::object self;
  pybind11::object legend_elements_attr;
};

// legend_elements
/// NOTE: this func does not return list of Line2Ds(handles) and list of
/// strs(labels) unlike original python func
std::pair<pybind11::object, pybind11::object>
PathCollection::legend_elements(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::list ret = legend_elements_attr(*args, **kwargs);
  pybind11::object handles = ret[0];
  pybind11::object labels = ret[1];
  return {handles, labels};
}

struct DECL_STRUCT_ATTR PatchCollection {
public:
  PatchCollection(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict()) {
    pybind11::object attr = pybind11::module::import("matplotlib.collections")
                                .attr("PatchCollection");
    self = attr(*args, **kwargs);
    load_attrs();
  }
  pybind11::object unwrap() { return self; }

  // set_array
  pybind11::object set_array(const pybind11::tuple &args = pybind11::tuple(),
                             const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(set_array, self); }
  pybind11::object self;
  pybind11::object set_array_attr;
};

pybind11::object PatchCollection::set_array(const pybind11::tuple &args,
                                            const pybind11::dict &kwargs) {
  pybind11::object ret = set_array_attr(*args, **kwargs);
  return ret;
}
} // namespace matplotlibcpp17::collections

#endif /* MATPLOTLIBCPP17_COLLECTIONS_H */
