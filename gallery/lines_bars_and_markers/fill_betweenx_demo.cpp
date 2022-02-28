// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill_betweenx_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;

template <typename T> std::vector<T> arange(T start, T end, T h) {
  int N = static_cast<int>((end - start) / h);
  std::vector<T> xs(N);
  T val = start;
  for (int i = 0; i < N; ++i) {
    xs[i] = val;
    val += h;
  }
  return xs;
}

using namespace std;

using namespace matplotlibcpp17;

int main1() {
  auto plt = matplotlibcpp17::pyplot::import();
  vector<double> y = arange(0.0, 2.0, 0.01);
  vector<double> x1, x2;
  transform(y.begin(), y.end(), back_inserter(x1),
            [](double y) { return sin(2 * M_PI * y); });
  transform(y.begin(), y.end(), back_inserter(x2),
            [](double y) { return 1.2 * sin(4 * M_PI * y); });
  auto [fig, axes] = plt.subplots(
      1, 3, kwargs_("sharey"_a = true, "figsize"_a = py::make_tuple(6, 6)));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];

  ax1.fill_betweenx(args_(y, 0, x1));
  ax1.set_title(args_("between (x1, 0)"));

  ax2.fill_betweenx(args_(y, x1, 1));
  ax2.set_title(args_("between (x1, 1)"));
  ax2.set_xlabel(args_("x"));
  
  ax3.fill_betweenx(args_(y, x1, x2));
  ax3.set_title(args_("between (x1, x2)"));

#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("fill_betweenx_demo.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
}
