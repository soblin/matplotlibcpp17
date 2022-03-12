// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/simple_plot.html

#include <matplotlibcpp17/pyplot.h>

#include <algorithm>
#include <vector>

template <typename T> std::vector<T> arange(T start, T end, T h) {
  int N = static_cast<int>((end - start) / h);
  std::vector<T> xs(N);
  T val = start;
  while (val <= end) {
    xs.push_back(val);
    val += h;
  }
  return xs;
}

using namespace std;
using namespace matplotlibcpp17;

void func() {
  auto plt = matplotlibcpp17::pyplot::import();
  auto t = arange(0.0, 2.0, 0.01);
  decltype(t) s;
  transform(t.begin(), t.end(), back_inserter(s),
            [](double x) { return 1.0 + sin(2 * M_PI * x); });

  auto [fig, ax] = plt.subplots();
  ax.plot(Args(t, s), Kwargs("color"_a = "blue", "linewidth"_a = 1.0));
  ax.set(Args(), Kwargs("xlabel"_a = "time (s)", "ylabel"_a = "voltage (mV)",
                        "title"_a = "About as simple as it gets, folks"));
  ax.grid();

  fig.savefig(Args("test.png"));
  plt.show();
}
