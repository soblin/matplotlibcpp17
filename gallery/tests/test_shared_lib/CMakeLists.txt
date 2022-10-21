# create library
add_library(test_shared_lib SHARED test_lib.cpp)
target_compile_options(test_shared_lib PUBLIC "-fPIC")
target_link_libraries(test_shared_lib matplotlibcpp17::matplotlibcpp17)
# link it
add_executable(test_lib_main test_lib_main.cpp)
target_link_libraries(test_lib_main test_shared_lib)
