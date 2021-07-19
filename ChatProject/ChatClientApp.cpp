#include "ChatClientApp.h"

ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_LogInRegisterUiController = new LogInRegisterUiController();
    this->setCentralWidget(m_LogInRegisterUiController);
}
