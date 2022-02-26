add_demo(lines3d lines3d.cpp)

# TODO: macro for this!
add_custom_target(mplot3d
  DEPENDS lines3d
  COMMAND lines3d
  COMMENT "running lines3d"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
