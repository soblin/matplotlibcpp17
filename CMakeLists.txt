cmake_minimum_required(VERSION 3.0)

find_package(PythonLibs 3 REQUIRED)
find_package(PythonInterp 3 REQUIRED)
find_package(pybind11 REQUIRED)

if(NOT DEFINED ADD_DEMO)
  set(ADD_DEMO ON)
endif()

function(add_demo name path)
  add_executable(${name} ${path})
  target_include_directories(${name} PUBLIC ${pybind11_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} include/)
  target_link_libraries(${name} ${PYTHON_LIBRARY} pybind11::embed)
endfunction()

if(${ADD_DEMO})
  set(CMAKE_CXX_STANDARD 17)
  add_demo(simple_plot gallery/lines_bars_and_markers/simple_plot.cpp)
endif()

if(NOT DEFINED DO_TEST)
  set(DO_TEST ON)
endif()

if(${DO_TEST})
  add_subdirectory(tests)
endif()
