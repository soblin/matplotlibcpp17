/**
 * @file animation.h
 * @brief corresponding header for matplotlib.animation
 **/

#ifndef MATPLOTLIBCPP17_ANIMATION_H
#define MATPLOTLIBCPP17_ANIMATION_H

#include <pybind11/pybind11.h>

#include <matplotlibcpp17/common.h>

namespace matplotlibcpp17::animation {

/**
 * @brief A wrapper class for matplotlib.animation.ArtistAnimation
 **/
struct DECL_STRUCT_ATTR ArtistAnimation : public BaseWrapper {
public:
  ArtistAnimation(const pybind11::tuple &args, const pybind11::dict &kwargs) {
    pybind11::object attr = pybind11::module::import("matplotlib.animation")
                                .attr("ArtistAnimation");
    self = attr(*args, **kwargs);
    load_attrs();
  }
  // save
  pybind11::object save(const pybind11::tuple &args = pybind11::tuple(),
                        const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(save, self); }
  pybind11::object self;
  pybind11::object save_attr;
};

// save
pybind11::object ArtistAnimation::save(const pybind11::tuple &args,
                                       const pybind11::dict &kwargs) {
  pybind11::object ret = save_attr(*args, **kwargs);
  return ret;
}

} // namespace matplotlibcpp17::animation

#endif /* MATPLOTLIBCPP17_ANIMATION_H */
