#include <QApplication>
#include <QSurfaceFormat>
#include <QHBoxLayout>

#include "cubewindow.h"

int main(int argc, char **argv) {
    QApplication app(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);
    format.setVersion(2, 1);

    CubeWindow window;
    window.setFormat(format);
    window.resize(640, 480);
    window.show();

    window.setAnimated(true);

    return app.exec();
}