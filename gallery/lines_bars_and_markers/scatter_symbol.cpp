// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/scatter_symbol.html

#include <matplotlibcpp17/pyplot.h>

#include <vector>
#include <string>

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

int main() {
  py::scoped_interpreter guard{};
  auto plt = pyplot::import();
  vector<double> x = {0.,  2.,  4.,  6.,  8.,  10., 12., 14., 16.,
                      18., 20., 22., 24., 26., 28., 30., 32., 34.,
                      36., 38., 40., 42., 44., 46., 48.};
  vector<double> y = {
      21.01101912,  24.74481311,  27.34126659,  27.27298483,  44.26208785,
      41.14266853,  32.72670355,  35.63706738,  57.689303,    64.43917295,
      56.86145395,  65.85596686,  91.33222544,  89.93319308,  90.07761828,
      104.3101143,  105.86324421, 125.79378295, 127.67869682, 131.83987721,
      140.51644988, 140.79566887, 153.22398837, 169.06951457, 174.97156606};
  vector<double> s = {
      736.2911849,   628.75670445,  664.90041181,  607.46030945, 884.4840139,
      774.0174507,   790.37543212,  1278.33411095, 588.75488929, 810.61127126,
      1126.45270023, 1278.31780809, 886.56768427,  769.13688434, 953.93522899,
      538.35320778,  811.14962318,  1225.04291605, 628.81456741, 1094.89690779,
      1006.37932941, 759.34401418,  1237.90122592, 689.78115093, 1159.15645671};
  plt.scatter(Args(x, y, s),
              Kwargs("c"_a = "g", "alpha"_a = 0.5,
                     "marker"_a = R"($\clubsuit$)", "label"_a = "Luck"));
  plt.xlabel(Args("Leprechauns"));
  plt.ylabel(Args("Gold"));
  plt.legend(Kwargs("loc"_a = "upper left"));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("scatter_symbol.png"));
#endif
  return 0;
}
