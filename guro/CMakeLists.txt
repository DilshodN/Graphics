cmake_minimum_required(VERSION 3.20)
project(guro)

set(CMAKE_PREFIX_PATH /usr/local/opt/qt@5/lib/cmake/Qt5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenGL REQUIRED)

find_package(Qt5 COMPONENTS Core Gui Widgets REQUIRED)

add_executable(guro SquareWindow.cpp SquareWindow.hpp GLWindow.cpp GLWindow.hpp MyWidget.cpp MyWidget.hpp main.cpp)
target_link_libraries(guro PRIVATE Qt5::Core Qt5::Widgets OpenGL::GL)