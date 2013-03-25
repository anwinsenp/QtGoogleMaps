#include "QGoogleMaps.h"
#include "MapViewer.h"

#include <QWidget>

#include <QDebug>

struct QGoogleMapsData
{
    QString apiKey;
    MapViewer viewer;
};

QGoogleMaps& QGoogleMaps::instance()
{
    static QGoogleMaps theInstance;
    return theInstance;
}

QGoogleMaps::QGoogleMaps(QObject *parent) :
    QObject(parent)
{
    d = new QGoogleMapsData;
}

QGoogleMaps::~QGoogleMaps()
{
    delete d;
    d = 0;
}

MapViewer *QGoogleMaps::mapViewer()
{
    d->viewer.setOrientation(MapViewer::ScreenOrientationAuto);
    d->viewer.loadFile(QLatin1String("html/index.html"));
    return &d->viewer;
}
#include <QGraphicsWebView>
#include <QWebFrame>
void QGoogleMaps::setApiKey(const QString& apiKey)
{
    d->viewer.webView()->page()->mainFrame()->evaluateJavaScript("alert(map.getMapTypeId())");
    if(apiKey.isEmpty() || (d->apiKey == apiKey))
        return;

    d->apiKey = apiKey;
}

QString QGoogleMaps::apiKey() const
{
    return d->apiKey;
}


