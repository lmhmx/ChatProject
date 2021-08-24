#pragma once
# include "ui_Widget_MessageSend.h"
# include <qwidget.h>
class Widget_MessageSend_Controller:public QWidget
{
public:
	Widget_MessageSend_Controller(QWidget* parent = Q_NULLPTR);

private:
	Ui::Widget_Send ui;
};

