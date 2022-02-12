// example from
// https://matplotlib.org/stable/gallery/lines_bars_and_markers/bar_label_demo.html

#include <pybind11/embed.h>
#include <pybind11/stl.h>

#include <matplotlibcpp17/matplotlibcpp17.h>

#include <algorithm>
#include <vector>
#include <iomanip>
#include <iostream>

namespace py = pybind11;
using namespace py::literals;

using namespace std;

using namespace matplotlibcpp17;

int main1() {
  vector<int> menMeans = {20, 35, 30, 35, -27};
  vector<int> womenMeans = {25, 32, 34, 20, -25};
  vector<int> menStd = {2, 3, 4, 1, 2};
  vector<int> womenStd = {3, 5, 2, 3, 3};
  vector<int> ind = {0, 1, 2, 3, 4}; // the x locations for the groups
  const double width =
      0.35; // the width of the bars: can also be len(x) sequence
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto p1 = ax.bar(args_(ind, menMeans, width),
                   kwargs_("yerr"_a = menStd, "label"_a = "Men"));
  auto p2 = ax.bar(
      args_(ind, womenMeans, width),
      kwargs_("bottom"_a = menMeans, "yerr"_a = womenStd, "label"_a = "Women"));
  ax.axhline(args_(0), kwargs_("color"_a = "grey", "linewidth"_a = 0.8));
  ax.set_ylabel(args_("Scores"));
  ax.set_title(args_("Scores by group and gender"));
  ax.set_xticks(args_(ind, py::make_tuple("G1", "G2", "G3", "G4", "G5")));
  ax.legend();

  // Label with label_type 'center' instead of the default 'edge'
  ax.bar_label(args_(p1.unwrap()), kwargs_("label_type"_a = "center"));
  ax.bar_label(args_(p2.unwrap()), kwargs_("label_type"_a = "center"));
  ax.bar_label(args_(p2.unwrap()));
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("bar_label_demo1.png"));
#endif
  return 0;
}

int main2() {
  vector<string> people = {"Tom", "Dick", "Harry", "Slim", "Jim"};
  vector<int> y_pos = {0, 1, 2, 3, 4};
  vector<double> performance = {10.00367304, 10.42750809, 10.09280011,
                                8.66745522, 12.77785333};
  vector<double> error = {0.70633485, 0.24791576, 0.15788335, 0.69769852,
                          0.71995667};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto hbars = ax.barh(args_(y_pos, performance),
                       kwargs_("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(args_(y_pos), kwargs_("labels"_a = people));
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel(args_("Performance"));
  ax.set_title(args_("How fast do you want to go today?"));

  // Label with specially formatted floats
  ax.bar_label(args_(hbars.unwrap()), kwargs_("fmt"_a = "%.2f"));
  ax.set_xlim(args_(), kwargs_("right"_a = 15)); // adjust xlim to fit labels
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("bar_label_demo2.png"));
#endif
  return 0;
}

int main3() {
  vector<string> people = {"Tom", "Dick", "Harry", "Slim", "Jim"};
  vector<int> y_pos = {0, 1, 2, 3, 4};
  vector<double> performance = {10.00367304, 10.42750809, 10.09280011,
                                8.66745522, 12.77785333};
  vector<double> error = {0.70633485, 0.24791576, 0.15788335, 0.69769852,
                          0.71995667};
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto hbars = ax.barh(args_(y_pos, performance),
                       kwargs_("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(args_(y_pos), kwargs_("labels"_a = people));
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel(args_("Performance"));
  ax.set_title(args_("How fast do you want to go today?"));

  // Label with specially formatted floats
  vector<string> labels;
  transform(error.begin(), error.end(), back_inserter(labels), [](double e) {
    stringstream stm;
    stm << std::fixed << std::setprecision(2) << e;
    return "±" + stm.str();
  });
  ax.bar_label(args_(hbars.unwrap()), kwargs_("labels"_a = labels, "padding"_a = 8,
               "color"_a = "b", "fontsize"_a = 14));
  ax.set_xlim(args_(), kwargs_("right"_a = 15)); // adjust xlim to fit labels
#if USE_GUI
  plt.show();
#else
  plt.savefig(args_("bar_label_demo3.png"));
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
