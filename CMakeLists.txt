cmake_minimum_required(VERSION 3.28)
project(geometry_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(geometry_tool STATIC
    src/geo_2D/circle_2D.cpp
    src/geo_2D/edge_2D.cpp
    src/geo_2D/point_2D.cpp
    src/geo_2D/triangle_2D.cpp
    src/geo_2D/vector_2D.cpp)

target_include_directories(geometry_tool
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>)

include(GNUInstallDirs)
install(
    DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(TARGETS geometry_tool EXPORT geometryTargets)
install(EXPORT geometryTargets
    FILE geometryConfig.cmake
    NAMESPACE geometry::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/geometry)