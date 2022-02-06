add_demo(cla_pause cla_pause.cpp)

add_custom_target(artist_animation
  DEPENDS cla_pause
  COMMAND cla_pause
  COMMENT "running artist_animation"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
