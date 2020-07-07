#ifndef MAINVIEWCTRL_H
#define MAINVIEWCTRL_H

#include <QObject>
#include "mainview.h"

class MainViewCtrl : public QObject // Q_PROPERTY 매크로를 정의하기 위해서 QObject 클래스를 상속받아야 한다.
{
    Q_OBJECT
    Q_PROPERTY(int num READ getnum WRITE setnum NOTIFY numchanged)
    // READ 뒤에는 qml에서 변수값을 얻으려고 할 때 cpp에 구현된 함수명
    // WRITE 뒤에는 qml에서 새로운 값으로 세팅할 때 cpp에 구현된 함수명
    // NOTIFY 뒤에는 cpp내에서 해당되는 함수를 호출하게 된다.

public:
    MainViewCtrl();
    MainView* getViewPtr();

    int getnum() const;
    void setnum(const int &);

private:
    MainView *m_pMainView;

    int m_NumValue;

signals:
    void numchanged();
};

#endif // MAINVIEWCTRL_H
