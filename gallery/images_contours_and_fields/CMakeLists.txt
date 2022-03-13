add_demo(quiver_demo quiver_demo.cpp)
add_demo(contourf_log contourf_log)

add_custom_target(
  images_contours_and_fields
  DEPENDS quiver_demo contourf_log
  COMMAND quiver_demo
  COMMAND contourf_log
  COMMENT "running images_contours_and_fields"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images")
