cmake_minimum_required(VERSION 3.12)

# example of CMakeLists.txt with installed matplotlibcpp17
project(matplotlibcpp17_hello_world)

find_package(Python3 COMPONENTS Interpreter Development)
find_package(pybind11 REQUIRED)
find_package(matplotlibcpp17 REQUIRED)

add_executable(hello_world hello_world.cpp)
target_include_directories(hello_world PUBLIC ${Python3_INCLUDE_DIRS})
target_link_libraries(hello_world ${Python3_LIBRARIES} pybind11::embed matplotlibcpp17::matplotlibcpp17)
