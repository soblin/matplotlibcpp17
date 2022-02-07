// example from
// https://matplotlib.org/stable/gallery/animation/animate_decay.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <vector>
#include <algorithm>
#include <string>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17::util;
using matplotlibcpp17::animation::ArtistAnimation;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  const int N = 200;
  vector<double> ts, ys;
  auto [fig, ax] = plt.subplots();
  ax.set_xlim(0, 10);
  ax.set_ylim(-1.1, 1.1);
  py::list artist_list;
  for (int i = 0; i < N; ++i) {
    double t = i * 1.0 / 10;
    double y = sin(2 * M_PI * t) * exp(-t * 1.0 / 10);
    ts.push_back(t);
    ys.push_back(y);
    auto [xmin, xmax] = ax.get_xlim();
    if (t >= xmax)
      ax.set_xlim(xmin, 2 * xmax);
    py::object line = ax.plot(ts, ys, "color"_a = "blue", "lw"_a = 1);
    artist_list.append(line);
  }
  auto ani = ArtistAnimation(args_(fig.unwrap(), artist_list),
                             kwargs_("interval"_a = 10));
  plt.show();
  return 0;
}
