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
    // 界面相关的程序
    void setPageLogInRegisterWindow();

    void setPageMainWindow();



    // 信号相关的操作
signals:
    void signal_LogInSucceed(string uid,string certificate);
    void signal_RegisterSucceed(string uid, string certificate);
    

protected:
    void slotLogInSucceed(string uid, string certificate);
    void slotRegisterSucceed(string uid, string certificate);

protected:
    // 接收LogInRegisterUiController的信号
    void slotLogInByMail(string mail, string pwd);
    void slotRegisterByMail(string mail, string pwd);
    
protected:
    // 接收到一条信息
    void slotNewMessage(string message);

    void replyToLogInMessage(Message m);
    void replyToRegisterMessage(Message m);

protected:
    // 
    

private:
    LogInRegisterUiController* m_LogInRegisterUiController;
    MainUiController* m_MainUiController;

private:
    NetManagerClient* m_NetManagerClient;

private:
    
    Ui::ChatClientAppClass ui;
private:
    User m_User;
    string m_OnlineCertificate;
};
