#pragma once
# include "ui_Widget_MessageSend.h"
# include <qevent.h>
# include <qwidget.h>
# include <qmessagebox.h>
# include "Share.h"
class Widget_MessageSend_Controller:public QWidget
{
	Q_OBJECT
public:
	Widget_MessageSend_Controller(QWidget* parent = Q_NULLPTR);

protected:
	void keyPressEvent(QKeyEvent* ev);

signals:
	void signal_SendMessage(MessageContent messagecontent);

protected:
	void slot_SendMessage();

private:
	Ui::Widget_Send ui;
};

