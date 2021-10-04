#include "MessageManagerClient.h"
MessageManagerClient::MessageManagerClient(QObject* parent) {
	m_NetManagerClient = new NetManagerClient();
    connect(m_NetManagerClient, &NetManagerClient::signalReceiveMessage,
        this, &MessageManagerClient::slotNewMessage);
}

void MessageManagerClient::sendMessage(Message m) {
	string s = m.to_String();
	m_NetManagerClient->slotSendMessage(s);

}
void MessageManagerClient::slotNewMessage(string message) {

    Message m = Message::to_Message(message);
    emit signal_NewMessage(m);
}
