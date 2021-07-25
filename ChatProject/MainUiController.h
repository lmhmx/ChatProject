#pragma once
#include <qwidget.h>
# include "ui_Widget_Main.h"
# include "ui_Widget_ChatItem.h"
# include "ui_Widget_ChatList.h"
# include "ui_Widget_MessageShow.h"
# include "ui_Widget_MessageSend.h"
# include <string>
# include "Share.h"
using namespace std;
class MainUiController:
    public QWidget
{
    Q_OBJECT

public:
    MainUiController(QWidget* parent = Q_NULLPTR);

public:
    bool newItemInsert(string id, int newMessageNum, QIcon pic,string name, string message, string time, bool mute);
    bool updateItem(string id, int newMessageNum, QIcon pic, string name, string message, string time, bool mute);

    bool removeItem(string id);
    
public:
    void slot_SendMessageClick();
    void slot_SendMessageEnterClick();
    void slot_EmojiClick();
    void slot_FileClick();
    
    void slot_AddClick();

signals:
    void signal_SendMessage(Message m);


private:
    Ui::Widget_Main ui_main;
    Ui::Widget_Send ui_send;
    Ui::Widget_ChatItem ui_ChatItem;
    Ui::Widget_ChatList ui_ChatList;
    Ui::Widget_MessageShow ui_MessageShow;
    
};

