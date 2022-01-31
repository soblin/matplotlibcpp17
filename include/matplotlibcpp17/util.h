namespace util {

template <typename... Args> pybind11::tuple args_(Args &&... args) {
  return pybind11::make_tuple(std::forward<Args>(args)...);
}

using kwargs_ = pybind11::dict;

} // namespace util
