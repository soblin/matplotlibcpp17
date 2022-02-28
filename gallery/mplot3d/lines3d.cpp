// example from https://matplotlib.org/stable/gallery/mplot3d/lines3d.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>
#include <matplotlibcpp17/pyplot.h>
#include <algorithm>
#include <vector>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

template <typename T> std::vector<T> linspace(T start, T end, int N) {
  double h = static_cast<double>((end - start) * 1.0 / N);
  std::vector<T> xs(N);
  T val = start;
  for (int i = 0; i < N; ++i) {
    xs[i] = val;
    val += h;
  }
  return xs;
}

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  auto fig = plt.figure();
  auto ax = fig.add_subplot(args_(), kwargs_("projection"_a = "3d"));
  vector<double> theta = linspace(-4 * M_PI, 4 * M_PI, 100);
  vector<double> z = linspace(-2.0, 2.0, 100);
  vector<double> r, x, y;
  transform(z.begin(), z.end(), back_inserter(r),
            [](double z) { return z * z + 1.0; });
  for (unsigned i = 0; i < z.size(); ++i) {
    x.push_back(r[i] * sin(theta[i]));
    y.push_back(r[i] * cos(theta[i]));
  }
  ax.plot(args_(x, y, z), kwargs_("label"_a = "parametric curve"));
  ax.legend();
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("lines3d.png"));
#endif
}
