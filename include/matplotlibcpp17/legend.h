#ifndef MATPLOTLIBCPP17_LEGEND_H
#define MATPLOTLIBCPP17_LEGEND_H

#include <matplotlibcpp17/common.h>

#include <pybind11/pybind11.h>

namespace matplotlibcpp17::legend {

struct DECL_STRUCT_ATTR Legend : public BaseWrapper {
public:
  Legend(pybind11::object obj) {
    self = obj;
  }
};

} // namespace matplotlibcpp17::legend

#endif /* MATPLOTLIBCPP17_LEGEND_H */
