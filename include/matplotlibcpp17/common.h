#ifndef MATPLOTLIBCPP17_COMMON_H
#define MATPLOTLIBCPP17_COMMON_H

#define LOAD_FUNC_ATTR(obj, mod)                                               \
  do {                                                                         \
    obj##_attr = mod.attr(#obj);                                               \
  } while (0)

#define DECL_STRUCT_ATTR __attribute__((visibility("hidden")))

#include <iostream>
#include <utility>

#define INFO_MSG(msg)                                                          \
  do {                                                                         \
    std::cout << "Info [" __FILE__ << "@" << __LINE__ << "]: ";                \
    std::cout << #msg << std::endl;                                            \
  } while (0)

#define WARN_MSG(msg)                                                          \
  do {                                                                         \
    std::cout << "Warn [" __FILE__ << "@" << __LINE__ << "]: ";                \
    std::cout << #msg << std::endl;                                            \
  } while (0)

#define ERROR_MSG(msg)                                                         \
  do {                                                                         \
    std::cerr << "Error [" __FILE__ << "@" << __LINE__ << "]: ";               \
    std::cerr << #msg << std::endl;                                            \
  } while (0)

#include <pybind11/pybind11.h>

namespace matplotlibcpp17 {

/**
 * @brief A base class for python wrapper classes
 **/
struct DECL_STRUCT_ATTR BaseWrapper {
public:
  pybind11::object unwrap() { return self; }

protected:
  pybind11::object self;
};

/**
 * @brief A proxy class for pybind object
 **/
struct ObjectWrapper : public BaseWrapper {
public:
  ObjectWrapper(const pybind11::object &object) { self = object; }
  ObjectWrapper(pybind11::object &&object) { self = std::move(object); }
};

} // namespace matplotlibcpp17

#endif /* MATPLOTLIBCPP17_COMMON_H */
