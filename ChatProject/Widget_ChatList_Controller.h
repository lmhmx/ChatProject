#pragma once
#include <qwidget.h>
# include "ui_Widget_ChatList.h"
# include "Widget_ChatItem_Controller.h"
# include <qpixmap.h>
# include <boost/bimap.hpp>

class Widget_ChatList_Controller:public QWidget
{
	Q_OBJECT

public:
	Widget_ChatList_Controller(QWidget* parent = Q_NULLPTR);

	void setItem(string id, int newMessageNum, QPixmap pic, string name, string message, string time, bool mute);
	bool newItemInsert(string id, int newMessageNum, QPixmap pic, string name, string message, string time, bool mute);
	bool updateItem(string id, int newMessageNum, QPixmap pic, string name, string message, string time, bool mute);

	bool removeItem(string id);


signals:
	// 将QT接口封装成自己的类的接口
	void signal_itemSelectionChanged();
public slots:
	// 返回当前选中的项的对应的ID
	string currentSelectionID();
	string setCurrentSelect(string id);


private:

	boost::bimap<string, QListWidgetItem*> m_ID2Item;

	Ui::Widget_ChatList ui;
};

