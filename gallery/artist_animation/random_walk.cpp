// example from https://matplotlib.org/stable/gallery/animation/random_walk.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/animation.h>

#include <array>
#include <vector>
#include <random>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;
using matplotlibcpp17::animation::ArtistAnimation;

array<double, 3> init_pos() {
  static random_device rnd;
  static mt19937 mt(rnd());
  uniform_real_distribution dist(0.0, 1.0);
  return {dist(mt), dist(mt), dist(mt)};
}

array<double, 3> random_step() {
  static double max_step = 0.05;
  static random_device rnd;
  static mt19937 mt(rnd());
  uniform_real_distribution dist(-max_step, max_step);
  return {dist(mt), dist(mt), dist(mt)};
}

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(py::make_tuple(), kwargs_("projection"_a = "3d"));
  py::list artist_list;
  const int M = 4;
  const int N = 30;
  const vector<string> colors = {"r", "g", "b", "orange"}; // #M
  vector<vector<array<double, 3>>> walks(M);
  for (int i = 0; i < M; ++i) {
    walks[i].emplace_back(init_pos());
  }
  for (int step = 0; step < N; step++) {
    for (int i = 0; i < M; ++i) {
      auto [dx, dy, dz] = random_step();
      auto [x, y, z] = walks[i][step];
      walks[i].push_back({x + dx, y + dy, z + dz});
      vector<double> xs, ys, zs;
      for_each(walks[i].begin(), walks[i].end(),
               [&xs, &ys, &zs](const array<double, 3> &pos) {
                 xs.push_back(pos[0]);
                 ys.push_back(pos[1]);
                 zs.push_back(pos[2]);
               });
      ax.plot(args_(xs, ys, zs), kwargs_("color"_a = colors[i]));
    }
    artist_list.append(ax.get_lines());
  }
  auto ani = ArtistAnimation(args_(fig.unwrap(), artist_list),
                             kwargs_("interval"_a = 100));
#if USE_GUI
  plt.show();
#else
  ani.save(args_("random_walk.gif"), kwargs_("writer"_a = "pillow"));
#endif
  return 0;
}
