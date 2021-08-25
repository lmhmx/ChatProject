#pragma once
# include "ui_Widget_MessageShow.h"
# include <qwidget.h>
# include <vector>
# include "Share.h"
using namespace std;

class Widget_MessageShow_Controller:public QWidget
{
public:
	Widget_MessageShow_Controller(QWidget* parent = Q_NULLPTR);

	void addMessage(vector<Message> m);

	void setMessage(vector<Message> m);

private:

	vector<Message> m_Message;

private:


	Ui::Widget_MessageShow ui;
};

