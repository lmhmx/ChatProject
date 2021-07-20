#include "ChatClientApp.h"
ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_LogInRegisterUiController = new LogInRegisterUiController();
    this->setCentralWidget(m_LogInRegisterUiController);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_LogInByMail, 
        this, &ChatClientApp::slotLogInByMail);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_LogInByPhone, 
        this, &ChatClientApp::slotRegisterByMail);
}
void ChatClientApp::slotLogInByMail(string mail, string pwd) {
    // Message m;
    
    // sendMessage(m);
}
void ChatClientApp::sendMessage(Message& m) {
    // string s = m.to_String();
    // m_NetManagerClient->slotSendMessage(s);
    // qDebug() << QString::fromStdString(s);
}
void ChatClientApp::slotRegisterByMail(string mail, string pwd) {
    Message m;

    // sendMessage(m);
}