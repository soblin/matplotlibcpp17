# matplotlib-cpp11

This project aims to replace [matplotlibcpp](https://github.com/lava/matplotlib-cpp) using [pybind11](https://github.com/pybind/pybind11) as backend.

## Dependencies

- pybind11(https://github.com/pybind/pybind11) >= version2.9.0
- compatible with matplotlib(https://matplotlib.org/stable/index.html) == 3.5.1 as of now

## Usage

Just add include path to `include` directory of this project.

## Syntax

- `void` functions can be called in almost the same way as python code (remind yourself to append `_a` literal to keyword arguments).
- (**tentative**) For `non-void` functions that return some objects, basically the user will need to capsulate *arguments* in `pybind11::tuple` and *keyword arguments* in `pybind11::dict("k1"_a = v1, "k2"_a = v2, ...)`. The returned value is a corresponding wrapper class. Please refer to the examples below.
  - exception: `subplots`, 

### example1

From [gallery/subplots_axes_and_figures/align_labels_demo.cpp](https://github.com/soblin/matplotlib-cpp11/blob/master/gallery/subplots_axes_and_figures/align_labels_demo.cpp).

- [original python code](https://matplotlib.org/stable/gallery/subplots_axes_and_figures/align_labels_demo.html)

```cpp
  // plt object(singleton object)
  auto plt = matplotlib_cpp11::pyplot::import();

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

From [gallery/lines_bars_and_markers/fill_between_demo.cpp](https://github.com/soblin/matplotlib-cpp11/blob/master/gallery/lines_bars_and_markers/fill_between_demo.cpp).

- [original python code](https://matplotlib.org/stable/gallery/lines_bars_and_markers/fill_between_demo.html)

```cpp
  // non-void function: capsulate args and kwargs in py::tuple and py::dict
  /// subplot returns different types depending on the argument value, so this function is overloaded (see pyplot.h).
  auto [fig, axs] = plt.subplots(2, 1, py::dict("sharex"_a = true));
  auto ax1 = axs[0], ax2 = axs[1];

  // void function: no need to capsulate args and kwargs
  ax1.set_title("interpolation=False");
  ax1.plot(x, y1, "o--");
  ax1.plot(x, y2, "o--");
  vector<bool> where = {true, true, false, false};
  ax1.fill_between(x, y1, y2, "where"_a = where, "color"_a = "C0",
                   "alpha"_a = 0.3);
  where = {false, false, true, true};
  ax1.fill_between(x, y1, y2, "where"_a = where, "color"_a = "C1",
                   "alpha"_a = 0.3);
```

## Demos

`gallery` folder contains corresponding examples from [the official website of matplotlib](https://matplotlib.org/stable/gallery) with the same structure.

## Contributing

Contributions to this project are welcome if you could add or want/need more modules :)
