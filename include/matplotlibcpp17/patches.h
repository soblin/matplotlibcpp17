#ifndef MATPLOTLIBCPP17_PATCHES_H
#define MATPLOTLIBCPP17_PATCHES_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::patches {

struct DECL_STRUCT_ATTR Circle {
public:
  Circle(const pybind11::tuple &args = pybind11::tuple(),
         const pybind11::dict &kwargs = pybind11::dict()) {
    circle_attr = pybind11::module::import("matplotlib.patches").attr("Circle");
    self = circle_attr(*args, **kwargs);
  }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
  pybind11::object circle_attr;
};

struct DECL_STRUCT_ATTR Ellipse {
public:
  Ellipse(const pybind11::tuple &args = pybind11::tuple(),
          const pybind11::dict &kwargs = pybind11::dict()) {
    ellipse_attr =
        pybind11::module::import("matplotlib.patches").attr("Ellipse");
    self = ellipse_attr(*args, **kwargs);
  }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
  pybind11::object ellipse_attr;
};

struct DECL_STRUCT_ATTR Rectangle {
public:
  Rectangle(const pybind11::tuple &args = pybind11::tuple(),
            const pybind11::dict &kwargs = pybind11::dict()) {
    rectangle_attr =
        pybind11::module::import("matplotlib.patches").attr("Rectangle");
    self = rectangle_attr(*args, **kwargs);
  }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
  pybind11::object rectangle_attr;
};

struct DECL_STRUCT_ATTR Wedge {
public:
  Wedge(const pybind11::tuple &args = pybind11::tuple(),
        const pybind11::dict &kwargs = pybind11::dict()) {
    wedge_attr = pybind11::module::import("matplotlib.patches").attr("Wedge");
    self = wedge_attr(*args, **kwargs);
  }

  pybind11::object unwrap() { return self; }

private:
  pybind11::object self;
  pybind11::object wedge_attr;
};

} // namespace matplotlibcpp17::patches

#endif /* MATPLOTLIBCPP17_PATCHES_H */
