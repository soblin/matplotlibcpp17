/**
 * @file text.h
 * @brief corresponding header for matplotlib.text
 **/

#ifndef MATPLOTLIBCPP17_TEXT_H
#define MATPLOTLIBCPP17_TEXT_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

/**
 * @brief A wrapper class for matplotlib.text.Text
 **/
namespace matplotlibcpp17::text {

struct DECL_STRUCT_ATTR Text : public BaseWrapper {
public:
  Text(pybind11::object text) {
    self = text;
    load_attrs();
  }

  pybind11::object
  set_rotation(const pybind11::tuple &args = pybind11::tuple(),
               const pybind11::dict &kwargs = pybind11::dict());

private:
  void load_attrs() { LOAD_FUNC_ATTR(set_rotation, self); }
  pybind11::object set_rotation_attr;
};

pybind11::object Text::set_rotation(const pybind11::tuple &args,
                                    const pybind11::dict &kwargs) {
  pybind11::object ret = set_rotation_attr(*args, **kwargs);
  return ret;
}

} // namespace matplotlibcpp17::text

#endif /* MATPLOTLIBCPP17_TEXT_H */
