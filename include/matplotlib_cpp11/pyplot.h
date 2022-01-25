struct __attribute__((visibility("hidden"))) pyplot {
  pybind11::module mod;
  pybind11::object plot;
  pybind11::object show;
  pybind11::object subplot_attr;
  pybind11::object subplots_attr;
  axes subplot() {
    auto ret = subplot_attr();
    axes ax;
    ax.init(ret);
    return ax;
  }
  std::tuple<figure, axes> subplots() {
    // TODO: a lot of versions like subplots(111) or subplots(py::tuple(1,1,1))
    pybind11::list ret = subplots_attr();
    figure fig;
    fig.init(ret[0]);
    axes ax;
    ax.init(ret[1]);
    return {fig, ax};
  }
};
