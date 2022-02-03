namespace patches {

struct DECL_STRUCT_ATTR Circle {
  Circle(const pybind11::tuple &args = pybind11::tuple(),
         const pybind11::dict &kwargs = pybind11::dict()) {
    circle_attr = pybind11::module::import("matplotlib.patches").attr("Circle");
    self = circle_attr(*args, **kwargs);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  pybind11::object circle_attr;
};

struct DECL_STRUCT_ATTR Ellipse {
  Ellipse(const pybind11::tuple &args = pybind11::tuple(),
          const pybind11::dict &kwargs = pybind11::dict()) {
    ellipse_attr =
        pybind11::module::import("matplotlib.patches").attr("Ellipse");
    self = ellipse_attr(*args, **kwargs);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  pybind11::object ellipse_attr;
};

struct DECL_STRUCT_ATTR Rectangle {
  Rectangle(const pybind11::tuple &args = pybind11::tuple(),
            const pybind11::dict &kwargs = pybind11::dict()) {
    rectangle_attr =
        pybind11::module::import("matplotlib.patches").attr("Rectangle");
    self = rectangle_attr(*args, **kwargs);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  pybind11::object rectangle_attr;
};

struct DECL_STRUCT_ATTR Wedge {
  Wedge(const pybind11::tuple &args = pybind11::tuple(),
        const pybind11::dict &kwargs = pybind11::dict()) {
    wedge_attr = pybind11::module::import("matplotlib.patches").attr("Wedge");
    self = wedge_attr(*args, **kwargs);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  pybind11::object wedge_attr;
};

} // namespace patches
