#include "ChatServer.h"

ChatServer::ChatServer(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    m_ChatCoreTask = new ChatCoreTask();
}
