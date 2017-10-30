
cmake_minimum_required( VERSION 3.8 FATAL_ERROR )

project( circle-gl-glut )

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

find_package(OPENGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(GLEW REQUIRED)

find_library(COCOA Cocoa)

include_directories(
    include
    ${GLUT_INCLUDE_DIR}
    ${GLEW_INCLUDE_DIR}
)

add_executable(
    circle-gl-glut
    src/main.cpp
    include/display/Display.cpp
)

target_link_libraries(
    circle-gl-glut
    ${COCOA_LIBRARIES}
    ${OPENGL_LIBRARIES}
    ${GLUT_LIBRARIES}
    ${GLEW_LIBRARIES}
)