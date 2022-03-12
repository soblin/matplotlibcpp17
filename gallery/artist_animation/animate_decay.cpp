// example from
// https://matplotlib.org/stable/gallery/animation/animate_decay.html

#include <matplotlibcpp17/pyplot.h>
#include <matplotlibcpp17/animation.h>

#include <vector>

using namespace std;
using namespace matplotlibcpp17;
using matplotlibcpp17::animation::ArtistAnimation;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  const int N = 200;
  vector<double> ts, ys;
  auto [fig, ax] = plt.subplots();
  ax.set_xlim(Args(0, 10));
  ax.set_ylim(Args(-1.1, 1.1));
  py::list artist_list;
  for (int i = 0; i < N; ++i) {
    double t = i * 1.0 / 10;
    double y = sin(2 * M_PI * t) * exp(-t * 1.0 / 10);
    ts.push_back(t);
    ys.push_back(y);
    auto [xmin, xmax] = ax.get_xlim();
    if (t >= xmax)
      ax.set_xlim(Args(xmin, 2 * xmax));
    py::object line =
        ax.plot(Args(ts, ys), Kwargs("color"_a = "blue", "lw"_a = 1));
    artist_list.append(line);
  }
  auto ani = ArtistAnimation(Args(fig.unwrap(), artist_list),
                             Kwargs("interval"_a = 10));
#if USE_GUI
  plt.show();
#else
  ani.save(Args("animate_decay.gif"), Kwargs("writer"_a = "pillow"));
#endif
  return 0;
}
