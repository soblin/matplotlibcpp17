// example from https://matplotlib.org/stable/gallery/animation/random_walk.html

#include <matplotlibcpp17/axes.h>
#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/animation.h>
#include <matplotlibcpp17/mplot3d.h>

#include <xtensor/xrandom.hpp>
#include <xtensor/xbuilder.hpp>
#include <xtensor/xview.hpp>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;
using matplotlibcpp17::animation::ArtistAnimation;

xt::xtensor<double, 2> random_walk(int num_steps, double max_step = 0.05) {
  auto start_pos = xt::random::rand<double>({3, 1});
  auto steps_ = xt::random::rand<double>({3, num_steps}, -max_step, max_step);
  auto steps = xt::hstack(xt::xtuple(start_pos, steps_)); // {3, num_steps+1}
  auto walk = xt::cumsum(steps, 1);                       // {3, num_steps+1}
  return walk;
}

int main() {
  static const int M = 4;
  const int num_steps = 30;
  const vector<string> colors = {"r", "g", "b", "orange"}; // #M
  auto walks = xt::xtensor<double, 3>::from_shape({M, 3, num_steps + 1});
  for (int i = 0; i < M; ++i) {
    auto walk = xt::view(walks, i, xt::all(), xt::all());
    walk = random_walk(num_steps);
  }
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  // this is required for "projection = 3d"
  matplotlibcpp17::mplot3d::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(py::make_tuple(), Kwargs("projection"_a = "3d"));
  py::list artist_list;
  for (int j = 1; j <= num_steps; ++j) {
    for (int i = 0; i < M; ++i) {
      auto xs0 = xt::view(walks, i, 0, xt::range(1, j + 1));
      auto ys0 = xt::view(walks, i, 1, xt::range(1, j + 1));
      auto zs0 = xt::view(walks, i, 2, xt::range(1, j + 1));
      // to vector
      vector<double> xs(xs0.begin(), xs0.end());
      vector<double> ys(ys0.begin(), ys0.end());
      vector<double> zs(zs0.begin(), zs0.end());
      ax.plot(Args(xs, ys, zs), Kwargs("color"_a = colors[i]));
    }
    artist_list.append(ax.get_lines().unwrap());
  }
  auto ani = ArtistAnimation(Args(fig.unwrap(), artist_list),
                             Kwargs("interval"_a = 100));
#if USE_GUI
  plt.show();
#else
  ani.save(Args("random_walk.gif"), Kwargs("writer"_a = "pillow"));
#endif
  return 0;
}
