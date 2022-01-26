// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/simple_plot.html#sphx-glr-gallery-lines-bars-and-markers-simple-plot-py

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlib_cpp11/matplotlib_cpp11.h>

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
namespace pyplot = matplotlib_cpp11;

int main() {
  py::initialize_interpreter();
  auto plt = pyplot::import();
  vector<double> t = arange(0.0, 2.0, 0.01);
  decltype(t) s;
  transform(t.begin(), t.end(), back_inserter(s),
            [](double x) { return 1.0 + sin(2 * M_PI * x); });

  auto [fig, ax] = plt.subplots();
  ax.plot(t, s, "color"_a = "blue", "linewidth"_a = 1.0);
  ax.set("xlabel"_a = "time (s)", "ylabel"_a = "voltage (mV)",
         "title"_a = "About as simple as it gets, folks");
  ax.grid();

  fig.savefig("test.png");
  plt.show();
}
