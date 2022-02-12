#ifndef MATPLOTLIBCPP17_COMMON_H
#define MATPLOTLIBCPP17_COMMON_H

#define LOAD_FUNC_ATTR(obj, mod)                                               \
  do {                                                                         \
    obj##_attr = mod.attr(#obj);                                               \
  } while (0)

#define DECL_STRUCT_ATTR __attribute__((visibility("hidden")))

#endif /* MATPLOTLIBCPP17_COMMON_H */
