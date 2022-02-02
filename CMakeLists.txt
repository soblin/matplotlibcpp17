project(matplotlibcpp17)
cmake_minimum_required(VERSION 3.0)

find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)
find_package(pybind11 REQUIRED)

if(NOT DEFINED ADD_DEMO)
  set(ADD_DEMO ON)
endif()

if(NOT DEFINED USE_GUI)
  set(USE_GUI OFF)
endif()

set(matplotlibcpp17_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

function(add_demo name path)
  add_executable(${name} ${path})
  target_include_directories(${name} PUBLIC ${pybind11_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} ${matplotlibcpp17_INCLUDE_DIRS})
  target_link_libraries(${name} ${PYTHON_LIBRARY} pybind11::embed)
endfunction()

if(${ADD_DEMO})
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_FLAGS "-Wall -g -DUSE_GUI=${USE_GUI}")
  add_subdirectory(gallery/lines_bars_and_markers)
  add_subdirectory(gallery/subplots_axes_and_figures)
  add_subdirectory(gallery/statistics)
  add_subdirectory(gallery/images_contours_and_fields)
endif()

if(NOT DEFINED DO_TEST)
  set(DO_TEST ON)
endif()

if(${DO_TEST})
  add_subdirectory(tests)
endif()
