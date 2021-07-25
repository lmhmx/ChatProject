#include "ChatServer.h"

ChatServer::ChatServer(QWidget *parent)
    : QMainWindow(parent)
{

    m_timer = new QTimer(this);
    
    ui.setupUi(this);
    m_ChatCoreTask = new ChatCoreTask();
    m_timer->start(2000);
    connect(m_timer, &QTimer::timeout, [=] {
        map<string, string> info = m_ChatCoreTask->m_Info;
        string s;
        for (auto iter = info.begin(); iter != info.end(); iter++) {
            s.append(iter->first);
            s.append(" : ");
            s.append(iter->second);
            s.append("\n");
        }
        
        //(QString::fromStdString(s));
        });
}
