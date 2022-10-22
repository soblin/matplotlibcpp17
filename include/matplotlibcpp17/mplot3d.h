/**
 * @file mplot3d.h
 * @brief header file for mplot3d
 **/

#ifndef MATPLOTLIBCPP17_MPLOT3D_H
#define MATPLOTLIBCPP17_MPLOT3D_H

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::mplot3d {

pybind11::object import() {
  return pybind11::module::import("mpl_toolkits.mplot3d").attr("Axes3D");
}

} // namespace matplotlibcpp17::mplot3d
#endif
