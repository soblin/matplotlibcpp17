// example from https://note.nkmk.me/python-matplotlib-patches-circle-rectangle

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/patches.h>

#include <algorithm>
#include <vector>

using namespace std;
using namespace matplotlibcpp17;
using namespace matplotlibcpp17::patches;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = plt.axes();
  auto c = Circle(Args(py::make_tuple(0, 0), 0.5),
                  Kwargs("fc"_a = "g", "ec"_a = "r"));
  auto e = Ellipse(Args(py::make_tuple(-0.25, 0), 0.5, 0.25),
                   Kwargs("fc"_a = "b", "ec"_a = "y"));
  auto r = Rectangle(Args(py::make_tuple(0, 0), 0.25, 0.5),
                     Kwargs("ec"_a = "#000000", "fill"_a = false));
  ax.add_patch(Args(c.unwrap()));
  ax.add_patch(Args(e.unwrap()));
  ax.add_patch(Args(r.unwrap()));
  plt.axis(Args("scaled"));
  ax.set_aspect(Args("equal"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("patches_circle_rectangle.png"));
#endif
}
