#include <pybind11/embed.h>

#include "test_lib.h"

namespace py = pybind11;

int main() {
  py::scoped_interpreter guard{};
  func();
}
