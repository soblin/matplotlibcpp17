namespace axes {

struct DECL_STRUCT_ATTR Axes {
  Axes(pybind11::object axes) {
    self = axes;
    load_attrs();
  }
  void load_attrs() {
    LOAD_VOID_ATTR(add_artist, self);
    LOAD_VOID_ATTR(add_collection, self);
    LOAD_VOID_ATTR(add_patch, self);
    LOAD_VOID_ATTR(axhline, self);
    LOAD_NONVOID_ATTR(bar, self);
    LOAD_VOID_ATTR(bar_label, self);
    LOAD_NONVOID_ATTR(barh, self);
    LOAD_VOID_ATTR(fill, self);
    LOAD_VOID_ATTR(fill_between, self);
    LOAD_VOID_ATTR(fill_betweenx, self);
    LOAD_VOID_ATTR(get_xaxis_transform, self);
    LOAD_NONVOID_ATTR(get_xlim, self);
    LOAD_NONVOID_ATTR(get_xticklabels, self);
    LOAD_VOID_ATTR(grid, self);
    LOAD_NONVOID_ATTR(hist, self);
    LOAD_VOID_ATTR(hist2d, self);
    LOAD_VOID_ATTR(invert_yaxis, self);
    LOAD_NONVOID_ATTR(legend, self);
    LOAD_VOID_ATTR(plot, self);
    LOAD_NONVOID_ATTR(quiver, self);
    LOAD_NONVOID_ATTR(quiverkey, self);
    LOAD_NONVOID_ATTR(scatter, self);
    LOAD_VOID_ATTR(set, self);
    LOAD_VOID_ATTR(set_aspect, self);
    LOAD_VOID_ATTR(set_title, self);
    LOAD_VOID_ATTR(set_xlabel, self);
    LOAD_VOID_ATTR(set_xlim, self);
    LOAD_VOID_ATTR(set_xticks, self);
    LOAD_VOID_ATTR(set_ylabel, self);
    LOAD_VOID_ATTR(set_ylim, self);
    LOAD_VOID_ATTR(set_yticks, self);
    LOAD_VOID_ATTR(text, self);
    LOAD_VOID_ATTR(tick_params, self);
  }
  pybind11::object self;

  // for passing as python object
  pybind11::object unwrap() { return self; }

  // add_artist
  pybind11::object add_artist;

  // add_collection
  pybind11::object add_collection;

  // add_patch
  pybind11::object add_patch;

  // axhline
  pybind11::object axhline;

  // bar
  container::BarContainer bar(const pybind11::tuple &args,
                              const pybind11::dict &kwargs);
  pybind11::object bar_attr;

  // bar_label
  pybind11::object bar_label;

  // barh
  container::BarContainer barh(const pybind11::tuple &args,
                               const pybind11::dict &kwargs);
  pybind11::object barh_attr;

  // fill
  pybind11::object fill;

  // fill_between
  pybind11::object fill_between;

  // fill_betweenx
  pybind11::object fill_betweenx;

  // get_xaxis_transform
  /// TODO: currently returns py::object
  pybind11::object get_xaxis_transform;

  // get_xlim
  std::tuple<double, double> get_xlim();
  pybind11::object get_xlim_attr;

  // get_xticklabels
  std::vector<text::Text> get_xticklabels();
  pybind11::object get_xticklabels_attr;

  // grid
  pybind11::object grid;

  // hist
  std::tuple<std::vector<double>, std::vector<double>, container::BarContainer>
  hist(const pybind11::tuple &args, const pybind11::dict &kwargs);
  pybind11::object hist_attr;

  // hist2d
  pybind11::object hist2d;

  // invert_yaxis
  pybind11::object invert_yaxis;

  // legend
  legend::Legend legend(const pybind11::tuple &args,
                        const pybind11::dict &kwargs);

  pybind11::object legend_attr;

  // plot
  // TODO: should return `artists` for gif?
  pybind11::object plot;

  // quiver
  quiver::Quiver quiver(const pybind11::tuple &args,
                        const pybind11::dict &kwargs);
  pybind11::object quiver_attr;

  // quiverkey
  quiver::QuiverKey quiverkey(const pybind11::tuple &args,
                              const pybind11::dict &kwargs);
  pybind11::object quiverkey_attr;

  // scatter
  // TODO: should return `artist` for gif?
  collections::PathCollection scatter(const pybind11::tuple &args,
                                      const pybind11::dict &kwargs);
  pybind11::object scatter_attr;

  // set
  pybind11::object set;

  // set
  pybind11::object set_aspect;

  // set_title
  pybind11::object set_title;

  // set_xlabel
  pybind11::object set_xlabel;

  // set_xlim
  pybind11::object set_xlim;

  // set_xticks
  pybind11::object set_xticks;

  // set_ylabel
  pybind11::object set_ylabel;

  // set_ylim
  pybind11::object set_ylim;

  // set_yticks
  pybind11::object set_yticks;

  // text
  pybind11::object text;

  // tick_params
  pybind11::object tick_params;
};

// bar
container::BarContainer Axes::bar(const pybind11::tuple &args,
                                  const pybind11::dict &kwargs) {
  pybind11::object obj = bar_attr(*args, **kwargs);
  return container::BarContainer(obj);
}

// barh
container::BarContainer Axes::barh(const pybind11::tuple &args,
                                   const pybind11::dict &kwargs) {
  pybind11::object obj = barh_attr(*args, **kwargs);
  return container::BarContainer(obj);
}

// get_xlim
std::tuple<double, double> Axes::get_xlim() {
  pybind11::list ret = get_xlim_attr();
  double x1 = ret[0].cast<double>();
  double x2 = ret[1].cast<double>();
  return {x1, x2};
}

// get_xticklabels
std::vector<text::Text> Axes::get_xticklabels() {
  pybind11::list ret = get_xticklabels_attr();
  std::vector<text::Text> texts;
  for (pybind11::size_t i = 0; i < ret.size(); ++i) {
    texts.push_back(text::Text(ret[i]));
  }
  return texts;
}

// hist
std::tuple<std::vector<double>, std::vector<double>, container::BarContainer>
Axes::hist(const pybind11::tuple &args, const pybind11::dict &kwargs) {
  pybind11::list ret = hist_attr(*args, **kwargs);
  // parse N, bins, patches
  pybind11::list N_obj = ret[0], bins_obj = ret[1];
  pybind11::object patches_obj = ret[2];
  std::vector<double> N, bins;
  for (auto it = N_obj.begin(); it != N_obj.end(); it++) {
    N.push_back(it->cast<double>());
  }
  for (auto it = bins_obj.begin(); it != bins_obj.end(); it++) {
    bins.push_back(it->cast<double>());
  }
  return {N, bins, container::BarContainer(patches_obj)};
}

// legend
legend::Legend Axes::legend(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = legend_attr(*args, **kwargs);
  return legend::Legend(obj);
}

// quiver
quiver::Quiver Axes::quiver(const pybind11::tuple &args = pybind11::tuple(),
                            const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = quiver_attr(*args, **kwargs);
  return quiver::Quiver(obj);
}

// quiverkey
quiver::QuiverKey
Axes::quiverkey(const pybind11::tuple &args = pybind11::tuple(),
                const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = quiverkey_attr(*args, **kwargs);
  return quiver::QuiverKey(obj);
}

// scatter
collections::PathCollection
Axes::scatter(const pybind11::tuple &args = pybind11::tuple(),
              const pybind11::dict &kwargs = pybind11::dict()) {
  pybind11::object obj = scatter_attr(*args, **kwargs);
  return collections::PathCollection(obj);
}

} // namespace axes
