#pragma once
#include <qwidget.h>
# include "ui_Widget_Main.h"

# include <string>
# include <qlistwidget.h>
# include <qmessagebox.h>
# include <qpixmap.h>
# include <map>
# include <boost/bimap.hpp>
# include "Widget_ChatList_Controller.h"
# include "Widget_MessageSend_Controller.h"
# include "Widget_MessageShow_Controller.h"
# include "Widget_SearchUiController.h"
# include "Share.h"

using namespace std;
class MainUiController:
    public QWidget
{
    Q_OBJECT

public:
    MainUiController(QWidget* parent = Q_NULLPTR);


public:
    void newMessage(map<string,string> m);

signals:
    // ����MainUi�����߼�����Ϣ������map�е�Ԫ�ؽ����������
    void signal_SendMessage(map<string,string> m);


public:

private:

    // ��������ʾ������ʾ��Ϣ
    void setCurrentChat(string id);

    

protected:
    // �����б���ź�
    void slot_SelectChanged();
    // ���յ��+�ŵ��ź�
    void slot_SearchClicked();
    // ���շ���enter���ź�
    void slot_SendMessage(string message_text);

private:
    

private:
    // ������ÿһ��id��Ӧ����Ϣ
    map<string, vector<Message>> m_Messages;

private:
    Widget_ChatList_Controller* m_ChatList_Controller;
    Widget_MessageSend_Controller* m_MessageSend_Controller;
    Widget_MessageShow_Controller* m_MessageShow_Controller;
    
private:
    Ui::Widget_Main ui_main;
    
private:
    User m_currentUser;

};

