# create library
add_library(test_static_lib STATIC
  test_lib.cpp
)
target_compile_options(test_static_lib PUBLIC "-fPIC")
target_include_directories(test_static_lib PUBLIC ${pybind11_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} ${matplotlibcpp17_INCLUDE_DIRS})
target_link_libraries(test_static_lib ${PYTHON_LIBRARY} pybind11::embed)
# link it
add_executable(test_lib_static_main test_lib_main.cpp)
target_link_libraries(test_lib_static_main ${PYTHON_LIBRARY} pybind11::embed test_static_lib)
