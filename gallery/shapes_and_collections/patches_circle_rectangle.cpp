// example from https://note.nkmk.me/python-matplotlib-patches-circle-rectangle

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <algorithm>
#include <iostream>
#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;
using namespace matplotlibcpp17::patches;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = plt.axes();
  auto c = Circle(args_(py::make_tuple(0, 0), 0.5),
                  kwargs_("fc"_a = "g", "ec"_a = "r"));
  auto e = Ellipse(args_(py::make_tuple(-0.25, 0), 0.5, 0.25),
                   kwargs_("fc"_a = "b", "ec"_a = "y"));
  auto r = Rectangle(args_(py::make_tuple(0, 0), 0.25, 0.5),
                     kwargs_("ec"_a = "#000000", "fill"_a = false));
  ax.add_patch(args_(c.unwrap()));
  ax.add_patch(args_(e.unwrap()));
  ax.add_patch(args_(r.unwrap()));
  plt.axis(args_("scaled"));
  ax.set_aspect(args_("equal"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("patches_circle_rectangle.png"));
#endif
}
