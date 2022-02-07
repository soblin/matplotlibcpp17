namespace animation {

struct DECL_STRUCT_ATTR ArtistAnimation {
  ArtistAnimation(const pybind11::tuple &args, const pybind11::dict &kwargs) {
    pybind11::object attr = pybind11::module::import("matplotlib.animation")
                                .attr("ArtistAnimation");
    self = attr(*args, **kwargs);
  }
  pybind11::object self;
};

} // namespace animation
