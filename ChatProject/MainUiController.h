#pragma once
#include <qwidget.h>
# include "ui_Widget_Main.h"
class MainUiController :
    public QWidget
{
    Q_OBJECT

public:
    MainUiController(QWidget* parent = Q_NULLPTR);
private:
    Ui::Widget_Main ui;
};

