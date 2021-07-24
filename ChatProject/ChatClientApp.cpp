#include "ChatClientApp.h"
ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_NetManagerClient = new NetManagerClient();
    ui.setupUi(this);
    setPageLogInRegisterWindow();
    
}
void ChatClientApp::slotLogInByMail(string mail, string pwd) {
    Message m;
    m.m_MessageType = MessageType::MessageType::LOGIN;
    m.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::LOGIN_request;
    m.m_MessageContent.m_Content.insert(pair<string, string>("MAIL", mail));
    m.m_MessageContent.m_Content.insert(pair<string, string>("PASSWORD", pwd));
    m.m_MessageContent.m_Content.insert(pair<string, string>("LOGIN_WAY", "MAIL"));

    m.m_MessageReceiver = "";

    sendMessage(m);

}
void ChatClientApp::slotNewMessage(string message) {
    Message m = Message::to_Message(message);
    switch (m.m_MessageType) {
    case MessageType::MessageType::REGISTER:
        if (m.m_MessageContent.m_MessageContentType ==
            MessageContentType::MessageContentType::REGISTER_reply) {
            
            // TODO: 拆成一个函数，进行补充
            if (m.m_MessageContent.m_Content["REGISTER_RESULT"] == "SUCCEED") {
                QMessageBox::information(0, "info", "register succeed");
            }
            else {
                QMessageBox::information(0, "info", "register failed");
            }


        }
        break;
    case MessageType::MessageType::LOGIN:
        if (m.m_MessageContent.m_MessageContentType ==
            MessageContentType::MessageContentType::LOGIN_reply) {

            // TODO: 拆成一个函数，进行补充 login
            if (m.m_MessageContent.m_Content["LOGIN_RESULT"] == "SUCCEED") {
                QMessageBox::information(0, "info", "login succeed");
            }
            else {
                QMessageBox::information(0, "info", "login failed");
            }
        }
        break;
    default:
        break;
    }
    
}

void ChatClientApp::slotRegisterByMail(string mail, string pwd) {
    qDebug() << "ChatClientApp slot Register By Mail start";
    Message m;
    m.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_request;
    m.m_MessageContent.m_Content.insert({ "MAIL",mail });
    m.m_MessageContent.m_Content.insert({"PASSWORD", pwd});
    m.m_MessageContent.m_Content.insert({"REGISTER_WAY", "MAIL"});
    
    m.m_MessageReceiver = "";

    m.m_MessageType = MessageType::MessageType::REGISTER;

    sendMessage(m);
    qDebug() << "ChatClientApp slot Register By Mail end";
}
void ChatClientApp::sendMessage(Message& m) {
    qDebug() << "ChatClientApp send Message begin";
    string s = m.to_String();
    qDebug() << "change end";
    m_NetManagerClient->slotSendMessage(s);

    qDebug() << QString::fromStdString(s);

}
void ChatClientApp::setPageLogInRegisterWindow() {
    
    m_LogInRegisterUiController = new LogInRegisterUiController();
    this->setCentralWidget(m_LogInRegisterUiController);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_LogInByMail,
        this, &ChatClientApp::slotLogInByMail);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_RegisterByMail,
        this, &ChatClientApp::slotRegisterByMail);
    

}

void ChatClientApp::setPageMainWindow() {
    m_MainUiController = new MainUiController();
    this->setCentralWidget(m_MainUiController);

}