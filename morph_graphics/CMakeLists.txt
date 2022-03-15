cmake_minimum_required(VERSION 3.20)
project(morph_graphics)

set(CMAKE_PREFIX_PATH /usr/local/opt/qt@5/lib/cmake/Qt5)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(OpenGL REQUIRED)
find_package(Qt5 COMPONENTS
        Core
        Gui
        Widgets
        REQUIRED)

add_executable(morph_graphics main.cpp cubewindow.cpp cubewindow.h GLWindow.cpp GLWindow.h)
target_link_libraries(morph_graphics
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        OpenGL::GL)