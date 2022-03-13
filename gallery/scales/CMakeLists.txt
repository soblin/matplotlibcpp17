add_demo(aspect_loglog aspect_loglog.cpp)

add_custom_target(scales
  DEPENDS aspect_loglog
  COMMAND aspect_loglog
  COMMENT "running scales"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
