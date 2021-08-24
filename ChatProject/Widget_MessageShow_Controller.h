#pragma once
# include "ui_Widget_MessageShow.h"
# include <qwidget.h>
class Widget_MessageShow_Controller:public QWidget
{
public:
	Widget_MessageShow_Controller(QWidget* parent = Q_NULLPTR);

private:
	Ui::Widget_MessageShow ui;
};

