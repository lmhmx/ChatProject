#pragma once
# include "ui_Widget_LogIn_Mail.h"
# include <qwidget.h>
class LogInUiController:public QWidget
{
public:
	LogInUiController(QWidget* parent = Q_NULLPTR);
private:
	Ui::Widget_LogIn_Mail ui;
};

