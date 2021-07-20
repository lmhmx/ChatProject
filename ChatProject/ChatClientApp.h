#pragma once

#include <QtWidgets/QMainWindow>
# include "ui_ChatApp.h"
# include "LogInRegisterUiController.h"
# include "NetManagerClient.h"
# include "Share.h"
class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);

    void sendMessage(Message& m);

protected:
    void slotLogInByMail(string mail, string pwd);
    void slotRegisterByMail(string mail, string pwd);
    

private:
    LogInRegisterUiController* m_LogInRegisterUiController;

private:
    NetManagerClient* m_NetManagerClient;

private:
    
    Ui::ChatClientAppClass ui;
};
