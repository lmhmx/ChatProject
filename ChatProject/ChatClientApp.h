#pragma once
#include <QtWidgets/QMainWindow>
# include "ui_ChatApp.h"
# include <list>
# include "LogInRegisterUiController.h"
# include "NetManagerClient.h"
# include "Share.h"
# include "MainUiController.h"
# include "ChatClientCore.h"
class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);

    
public:
    // 切换界面相关的程序
    void setPageLogInRegisterWindow();

    void setPageMainWindow();




protected:
    // 接收下级的成功信号
    void slotLogInSucceed(bool succeed);
    void slotRegisterSucceed(bool succeed);

protected:
    // 接收LogInRegisterUiController的信号
    void slotLogInByMail(string mail, string pwd);
    void slotRegisterByMail(string mail, string pwd);
protected:
    // 接收主界面的信号
    void slotSendMessageFromMainUi(Message message);

protected:
    // 从下级接收的总接口
    void slotNewMessage(Message message);
    // 向下级发送的总接口
    void sendMessage(Message message);

protected:
    // 
    

private:
    LogInRegisterUiController* m_LogInRegisterUiController;
    MainUiController* m_MainUiController;


private:

    ChatClientCore* m_ChatClientCore;
    Ui::ChatClientAppClass ui;

};
