#include "MyWidget.hpp"
#include "SquareWindow.hpp"
#include <QApplication>
#include <QSurfaceFormat>


template <typename T, typename = std::enable_if_t<std::is_pointer<T>::value>>
using App = T;

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(2, 1);

    auto window = new MyWidget();
    window->createToolBar();
    window->createAxes();

    return app.exec();
}