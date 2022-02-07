add_demo(cla_pause cla_pause.cpp)
add_demo(animate_decay animate_decay.cpp)

add_custom_target(artist_animation
  DEPENDS cla_pause animate_decay
  COMMAND cla_pause
  COMMAND animate_decay
  COMMENT "running artist_animation"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
