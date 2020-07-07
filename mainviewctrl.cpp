#include "mainviewctrl.h"

#include <QQmlApplicationEngine>
#include <QQmlContext>

MainViewCtrl::MainViewCtrl() : QObject(), m_NumValue(0)
{
    m_pMainView = new MainView();

    // setContextProperty() 함수를 사용하여 qml과 Q_PROPERTY 매크로가 구현된 클래스를 연결한다.
    // 첫 번째 매개변수가 두 번째 매개변수를 가리키는 qml에서 사용할 값이고
    // 두 번째 매개변수가 Q_PROPERTY 매크로가 구현된 클래스 주소값에 해당한다.
    m_pMainView->engine()->rootContext()->setContextProperty("KMJ", this);
    m_pMainView->setSource(QUrl(QStringLiteral("qrc:/main.qml")));
}

MainView* MainViewCtrl::getViewPtr()
{
    return m_pMainView;
}

int MainViewCtrl::getnum() const    // qml에서 "text : KMJ.num" 할 경우 getnum()가 호출된다.
{
    qDebug() << "[1] called getnum()";
    return m_NumValue;  // return 한 값이 text 값에 세팅될 것이다.
}

void MainViewCtrl::setnum(const int &gn)    // qml에서 "KMJ.num = 5 + 1" 할 경우 setnum(const int &gn)가 호출된다.
{
    qDebug() << "[2] called setnum()";
    m_NumValue = gn;    // 최종적으로 계산된 6 값을 첫 번째 매개변수 gn이 받아서 m_NumValue 변수에 저장된다.

    emit numchanged();  // 해주지 않으면 qml에 KMJ.num 값을 받고 있는 property 들이 새로운 값으로 세팅되지 않고 계속 기존 값을 가지고 있게 된다.
}
