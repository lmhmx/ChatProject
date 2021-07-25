#pragma once
#include <QtWidgets/QMainWindow>
# include <qtimer.h>
#include "ui_ChatServer.h"
# include "UserManager.h"
# include "ChatCoreTask.h"
class ChatServer : public QMainWindow
{
    Q_OBJECT


public:
    ChatServer(QWidget *parent = Q_NULLPTR);

    

private:
    
private:
    ChatCoreTask* m_ChatCoreTask;


private:
    QTimer* m_timer;

private:
    Ui::ChatServerClass ui;
};
