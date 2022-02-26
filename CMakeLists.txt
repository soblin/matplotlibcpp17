project(matplotlibcpp17)
cmake_minimum_required(VERSION 3.12)

find_package(Python3 COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)

if(NOT DEFINED ADD_DEMO)
  set(ADD_DEMO ON)
endif()

if(NOT DEFINED USE_GUI)
  set(USE_GUI 0)
endif()

set(matplotlibcpp17_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

function(add_demo name path)
  add_executable(${name} ${path})
  target_include_directories(${name} PUBLIC ${pybind11_INCLUDE_DIR} ${Python3_INCLUDE_DIRS} ${matplotlibcpp17_INCLUDE_DIRS})
  target_link_libraries(${name} ${Python3_LIBRARIES} pybind11::embed)
endfunction()

if(${ADD_DEMO})
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_FLAGS "-Wall -g -DUSE_GUI=${USE_GUI}")
  add_subdirectory(gallery/lines_bars_and_markers)
  add_subdirectory(gallery/subplots_axes_and_figures)
  add_subdirectory(gallery/statistics)
  add_subdirectory(gallery/images_contours_and_fields)
  add_subdirectory(gallery/shapes_and_collections)
  add_subdirectory(gallery/artist_animation)
  add_subdirectory(gallery/mplot3d)
endif()

if(NOT DEFINED DO_TEST)
  set(DO_TEST ON)
endif()

if(${DO_TEST})
  add_subdirectory(tests)
endif()
