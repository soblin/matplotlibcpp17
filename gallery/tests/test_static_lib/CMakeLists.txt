# create library
add_library(test_static_lib STATIC test_lib.cpp)
target_compile_options(test_static_lib PUBLIC "-fPIC")
target_link_libraries(test_static_lib matplotlibcpp17::matplotlibcpp17)
# link it
add_executable(test_lib_static_main test_lib_main.cpp)
target_link_libraries(test_lib_static_main test_static_lib)
