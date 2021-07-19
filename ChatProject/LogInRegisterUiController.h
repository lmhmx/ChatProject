#pragma once
# include "ui_Widget_LogIn_Mail.h"
# include "ui_Widget_LogIn_Phone.h"
# include "ui_Widget_Register_Mail.h"
# include "ui_Widget_Register_Phone.h"
# include <qwidget.h>
# include <qmessagebox.h>
# include <string>
using namespace std;

class LogInRegisterUiController :public QWidget
{
	Q_OBJECT
public:
	LogInRegisterUiController(QWidget* parent = Q_NULLPTR);

private:
	// 邮件登录界面
	void slot_logIn_mail_logIn_click();
	void slot_logIn_mail_register_click();
	void slot_logIn_mail_forgetPw_click();
	void slot_logIn_mail_quit_click();
	void slot_logIn_mail_phone_logIn();

	// 电话登录界面
	void slot_logIn_phone_logIn_click();
	void slot_logIn_phone_register_click();
	void slot_logIn_phone_forgetPw_click();
	void slot_logIn_phone_quit_click();
	void slot_logIn_phone_mail_logIn();

	void slot_register_mail_logIn_click();
	void slot_register_mail_register_click();
	void slot_register_mail_quit_click();
	void slot_register_mail_phone_logIn();

	void slot_register_phone_logIn_click();
	void slot_register_phone_register_click();
	void slot_register_phone_forgetPw_click();
	void slot_register_phone_quit_click();
	void slot_register_phone_phone_logIn();

signals:
	void signal_LogInByPhone(string phone, string pwd);
	void signal_LogInByMail(string mail, string pwd);
	void signal_RegisterByMail(string mail, string pwd);
	void signal_RegisterByPhone(string phone, string pwd);

protected:
	bool checkLogInMailOK(string mail, string pwd);
	bool checkLogInPhoneOK(string phone, string pwd);
	bool checkRegisterMailOK(string mail, string pwd, string confirmPwd);
	bool checkRegisterPhoneOK(string phone, string pwd, string confirmPwd);

	void setPageMailLogIn();
	void setPageMailRegister();
	void setPagePhoneLogIn();
	void setPagePhoneRegister();

private:
	Ui::Widget_LogIn_Mail ui_mail_LogIn;
	Ui::Widget_LogIn_Phone ui_phone_LogIn;
	Ui::Widget_Register_Mail ui_mail_register;
	Ui::Widget_Register_Phone ui_phone_register;
};
