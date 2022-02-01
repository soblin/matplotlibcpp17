#define LOAD_VOID_ATTR(obj, mod)                                               \
  do {                                                                         \
    obj = mod.attr(#obj);                                                      \
  } while (0)

#define LOAD_NONVOID_ATTR(obj, mod)                                            \
  do {                                                                         \
    obj##_attr = mod.attr(#obj);                                               \
  } while (0)

#define DECL_STRUCT_ATTR __attribute__((visibility("hidden")))
