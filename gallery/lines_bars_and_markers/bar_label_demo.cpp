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

int main1() {
  const int N = 5;
  auto menMeans = py::make_tuple(20, 35, 30, 35, -27);
  auto womenMeans = py::make_tuple(25, 32, 34, 20, -25);
  auto menStd = py::make_tuple(2, 3, 4, 1, 2);
  auto womenStd = py::make_tuple(3, 5, 2, 3, 3);
  vector<int> ind = {0, 1, 2, 3, 4}; // the x locations for the groups
  const double width =
      0.35; // the width of the bars: can also be len(x) sequence
  auto plt = matplotlibcpp17::pyplot::import();
  auto [fig, ax] = plt.subplots();
  auto p1 = ax.bar(py::make_tuple(ind, menMeans, width),
                   py::dict("yerr"_a = menStd, "label"_a = "Men"));
  auto p2 = ax.bar(py::make_tuple(ind, womenMeans, width),
                   py::dict("bottom"_a = menMeans, "yerr"_a = womenStd,
                            "label"_a = "Women"));
  ax.axhline(0, "color"_a = "grey", "linewidth"_a = 0.8);
  ax.set_ylabel("Scores");
  ax.set_title("Scores by group and gender");
  ax.set_xticks(ind, py::make_tuple("G1", "G2", "G3", "G4", "G5"));
  ax.legend();

  // Label with label_type 'center' instead of the default 'edge'
  ax.bar_label(p1.unwrap(), "label_type"_a = "center");
  ax.bar_label(p2.unwrap(), "label_type"_a = "center");
  ax.bar_label(p2.unwrap());
  plt.show();
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
  auto hbars = ax.barh(py::make_tuple(y_pos, performance),
                       py::dict("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(y_pos, "labels"_a = people);
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel("Performance");
  ax.set_title("How fast do you want to go today?");

  // Label with specially formatted floats
  ax.bar_label(hbars.unwrap(), "fmt"_a = "%.2f");
  ax.set_xlim("right"_a = 15); // adjust xlim to fit labels
  plt.show();
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
  auto hbars = ax.barh(py::make_tuple(y_pos, performance),
                       py::dict("xerr"_a = error, "align"_a = "center"));
  ax.set_yticks(y_pos, "labels"_a = people);
  ax.invert_yaxis(); // labels read top-to-bottom
  ax.set_xlabel("Performance");
  ax.set_title("How fast do you want to go today?");

  // Label with specially formatted floats
  vector<string> labels;
  transform(error.begin(), error.end(), back_inserter(labels), [](double e) {
    stringstream stm;
    stm << std::fixed << std::setprecision(2) << e;
    return "±" + stm.str();
  });
  ax.bar_label(hbars.unwrap(), "labels"_a = labels, "padding"_a = 8,
               "color"_a = "b", "fontsize"_a = 14);
  ax.set_xlim("right"_a = 15); // adjust xlim to fit labels
  plt.show();
  return 0;
}

int main() {
  py::initialize_interpreter();
  main1();
  main2();
  main3();
  return 0;
}
