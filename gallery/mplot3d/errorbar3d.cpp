// example from https://matplotlib.org/stable/gallery/mplot3d/errorbar3d.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/pyplot.h>

#include <xtensor/xbuilder.hpp>
#include <xtensor/xmath.hpp>

#include <vector>
#include <algorithm>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  auto ax = plt.figure().add_subplot(Args(), Kwargs("projection"_a = "3d"));
  auto t_ = xt::arange(0.0, 2 * M_PI + 0.1, 0.01);
  auto x_ = xt::sin(1.0 * t_);
  auto y_ = xt::cos(3.0 * t_);
  auto z_ = xt::sin(5.0 * t_);
  vector<double> t(t_.begin(), t_.end()), x(x_.begin(), x_.end()),
      y(y_.begin(), y_.end()), z(z_.begin(), z_.end());

  const int estep = 15;
  vector<int> i, zuplims, zlolims;
  std::iota(i.begin(), i.end(), 0);
  std::transform(i.begin(), i.end(), std::back_inserter(zuplims), [](int i) {
    return (i % 15 == 0) and ((i / estep) % 3 == 0);
  });
  std::transform(i.begin(), i.end(), std::back_inserter(zlolims), [](int i) {
    return (i % 15 == 0) and ((i / estep) % 3 == 2);
  });

  ax.errorbar(Args(x, y, z, 0.2),
              Kwargs("zuplims"_a = zuplims, "zlolims"_a = zlolims,
                     "errorevery"_a = estep));

  ax.set_xlabel(Args("X label"));
  ax.set_ylabel(Args("Y label"));
  ax.set_zlabel(Args("Z label"));

  plt.show();
}
