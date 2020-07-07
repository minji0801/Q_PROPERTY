#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QQuickView>

class MainView : public QQuickView  // qml과 연결하기 위해서 QQuickView 클래스를 상속받아야한다.
{
    Q_OBJECT

public:
    MainView();
};

#endif // MAINVIEW_H
