cmake_minimum_required(VERSION 3.20)
project(road)

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

add_executable(Task8 main.cpp cubesettingswindow.h cubesettingswindow.cpp cubesettingswindow.ui
        Edge.cpp Edge.hpp InputController.cpp InputController.hpp
        openglwindow.h openglwindow.cpp Params.h RoadWindow.h RoadWindow.cpp)
target_link_libraries(Task8
        Qt5::Core
        Qt5::Gui
        Qt5::Widgets
        OpenGL::GL)