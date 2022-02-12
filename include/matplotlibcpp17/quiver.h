#ifndef MATPLOTLIBCPP17_QUIVER_H
#define MATPLOTLIBCPP17_QUIVER_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::quiver {

struct DECL_STRUCT_ATTR Quiver {
public:
  Quiver(pybind11::object q) { self = q; }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
};

struct DECL_STRUCT_ATTR QuiverKey {
  QuiverKey(pybind11::object qk) { self = qk; }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
};

} // namespace matplotlibcpp17::quiver

#endif /* MATPLOTLIBCPP17_QUIVER_H */
