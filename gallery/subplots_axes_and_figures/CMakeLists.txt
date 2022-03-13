add_demo(align_labels_demo align_labels_demo.cpp)
add_demo(gridspec_multicolumn gridspec_multicolumn.cpp)
add_demo(multiple_figs_demo multiple_figs_demo.cpp)
add_demo(colorbar_placement colorbar_placement.cpp)
add_demo(subplots subplots.cpp)
add_demo(two_scales two_scales.cpp)

add_custom_target(subplots_axes_and_figures
  DEPENDS align_labels_demo gridspec_multicolumn multiple_figs_demo colorbar_placement two_scales
  COMMAND align_labels_demo
  COMMAND gridspec_multicolumn
  COMMAND multiple_figs_demo
  COMMAND colorbar_placement
  COMMAND two_scales
  COMMENT "subplots_axes_and_figures"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
