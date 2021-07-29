#include "ChatClientApp.h"
ChatClientApp::ChatClientApp(QWidget *parent)
    : QMainWindow(parent)
{
    m_ChatClientCore = new ChatClientCore();
    
    connect(m_ChatClientCore, &ChatClientCore::signal_LogInSucceed,
        this, &ChatClientApp::slotRegisterSucceed);
    connect(m_ChatClientCore, &ChatClientCore::signal_LogInSucceed,
        this, &ChatClientApp::slotLogInSucceed);
    connect(m_ChatClientCore, &ChatClientCore::signal_NewMessage,
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
void ChatClientApp::slotLogInSucceed(bool succeed) {
    if (succeed) {
        setPageMainWindow();
    }
    else {
        QMessageBox::warning(0, "error", "log in failed");
    }
    
}
void ChatClientApp::slotRegisterSucceed(bool succeed) {
    if (succeed) {
        setPageMainWindow();
    }
    else {
        QMessageBox::warning(0, "error", "register failed");
    }

}
void ChatClientApp::slotSendMessageFromMainUi(Message message) {
    sendMessage(message);
}
void ChatClientApp::slotNewMessage(Message message) {
    if (message.m_MessageType == MessageType::MessageType::MESSAGE) {
        // TODO: »Ø¸´ÐÅÏ¢
        m_MainUiController->newMessage(message);
        //string uid = message.m_MessageSender;
        //if (m_Messages.find(uid) == m_Messages.end()) {
        //    m_Messages[uid] = vector<Message>();
        //    m_Messages[uid].push_back(message);
        //}
        //
        //m_MainUiController->setItem(uid, 1, QPixmap(), "name", "message", "time", true);
        
    }
    else {
        QMessageBox::critical(0, "error", "App error, please contact the managers");
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
void ChatClientApp::sendMessage(Message m) {
    m_ChatClientCore->sendMessage(m);

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
    connect(m_MainUiController, &MainUiController::signal_SendMessage,
        this, &ChatClientApp::slotSendMessageFromMainUi);
}