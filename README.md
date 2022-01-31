# matplotlibcpp17

This project aims to replace [matplotlibcpp](https://github.com/lava/matplotlib-cpp) using [pybind11](https://github.com/pybind/pybind11) as backend.

## Dependencies

- pybind11(https://github.com/pybind/pybind11) >= 2.9.0
- compatible with matplotlib(https://matplotlib.org/stable/index.html) == 3.5.1 as of now

## Usage

Just add include path to `include` directory of this project.

## Syntax

- `void` functions can be called in almost the same way as python code (remind yourself to append `_a` literal to keyword arguments).
- For `non-void` functions that return some objects, basically the user will need to capsulate *arguments* in `pybind11::tuple` and *keyword arguments* in `pybind11::dict("k1"_a = v1, "k2"_a = v2, ...)`. The returned value is a corresponding wrapper class. Please refer to the examples below.
  - exception: `subplots`, 
  - conversion: Wrapper classes of matplotlibcpp17 like [::container::BarContainer](https://github.com/soblin/matplotlibcpp17/blob/master/include/matplotlibcpp17/container.h) need to be passed to python interpreter using `unwrap()` method in *args* and *kwargs*.

## Examples

### minimal example

```cpp
g++ hello_world.cpp -std=c++17 -I./include -I/usr/include/python3.x -I<path to pybind11> -lpython3.x
./a.out
```

gives

![minimal example](https://github.com/soblin/matplotlibcpp17/blob/master/hello_world.png)

### example1

From [gallery/subplots_axes_and_figures/align_labels_demo.cpp](https://github.com/soblin/matplotlibcpp17/blob/master/gallery/subplots_axes_and_figures/align_labels_demo.cpp).

- [original python code](https://matplotlib.org/stable/gallery/subplots_axes_and_figures/align_labels_demo.html)

```cpp
  auto plt = matplotlibcpp17::pyplot::import();

  // non-void function: capsulate args and kwargs in py::tuple and py::dict
  /// you can call `auto fig = plt.figure()` with default empty arguments :)
  auto fig = plt.figure(py::dict("tight_layout"_a = true));

  // wrapper classes for returned value are implemented in this library
  auto gs = GridSpec(2, 2);

  // non-void function: capsulate args and kwargs in py::tuple and py::dict
  auto ax = fig.add_subplot(py::make_tuple(gs(0, -1)));

  // void function: no need to capsulate args and kwargs
  ax.plot(arange(0, 1000000, 10000));
  ax.set_ylabel("YLabel0");
  ax.set_xlabel("XLabel0");
```

### example2

From [gallery/lines_bars_and_markers/bar_label_demo.cpp](https://github.com/soblin/matplotlibcpp17/blob/master/gallery/lines_bars_and_markers/bar_label_demo.cpp). Here `subplots()` returns `tuple<Figure, Axes>`.

- [original python code](https://matplotlib.org/stable/gallery/lines_bars_and_markers/bar_label_demo.html)

```cpp
  auto [fig, ax] = plt.subplots();
  // non-void function: capsulate args and kwargs in py::tuple and py::dict
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

  // pass wrapper classes like p1 of ::container::BarContainer to the interpreter using .unwrap() method as python object
  ax.bar_label(p1.unwrap(), "label_type"_a = "center");
  ax.bar_label(p2.unwrap(), "label_type"_a = "center");
  ax.bar_label(p2.unwrap());
  plt.show();
```

### example3

Fucntions like `subplots`, `TBD`s are overloaded because they return different types depending on the arguments. Here `subplots()` returns `tuple<Figure, vector<Axes>>`.

From [gallery/lines_bars_and_markers](https://github.com/soblin/matplotlibcpp17/blob/master/gallery/lines_bars_and_markers/fill.cpp)

```cpp
  auto [fig, axes] =
      plt.subplots(1, 3,
                   py::dict("figsize"_a = py::make_tuple(9, 3),
                            "subplot_kw"_a = py::dict("aspect"_a = "equal")));
  auto ax1 = axes[0], ax2 = axes[1], ax3 = axes[2];
```

## Demos

`gallery` folder contains corresponding examples from [the official website of matplotlib](https://matplotlib.org/stable/gallery) with the same structure.

## Contributing

Contributions to this project are welcome if you could add or want/need more modules :)
