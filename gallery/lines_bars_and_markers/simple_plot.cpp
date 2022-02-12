// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/simple_plot.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

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
    ;
    val += h;
  }
  return xs;
}

using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  vector<double> t = arange(0.0, 2.0, 0.01);
  decltype(t) s;
  transform(t.begin(), t.end(), back_inserter(s),
            [](double x) { return 1.0 + sin(2 * M_PI * x); });

  auto [fig, ax] = plt.subplots();
  ax.plot(args_(t, s), kwargs_("color"_a = "blue", "linewidth"_a = 1.0));
  ax.set(args_(), kwargs_("xlabel"_a = "time (s)", "ylabel"_a = "voltage (mV)",
         "title"_a = "About as simple as it gets, folks"));
  ax.grid();

#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("simple_plot.png"));
#endif
  return 0;
}
