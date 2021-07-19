#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_ChatApp.h"
# include "LogInRegisterUiController.h"
class ChatClientApp : public QMainWindow
{
    Q_OBJECT

public:
    ChatClientApp(QWidget *parent = Q_NULLPTR);


private:
    LogInRegisterUiController* m_LogInRegisterUiController;

private:
    
    Ui::ChatClientAppClass ui;
};
