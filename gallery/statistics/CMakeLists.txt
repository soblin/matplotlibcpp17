add_demo(hist hist.cpp)

add_custom_target(statitics
  DEPENDS hist
  COMMAND hist
  COMMENT "running hist"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
