add_demo(quiver_demo quiver_demo.cpp)

add_custom_target(images_contours_and_fields
  DEPENDS quiver_demo
  COMMAND quiver_demo
  COMMENT "running quiver_demo"
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
)
