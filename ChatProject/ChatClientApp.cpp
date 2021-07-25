#include "ChatClientApp.h"
ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_NetManagerClient = new NetManagerClient();
    connect(this, &ChatClientApp::signal_RegisterSucceed,
        this, &ChatClientApp::slotRegisterSucceed);
    connect(this, &ChatClientApp::signal_LogInSucceed,
        this, &ChatClientApp::slotLogInSucceed);
    connect(m_NetManagerClient, &NetManagerClient::signalReceiveMessage,
        this, &ChatClientApp::slotNewMessage);
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
void ChatClientApp::slotLogInSucceed(string uid, string certificate) {
    m_User.m_UserID = uid;
    m_OnlineCertificate = certificate;
    setPageMainWindow();
}
void ChatClientApp::slotRegisterSucceed(string uid, string certificate) {
    m_User.m_UserID = uid;
    m_OnlineCertificate = certificate;
    setPageMainWindow();
}
void ChatClientApp::replyToLogInMessage(Message m) {
    if (m.m_MessageContent.m_MessageContentType ==
        MessageContentType::MessageContentType::LOGIN_reply) {
        if (m.m_MessageContent.m_Content["LOGIN_RESULT"] == "SUCCEED") {
            QMessageBox::information(0, "info", "login succeed");
            string uid = m.m_MessageContent.m_Content["LOG_IN_USER_ID"];
            string certificate = m.m_MessageContent.m_Content["CERTIFICATE"];
            emit signal_LogInSucceed(uid, certificate);
        }
        else {
            QMessageBox::information(0, "info", "login failed");
        }
    }
}
void ChatClientApp::replyToRegisterMessage(Message m) {
    if (m.m_MessageContent.m_MessageContentType ==
        MessageContentType::MessageContentType::REGISTER_reply) {
        if (m.m_MessageContent.m_Content["REGISTER_RESULT"] == "SUCCEED") {
            QMessageBox::information(0, "info", "register succeed");
            string uid = m.m_MessageContent.m_Content["REGISTER_UID"];
            string certificate = m.m_MessageContent.m_Content["CERTIFICATE"];
            qDebug() << "register succeed";
            emit signal_RegisterSucceed(uid, certificate);
        }
        else {
            QMessageBox::information(0, "info", "register failed");
        }


    }
}
void ChatClientApp::slotNewMessage(string message) {
    Message m = Message::to_Message(message);
    switch (m.m_MessageType) {
    case MessageType::MessageType::REGISTER:
        replyToRegisterMessage(m);
        break;
    case MessageType::MessageType::LOGIN:
        replyToLogInMessage(m);
        break;
    default:
        qDebug() << MessageType::to_String(m.m_MessageType).c_str();
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