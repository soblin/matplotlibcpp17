add_demo(align_labels_demo align_labels_demo.cpp)
add_demo(gridspec_multicolumn gridspec_multicolumn.cpp)

add_custom_target(subplots_axes_and_figures
  DEPENDS align_labels_demo gridspec_multicolumn
  COMMAND align_labels_demo
  COMMENT "running align_labels_demo"
  COMMAND gridspec_multicolumn
  COMMENT "running gridspec_multicolumn"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
