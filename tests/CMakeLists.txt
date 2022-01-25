set(CMAKE_CXX_STANDARD 17)
# create library
add_library(test_lib SHARED
  test_lib.cpp
)
target_compile_options(test_lib PUBLIC "-fPIC")
target_include_directories(test_lib PUBLIC ${pybind11_INCLUDE_DIR} ${PYTHON_INCLUDE_DIRS} ../include/)
target_link_libraries(test_lib ${PYTHON_LIBRARY} pybind11::embed)
# link it
add_executable(test_lib_main test_lib_main.cpp)
target_link_libraries(test_lib_main ${PYTHON_LIBRARY} pybind11::embed test_lib)
