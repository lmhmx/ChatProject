#include "ChatClientApp.h"

ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_LogInUiController = new LogInUiController();
    this->setCentralWidget(m_LogInUiController);
}
