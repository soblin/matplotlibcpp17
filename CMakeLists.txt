cmake_minimum_required(VERSION 3.12)

project(
  "matplotlibcpp17"
  VERSION 1.0.0
  DESCRIPTION
    "A C++ header-only plotting library based on pybind11 and matplotlib, featuring more flexibility than matplotlibcpp"
  HOMEPAGE_URL "https://soblin.github.io/matplotlibcpp17/")

find_package(
  Python3
  COMPONENTS Interpreter Development
  REQUIRED)
find_package(pybind11 2.4.3 REQUIRED)

# check matplotlib minor version
execute_process(
  COMMAND ${Python3_EXECUTABLE} "-c" "import matplotlib;
print(str(matplotlib.__version__), end='')"
  RESULT_VARIABLE MATPLOTLIB_VERSION_CHECKING
  OUTPUT_VARIABLE MATPLOTLIB_VERSION)

if(NOT MATPLOTLIB_VERSION_CHECKING MATCHES 0)
  message(FATAL_ERROR "Could not check matplotlib.__version__")
endif()
message(STATUS "Detected matplotlib version is ${MATPLOTLIB_VERSION}")
if(${MATPLOTLIB_VERSION} VERSION_LESS 3.4)
  message(WARNING "Detected matplotlib version is < 3.4.0")
  set(MATPLOTLIB_MINOR_VER_GTE_4 0)
else()
  message(STATUS "Detected matplotlib version is >= 3.4.0")
  set(MATPLOTLIB_MINOR_VER_GTE_4 1)
endif()

# gallery
if(NOT DEFINED USE_GUI)
  set(USE_GUI 0)
  message(STATUS "set USE_GUI = OFF")
endif()
if(NOT DEFINED ADD_DEMO)
  set(ADD_DEMO 0)
  message(STATUS "set ADD_DEMO = OFF")
endif()
if(USE_GUI)
  message(STATUS "USE_GUI = ON")
else()
  message(STATUS "USE_GUI = OFF")
endif()
if(ADD_DEMO)
  message(STATUS "ADD_DEMO = ON")
else()
  message(STATUS "ADD_DEMO = OFF")
endif()

function(add_demo name path)
  add_executable(${name} ${path})
  target_include_directories(${name} PUBLIC ${Python3_INCLUDE_DIRS}
                                            ${matplotlibcpp17_INCLUDE_DIRS})
  target_link_libraries(${name} ${Python3_LIBRARIES} pybind11::embed xtensor)
endfunction()

if(${ADD_DEMO})
  find_package(
    Python3
    COMPONENTS NumPy
    REQUIRED)
  find_package(xtensor 0.24.0 REQUIRED)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_FLAGS
      "-Wall -g -DUSE_GUI=${USE_GUI} -DMATPLOTLIB_MINOR_VER_GTE_4=${MATPLOTLIB_MINOR_VER_GTE_4}"
  )
  add_subdirectory(gallery/tests)
  add_subdirectory(gallery/lines_bars_and_markers)
  add_subdirectory(gallery/subplots_axes_and_figures)
  add_subdirectory(gallery/statistics)
  add_subdirectory(gallery/images_contours_and_fields)
  add_subdirectory(gallery/shapes_and_collections)
  add_subdirectory(gallery/artist_animation)
  add_subdirectory(gallery/mplot3d)
  add_subdirectory(gallery/scales)
endif()

# for add_subdirectory
add_library(matplotlibcpp17::matplotlibcpp17 INTERFACE IMPORTED GLOBAL)
set_property(TARGET matplotlibcpp17::matplotlibcpp17 PROPERTY INTERFACE_INCLUDE_DIRECTORIES ${CMAKE_CURRENT_SOURCE_DIR}/include ${Python3_INCLUDE_DIRS})
set_property(TARGET matplotlibcpp17::matplotlibcpp17 PROPERTY INTERFACE_LINK_LIBRARIES ${Python3_LIBRARIES} pybind11::embed)

# install https://dominikberner.ch/cmake-interface-lib/
include(GNUInstallDirs)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(
  ${PROJECT_NAME}
  INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
            $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>)
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
install(
  TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR})
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
  "${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion)
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})
# to /share/cmake/matplotlibcpp17
install(FILES "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
              "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})
# to /share/cmake/matplotlibcpp17
install(
  EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME})
# to /include/matplotlibcpp17
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
        DESTINATION include)
set(CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE")
# create .deb
include("${PROJECT_SOURCE_DIR}/cmake/package.cmake")

# https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#can-i-do-make-uninstall-with-cmake
if(NOT TARGET uninstall)
  configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
                 "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake" IMMEDIATE @ONLY)
  add_custom_target(
    uninstall COMMAND ${CMAKE_COMMAND} -P
                      ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake)
endif()
