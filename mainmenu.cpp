#include "mainmenu.h"

MainMenu::MainMenu(int &argc, char *argv[]) : QGuiApplication(argc, argv)
{
    init();
    showqml();
}

void MainMenu::init()
{
    m_pMainViewCtrl = new MainViewCtrl();
}

void MainMenu::showqml()
{
    m_pMainViewCtrl->getViewPtr()->show();
}
