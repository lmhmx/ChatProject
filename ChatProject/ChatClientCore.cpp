#include "ChatClientCore.h"
ChatClientCore::ChatClientCore(QObject* parent) {
	m_NetManagerClient = new NetManagerClient();
	m_OnlineCertificate = "";
}

void ChatClientCore::sendMessage(Message m) {
	string s = m.to_String();
	m_NetManagerClient->slotSendMessage(s);

}
void ChatClientCore::slotNewMessage(string message) {
    Message m = Message::to_Message(message);
    switch (m.m_MessageType) {
    case MessageType::MessageType::REGISTER:
        actionToRegisterMessage(m);
        break;
    case MessageType::MessageType::LOGIN:
        actionToLogInMessage(m);
        break;
    case MessageType::MessageType::MESSAGE:
        actionToMessageMessage(m);
        break;
    default:
        qDebug() << MessageType::to_String(m.m_MessageType).c_str();
        break;
    }
}
void ChatClientCore::actionToLogInMessage(Message m) {
    if (m.m_MessageContent.m_MessageContentType ==
        MessageContentType::MessageContentType::LOGIN_reply) {
        if (m.m_MessageContent.m_Content["LOGIN_RESULT"] == "SUCCEED") {
            string uid = m.m_MessageContent.m_Content["LOG_IN_USER_ID"];
            string certificate = m.m_MessageContent.m_Content["CERTIFICATE"];
            emit signal_LogInSucceed(true);
        }
        else {
            emit signal_LogInSucceed(false);
        }
    }
}
void ChatClientCore::actionToRegisterMessage(Message m) {
    if (m.m_MessageContent.m_MessageContentType ==
        MessageContentType::MessageContentType::REGISTER_reply) {
        if (m.m_MessageContent.m_Content["REGISTER_RESULT"] == "SUCCEED") {
            string uid = m.m_MessageContent.m_Content["REGISTER_UID"];
            string certificate = m.m_MessageContent.m_Content["CERTIFICATE"];
            qDebug() << "register succeed";
            emit signal_RegisterSucceed(true);
        }
        else {
            emit signal_RegisterSucceed(false);
        }
    }
}
void ChatClientCore::actionToMessageMessage(Message m) {
    emit signal_NewMessage(m);
}