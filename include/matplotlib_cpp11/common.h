#define LOAD_ATTR(attr_, mod_)                                                 \
  do {                                                                         \
    attr_ = mod_.attr(#attr_);                                                 \
  } while (0)
