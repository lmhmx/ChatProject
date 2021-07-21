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

    m.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_request;
    m.m_MessageContent.m_Content.insert(pair<string, string>("MAIL", mail));
    m.m_MessageContent.m_Content.insert(pair<string, string>("PASSWORD", pwd));
    m.m_MessageContent.m_Content.insert(pair<string, string>("LOGINWAY", "MAIL"));

    m.m_MessageReceiver = "SuperUserLogIn";

    m.m_MessageType = MessageType::MessageType::REGISTER;

    sendMessage(m);

}
void ChatClientApp::slotNewMessage(string message) {
    Message m = Message::to_Message(message);
    switch (m.m_MessageType) {
    case MessageType::MessageType::REGISTER:
        if (m.m_MessageContent.m_MessageContentType ==
            MessageContentType::MessageContentType::REGISTER_reply) {
            

        }
        break;
    case MessageType::MessageType::LOGIN:
        if (m.m_MessageContent.m_MessageContentType ==
            MessageContentType::MessageContentType::LOGIN_reply) {


        }
        break;
    default:
        break;
    }
    
}

void ChatClientApp::slotRegisterByMail(string mail, string pwd) {
    Message m;
   
    m.m_MessageContent.m_MessageContentType = MessageContentType::MessageContentType::REGISTER_request;
    m.m_MessageContent.m_Content.insert(pair<string, string> ("MAIL",mail));
    m.m_MessageContent.m_Content.insert(pair<string, string>("PASSWORD", pwd));
    m.m_MessageContent.m_Content.insert(pair<string, string>("REGISTERWAY", "MAIL"));
    
    m.m_MessageReceiver = "SuperUserRegister";

    m.m_MessageType = MessageType::MessageType::REGISTER;

    sendMessage(m);
}
void ChatClientApp::sendMessage(Message& m) {

    string s = m.to_String();

    m_NetManagerClient->slotSendMessage(s);

    qDebug() << QString::fromStdString(s);

}
void ChatClientApp::setPageLogInRegisterWindow() {
    //for (auto i = centralWidget()->children().begin(); i <  centralWidget()->children().end(); i++) {
    //    delete (*i);
    //}

    //for (auto i = children().begin(); i < children().end(); i++) {
    //    qobject_cast<QWidget*>(*i)->show();
    //}
    //
    m_LogInRegisterUiController = new LogInRegisterUiController();
    this->setCentralWidget(m_LogInRegisterUiController);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_LogInByMail,
        this, &ChatClientApp::slotLogInByMail);
    connect(m_LogInRegisterUiController, &LogInRegisterUiController::signal_LogInByPhone,
        this, &ChatClientApp::slotRegisterByMail);
    

}

void ChatClientApp::setPageMainWindow() {
    m_MainUiController = new MainUiController();
    this->setCentralWidget(m_MainUiController);

}