#ifndef MATPLOTLIBCPP17_COMMON_H
#define MATPLOTLIBCPP17_COMMON_H

#define LOAD_FUNC_ATTR(obj, mod)                                               \
  do {                                                                         \
    obj##_attr = mod.attr(#obj);                                               \
  } while (0)

#define DECL_STRUCT_ATTR __attribute__((visibility("hidden")))

#include <pybind11/pybind11.h>

namespace matplotlibcpp17 {

struct DECL_STRUCT_ATTR BaseWrapper {
public:
  pybind11::object unwrap() { return self; }

protected:
  pybind11::object self;
};

} // namespace matplotlibcpp17

#endif /* MATPLOTLIBCPP17_COMMON_H */
