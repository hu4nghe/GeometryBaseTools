cmake_minimum_required(VERSION 3.28)
project(geometry_tool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(geometry_tool INTERFACE)

target_include_directories(geometry_tool
    INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

include(GNUInstallDirs)
install(
    DIRECTORY include/geo
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(TARGETS geometry_tool EXPORT geometryTargets)
install(EXPORT geometryTargets
    FILE geometryConfig.cmake
    NAMESPACE geometry::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/geometry
)