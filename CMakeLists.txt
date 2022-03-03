cmake_minimum_required(VERSION 3.12)

project(
  "matplotlibcpp17"
  VERSION 0.0.0
  DESCRIPTION "A C++ header-only plotting library based on pybind11 and matplotlib, featuring more flexibility than matplotlibcpp"
  HOMEPAGE_URL "https://soblin.github.io/matplotlibcpp17/"
  )

find_package(Python3 COMPONENTS Interpreter Development REQUIRED)
find_package(pybind11 2.4.3 REQUIRED)

set(matplotlibcpp17_INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/include")

# gallery
if(NOT DEFINED USE_GUI)
  set(USE_GUI 1)
endif()
if(NOT DEFINED ADD_DEMO)
  set(ADD_DEMO 1)
endif()

function(add_demo name path)
  add_executable(${name} ${path})
  target_include_directories(${name} PUBLIC
    ${Python3_INCLUDE_DIRS}
    ${matplotlibcpp17_INCLUDE_DIRS}
  )
  target_link_libraries(${name} ${Python3_LIBRARIES} pybind11::embed xtensor)
endfunction()

if(${ADD_DEMO})
  find_package(Python3 COMPONENTS NumPy REQUIRED)
  find_package(xtensor REQUIRED)
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


# test
enable_testing()
if(NOT DEFINED DO_TEST)
  set(DO_TEST ON)
endif()
if(${DO_TEST})
  add_subdirectory(tests)
endif()


# install
## https://dominikberner.ch/cmake-interface-lib/
include(GNUInstallDirs)
add_library(${PROJECT_NAME} INTERFACE)
target_include_directories(${PROJECT_NAME}
  INTERFACE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
  )
target_compile_features(${PROJECT_NAME} INTERFACE cxx_std_17)
install(TARGETS ${PROJECT_NAME}
  EXPORT ${PROJECT_NAME}_Targets
  ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
  LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
  )
include(CMakePackageConfigHelpers)
write_basic_package_version_file("${PROJECT_NAME}ConfigVersion.cmake"
  VERSION ${PROJECT_VERSION}
  COMPATIBILITY SameMajorVersion
  )
configure_package_config_file(
  "${PROJECT_SOURCE_DIR}/cmake/${PROJECT_NAME}Config.cmake.in"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  INSTALL_DESTINATION
  ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
  )
install(EXPORT ${PROJECT_NAME}_Targets
  FILE ${PROJECT_NAME}Targets.cmake
  NAMESPACE ${PROJECT_NAME}::
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
  )
install(FILES
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
  "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
  DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/cmake/${PROJECT_NAME}
  )
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/${PROJECT_NAME}
  DESTINATION include
  )

# uninstall target
## actually it's just `xargs rm < install_manifest.txt`
## https://gitlab.kitware.com/cmake/community/-/wikis/FAQ#can-i-do-make-uninstall-with-cmake
if(NOT TARGET uninstall)
  configure_file(
    "${CMAKE_CURRENT_SOURCE_DIR}/cmake/uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake"
    IMMEDIATE @ONLY
    )
  add_custom_target(uninstall
    COMMAND ${CMAKE_COMMAND} -P ${CMAKE_CURRENT_BINARY_DIR}/uninstall.cmake
    )
endif()
