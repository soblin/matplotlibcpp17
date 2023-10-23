/**
 * @file collections.h
 * @brief corresponding header for matplotlib.collections
 **/
#pragma once

#include <utility>

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::collections {

/**
 * @brief A wrapper class for matplotlib.collections.PathCollection
 **/
struct DECL_STRUCT_ATTR PathCollection : public BaseWrapper {
public:
  PathCollection(const pybind11::object &pathcollection) {
    self = pathcollection;
    load_attrs();
  }
  PathCollection(pybind11::object &&pathcollection) {
    self = std::move(pathcollection);
    load_attrs();
  }

  // legend_elements
  std::pair<ObjectWrapper, ObjectWrapper>
  legend_elements(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(legend_elements, self); }
  pybind11::object legend_elements_attr;
};

// legend_elements
/// NOTE: this func does not return list of Line2Ds(handles) and list of
/// strs(labels) unlike original python func
inline std::pair<ObjectWrapper, ObjectWrapper>
PathCollection::legend_elements(const pybind11::tuple &args,
                                const pybind11::dict &kwargs) {
  pybind11::list ret = legend_elements_attr(*args, **kwargs);
  pybind11::object handles = ret[0];
  pybind11::object labels = ret[1];
  return {ObjectWrapper(std::move(handles)), ObjectWrapper(std::move(labels))};
}

/**
 * @brief A wrapper class for matplotlib.collections.PatchCollection
 **/
struct DECL_STRUCT_ATTR PatchCollection : public BaseWrapper {
public:
  PatchCollection(const pybind11::tuple &args = pybind11::tuple(),
                  const pybind11::dict &kwargs = pybind11::dict()) {
    pybind11::object attr = pybind11::module::import("matplotlib.collections")
                                .attr("PatchCollection");
    self = attr(*args, **kwargs);
    load_attrs();
  }

  // set_array
  ObjectWrapper set_array(const pybind11::tuple &args = pybind11::tuple(),
                          const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(set_array, self); }
  pybind11::object set_array_attr;
};

inline ObjectWrapper PatchCollection::set_array(const pybind11::tuple &args,
                                                const pybind11::dict &kwargs) {
  pybind11::object ret = set_array_attr(*args, **kwargs);
  return ObjectWrapper(std::move(ret));
}

/**
 * @brief A wrapper class for matplotlib.collections.QuadMesh
 **/
struct DECL_STRUCT_ATTR QuadMesh : public BaseWrapper {
public:
  QuadMesh(const pybind11::object &quadmesh) { self = quadmesh; }
  QuadMesh(pybind11::object &&quadmesh) { self = std::move(quadmesh); }
};

} // namespace matplotlibcpp17::collections
