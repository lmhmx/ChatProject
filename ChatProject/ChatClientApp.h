#pragma once
#include <QtWidgets/QMainWindow>
# include "ui_ChatApp.h"
# include <list>
# include "LogInRegisterUiController.h"
# include "NetManagerClient.h"
# include "Share.h"
# include "MainUiController.h"
class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);

    void sendMessage(Message& m);

public:
    void setPageLogInRegisterWindow();

    void setPageMainWindow();

protected:
    // 接收LogInRegisterUiController的信号
    void slotLogInByMail(string mail, string pwd);
    void slotRegisterByMail(string mail, string pwd);
    
protected:
    // 接收到一条信息
    void slotNewMessage(string message);



private:
    LogInRegisterUiController* m_LogInRegisterUiController;
    MainUiController* m_MainUiController;

private:
    NetManagerClient* m_NetManagerClient;

private:
    
    Ui::ChatClientAppClass ui;
};
