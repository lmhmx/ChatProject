#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatApp.h"
# include "LogInUiController.h"
class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);


private:
    LogInUiController* m_LogInUiController;

private:
    
    Ui::ChatClientAppClass ui;
};
