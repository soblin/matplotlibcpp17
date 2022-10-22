// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/bar_label_demo.html

#include <matplotlibcpp17/pyplot.h>

#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;
using namespace matplotlibcpp17;

int main1() {
  const vector<int> menMeans = {20, 35, 30, 35, -27};
  const vector<int> womenMeans = {25, 32, 34, 20, -25};
  const vector<int> menStd = {2, 3, 4, 1, 2};
  const vector<int> womenStd = {3, 5, 2, 3, 3};
  const vector<int> ind = {0, 1, 2, 3, 4}; // the x locations for the groups
  const double width =
      0.35; // the width of the bars: can also be len(x) sequence
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto p1 = ax.bar(Args(ind, menMeans, width),
                   Kwargs("yerr"_a = menStd, "label"_a = "Men"));
  auto p2 = ax.bar(
      Args(ind, womenMeans, width),
      Kwargs("bottom"_a = menMeans, "yerr"_a = womenStd, "label"_a = "Women"));
  ax.axhline(Args(0), Kwargs("color"_a = "grey", "linewidth"_a = 0.8));
  ax.set_ylabel(Args("Scores"));
  ax.set_title(Args("Scores by group and gender"));
  ax.set_xticks(Args(ind, py::make_tuple("G1", "G2", "G3", "G4", "G5")));
  ax.legend();

  // Label with label_type 'center' instead of the default 'edge'
  ax.bar_label(Args(p1.unwrap()), Kwargs("label_type"_a = "center"));
  ax.bar_label(Args(p2.unwrap()), Kwargs("label_type"_a = "center"));
  ax.bar_label(Args(p2.unwrap()));
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("bar_label_demo1.png"));
#endif
  return 0;
}

int main2() {
  const vector<string> people = {"Tom", "Dick", "Harry", "Slim", "Jim"};
  const vector<int> y_pos = {0, 1, 2, 3, 4};
  const vector<double> performance = {10.00367304, 10.42750809, 10.09280011,
                                      8.66745522, 12.77785333};
  const vector<double> error = {0.70633485, 0.24791576, 0.15788335, 0.69769852,
                                0.71995667};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto hbars = ax.barh(Args(y_pos, performance),
                       Kwargs("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(Args(y_pos), Kwargs("labels"_a = people));
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel(Args("Performance"));
  ax.set_title(Args("How fast do you want to go today?"));

  // Label with specially formatted floats
  ax.bar_label(Args(hbars.unwrap()), Kwargs("fmt"_a = "%.2f"));
  ax.set_xlim(Args(), Kwargs("right"_a = 15)); // adjust xlim to fit labels
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("bar_label_demo2.png"));
#endif
  return 0;
}

int main3() {
  const vector<string> people = {"Tom", "Dick", "Harry", "Slim", "Jim"};
  const vector<int> y_pos = {0, 1, 2, 3, 4};
  const vector<double> performance = {10.00367304, 10.42750809, 10.09280011,
                                      8.66745522, 12.77785333};
  const vector<double> error = {0.70633485, 0.24791576, 0.15788335, 0.69769852,
                                0.71995667};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto hbars = ax.barh(Args(y_pos, performance),
                       Kwargs("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(Args(y_pos), Kwargs("labels"_a = people));
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel(Args("Performance"));
  ax.set_title(Args("How fast do you want to go today?"));

  // Label with specially formatted floats
  vector<string> labels;
  transform(error.begin(), error.end(), back_inserter(labels), [](double e) {
    stringstream stm;
    stm << std::fixed << std::setprecision(2) << e;
    return "±" + stm.str();
  });
  ax.bar_label(Args(hbars.unwrap()),
               Kwargs("labels"_a = labels, "padding"_a = 8, "color"_a = "b",
                      "fontsize"_a = 14));
  ax.set_xlim(Args(), Kwargs("right"_a = 15)); // adjust xlim to fit labels
#if USE_GUI
  plt.show();
#else
  plt.savefig(Args("bar_label_demo3.png"));
#endif
  return 0;
}

int main() {
  py::scoped_interpreter guard{};
  main1();
  main2();
  main3();
  return 0;
}
