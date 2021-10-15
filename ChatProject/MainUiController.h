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
    // 发送MainUi到更高级的信息，利用map中的元素进行命令控制
    void signal_SendMessage(map<string,string> m);


public:

private:

    // 在聊天显示界面显示消息
    void setCurrentChat(string id);

    

protected:
    // 接收列表的信号
    void slot_SelectChanged();
    // 接收点击+号的信号
    void slot_SearchClicked();
    // 接收发送enter的信号
    void slot_SendMessage(string message_text);

private:
    

private:
    // 索引和每一个id对应的消息
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

