#ifndef QGOOGLEMAPS_H
#define QGOOGLEMAPS_H

#include <QObject>

class QWidget;
class MapViewer;
struct QGoogleMapsData;
class QGoogleMaps : public QObject
{
    Q_OBJECT

public:
    static QGoogleMaps& instance();
    ~QGoogleMaps();

    MapViewer* mapViewer();

    Q_INVOKABLE void setApiKey(const QString& apiKey);
    Q_INVOKABLE QString apiKey() const;
    
private:
    QGoogleMaps(QObject *parent = 0);
    QGoogleMapsData* d;
};

#endif // QGOOGLEMAPS_H
