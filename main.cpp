#include <QApplication>
#include "MapViewer.h"
#include "QGoogleMaps.h"

#include <QObject>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QGoogleMaps::instance().setApiKey("AIzaSyBCdNVOM-Zie0oZjy4Dg-4ImIXFAHvfNx0");
    MapViewer* viewer = QGoogleMaps::instance().mapViewer();
    viewer->showMaximized();

    return app.exec();
}
