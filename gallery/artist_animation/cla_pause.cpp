#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <vector>
#include <algorithm>
#include <string>

namespace py = pybind11;
using namespace py::literals;
using namespace std;
using namespace matplotlibcpp17;

int main() {
  py::scoped_interpreter guard{};
  auto plt = matplotlibcpp17::pyplot::import();
  vector<int> data;
  const int N = 10;
  for (int i = 0; i <= N; ++i) {
    plt.xlim(args_(0, 10));
    plt.ylim(args_(0, 10));
    data.push_back(i);
    plt.plot(args_(data));
    plt.pause(args_(1));
    plt.cla();
  }
  return 0;
}
