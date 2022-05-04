cmake_minimum_required(VERSION 3.20)
project(mesh)

set(CMAKE_PREFIX_PATH /usr/local/opt/qt@5/lib/cmake/Qt5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

add_definitions(-DGL_SILENCE_DEPRECATION)

find_package(OpenGL REQUIRED)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

find_package(glm REQUIRED)

add_executable(mesh main.cpp obj_loader.h obj_loader.cpp widget.cpp widget.h)
target_link_libraries(mesh PRIVATE Qt5::Core Qt5::Widgets OpenGL::GL glm::glm)