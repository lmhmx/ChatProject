#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatApp.h"

class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);

private:
    Ui::ChatClientAppClass ui;
};
