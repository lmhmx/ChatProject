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
    // �л�������صĳ���
    void setPageLogInRegisterWindow();

    void setPageMainWindow();




protected:
    // �����¼��ĳɹ��ź�
    void slotLogInSucceed(bool succeed);
    void slotRegisterSucceed(bool succeed);

protected:
    // ����LogInRegisterUiController���ź�
    void slotLogInByMail(string mail, string pwd);
    void slotRegisterByMail(string mail, string pwd);
protected:
    // ������������ź�
    void slotSendMessageFromMainUi(Message message);

protected:
    // ���¼����յ��ܽӿ�
    void slotNewMessage(Message message);
    // ���¼����͵��ܽӿ�
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
