// checksum 0xd721 version 0x8000b
/*
  This file was generated by the Html5 Application wizard of Qt Creator.
  Html5ApplicationViewer is a convenience class containing mobile device specific
  code such as screen orientation handling.
  It is recommended not to modify this file, since newer versions of Qt Creator
  may offer an updated version of it.
*/

#ifndef MAPVIEWER_H
#define MAPVIEWER_H

#include <QWidget>
#include <QUrl>

class QGraphicsWebView;

class MapViewer : public QWidget
{
    Q_OBJECT

public:
    enum ScreenOrientation {
        ScreenOrientationLockPortrait,
        ScreenOrientationLockLandscape,
        ScreenOrientationAuto
    };

    explicit MapViewer(QWidget *parent = 0);
    virtual ~MapViewer();

    void loadFile(const QString &fileName);
    void loadUrl(const QUrl &url);

    // Note that this will only have an effect on Fremantle.
    void setOrientation(ScreenOrientation orientation);

    void showExpanded();

    QGraphicsWebView *webView() const;

private:
    class Html5ApplicationViewerPrivate *m_d;
};

#endif // MAPVIEWER_H
