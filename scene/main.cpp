#include "MyWidget.hpp"
#include "SquareWindow.hpp"
#include <QApplication>
#include <QSurfaceFormat>

template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value>>
using main = T;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(2, 1);

    const auto* my_window = main<SquareWindow*>(new SquareWindow);

//    auto window = new MyWidget();
//    window->createToolBar();
//    window->setMaximumSize(1280, 1024);
//    window->showMaximized();

    return app.exec();
}