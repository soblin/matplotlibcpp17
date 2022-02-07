#ifndef MATPLOTLIBCPP17_ANIMATION_H
#define MATPLOTLIBCPP17_ANIMATION_H

#include <pybind11/pybind11.h>

#include <matplotlibcpp17/common.h>

namespace matplotlibcpp17::animation {

struct DECL_STRUCT_ATTR ArtistAnimation {
  ArtistAnimation(const pybind11::tuple &args, const pybind11::dict &kwargs) {
    pybind11::object attr = pybind11::module::import("matplotlib.animation")
                                .attr("ArtistAnimation");
    self = attr(*args, **kwargs);
    load_attrs();
  }
  void load_attrs() { LOAD_VOID_ATTR(save, self); }
  pybind11::object self;

  // save
  pybind11::object save;
};

} // namespace matplotlibcpp17::animation

#endif /* MATPLOTLIBCPP17_ANIMATION_H */
