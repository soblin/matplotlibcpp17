add_demo(lines3d lines3d.cpp)
add_demo(lorenz_attractor lorenz_attractor.cpp)
add_demo(contour3d contour3d.cpp)
add_demo(subplot3d subplot3d.cpp)
add_demo(errorbar3d errorbar3d.cpp)
add_demo(surface3d surface3d)

add_custom_target(mplot3d
  DEPENDS lines3d lorenz_attractor contour3d subplot3d errorbar3d surface3d
  COMMAND lines3d
  COMMAND lorenz_attractor
  COMMAND contour3d
  COMMAND subplot3d
  COMMAND errorbar3d
  COMMAND surface3d
  COMMENT "running mplot3d"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
