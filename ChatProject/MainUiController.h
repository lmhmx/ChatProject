#pragma once
#include <qwidget.h>
# include "ui_Widget_Main.h"
# include "ui_Widget_ChatList.h"
# include "ui_Widget_MessageShow.h"
# include "ui_Widget_MessageSend.h"
# include <string>
# include <qlistwidget.h>
# include <qpixmap.h>
# include <map>
# include <boost/bimap.hpp>
# include "Widget_ChatItem_Controller.h"
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

    void setItem(string id, int newMessageNum, QPixmap pic, string name, string message, string time, bool mute);
    bool newItemInsert(string id, int newMessageNum, QPixmap pic,string name, string message, string time, bool mute);
    bool updateItem(string id, int newMessageNum, QPixmap pic, string name, string message, string time, bool mute);

    bool removeItem(string id);
    
    void setMessage(vector<Message> m);

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
    boost::bimap<string, QListWidgetItem*> m_ID2Item;
    // 各个发送者的uid对应的消息
    map<string, vector<Message>> m_Messages;


private:
    Ui::Widget_Main ui_main;
    Ui::Widget_Send ui_send;
    Ui::Widget_ChatList ui_ChatList;
    Ui::Widget_MessageShow ui_MessageShow;
    
};

