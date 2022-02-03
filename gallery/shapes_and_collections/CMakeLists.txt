add_demo(patch_collection patch_collection.cpp)
add_demo(patches_circle_rectangle patches_circle_rectangle.cpp)

add_custom_target(shapes_and_collections
  DEPENDS patch_collection patches_circle_rectangle
  COMMAND patch_collection
  COMMAND patches_circle_rectangle
  COMMENT "running shapes_and_collections"
  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/../images"
)
