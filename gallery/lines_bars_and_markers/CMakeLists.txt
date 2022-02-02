add_demo(bar_label_demo bar_label_demo.cpp)
add_demo(fill fill.cpp)
add_demo(simple_plot simple_plot.cpp)
add_demo(scatter_symbol scatter_symbol.cpp)
add_demo(fill_between_demo fill_between_demo.cpp)
add_demo(fill_betweenx_demo fill_betweenx_demo.cpp)
add_demo(scatter_with_legend scatter_with_legend.cpp)
add_demo(scatter_hist scatter_hist.cpp)

# TODO: macro for this!
add_custom_target(lines_bars_and_markers
  DEPENDS bar_label_demo fill simple_plot scatter_symbol fill_between_demo fill_betweenx_demo scatter_with_legend scatter_hist
  COMMAND bar_label_demo
  COMMENT "running bar_label_demo"
  COMMAND fill
  COMMENT "running fill"
  COMMAND simple_plot
  COMMENT "running simple_plot"
  COMMAND scatter_symbol
  COMMENT "running scatter_symbol"
  COMMAND fill_between_demo
  COMMENT "running fill_between_demo"
  COMMAND fill_betweenx_demo
  COMMENT "running fill_betweenx_demo"
  COMMAND scatter_with_legend
  COMMENT "running scatter_with_legend"
  COMMAND scatter_hist
  COMMENT "running scatter_hist"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
