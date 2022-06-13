#include <QApplication>
#include "RoadWindow.h"
#include "cubesettingswindow.h"
#include "Params.h"

int main(int argc, char **argv)
{

    QApplication qapp(argc, argv);

    QSurfaceFormat format;
    format.setSamples(16);


    Params p{Edge{{0, 0, 0}, 1, 100}, QVector3D{0.5, 0.5, -1}};

    RoadWindow window{p};
    window.setFormat(format);
    window.resize(800, 640);
    window.setPosition(0, 0);
    window.show();

    window.setAnimating(true);

    CubeSettingsWindow settings(p);
    settings.move(window.x() + window.width(), window.y());
    settings.show();


    return qapp.exec();
}
//! [2]
