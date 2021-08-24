#pragma once
#include <qwidget.h>
# include "ui_Widget_Main.h"
# include "ui_Widget_MessageShow.h"
# include "ui_Widget_MessageSend.h"
# include <string>
# include <qlistwidget.h>
# include <qmessagebox.h>
# include <qpixmap.h>
# include <map>
# include <boost/bimap.hpp>
# include "Widget_ChatList_Controller.h"
# include "Share.h"

using namespace std;
class MainUiController:
    public QWidget
{
    Q_OBJECT

public:
    MainUiController(QWidget* parent = Q_NULLPTR);


public:
    void newMessage(Message message);
public:

private:

    // ��������ʾ������ʾ��Ϣ
    void setCurrentChat(string id);

public:
    void slot_SendMessageClick();
    void slot_SendMessageEnterClick();
    void slot_EmojiClick();
    void slot_FileClick();
    
    void slot_AddClick();

    void slot_SelectChanged();
private:
    
signals:
    void signal_SendMessage(Message m);

private:
    // ������ÿһ��id��Ӧ����Ϣ
    map<string, vector<Message>> m_Messages;

private:
    Widget_ChatList_Controller* m_ChatList_Controller;


private:
    Ui::Widget_Main ui_main;
    Ui::Widget_Send ui_send;

    
    Ui::Widget_MessageShow ui_MessageShow;
    
};

