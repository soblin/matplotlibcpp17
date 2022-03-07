add_demo(hist hist.cpp)
add_demo(errorbar errorbar.cpp)

add_custom_target(statitics
  DEPENDS hist errorbar
  COMMAND hist
  COMMAND errorbar
  COMMENT "running hist"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
