#include "LogInRegisterUiController.h"
LogInRegisterUiController::LogInRegisterUiController(QWidget* parent):QWidget(parent) {
	setPageMailLogIn();
}

bool LogInRegisterUiController::checkLogInMailOK(string mail, string pwd) {
	if (mail.size() > 5 && pwd.size() > 5) {
		return true;
	}
	return false;
}
bool LogInRegisterUiController::checkLogInPhoneOK(string phone, string pwd) {
	if (phone.size() == 11 && pwd.size() > 5) {
		return true;
	}
	return false;
}
bool LogInRegisterUiController::checkRegisterMailOK(string mail, string pwd, string confirmPwd) {
	if (mail.size() > 5 && pwd.size() > 5 && pwd == confirmPwd) {
		return true;
	}
	return false;
}
bool LogInRegisterUiController::checkRegisterPhoneOK(string phone, string pwd, string confirmPwd) {
	if (phone.size() == 11 && pwd == confirmPwd && pwd.size() > 5) {
		return true;
	}
	return false;
}

/*****************************************************************
* mail login 界面
* 
*/

void LogInRegisterUiController::setPageMailLogIn() {
	for (auto i = children().begin(); i < children().end(); i++) {
		delete (*i);
	}

	ui_mail_LogIn.setupUi(this);
	for (auto i = children().begin(); i < children().end(); i++) {
		qobject_cast<QWidget*>(*i)->show();
	}


	ui_mail_LogIn.lineEdit_Passwd->setEchoMode(QLineEdit::EchoMode::Password);
	connect(ui_mail_LogIn.pushButton_LogIn, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_logIn_mail_logIn_click);
	connect(ui_mail_LogIn.pushButton_Register, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_logIn_mail_register_click);
	connect(ui_mail_LogIn.pushButton_Quit, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_logIn_mail_quit_click);
	connect(ui_mail_LogIn.pushButton_ForgetPwd, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_logIn_mail_forgetPw_click);
	connect(ui_mail_LogIn.pushButton_phoneLogIn, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_logIn_mail_phone_logIn);
}

void LogInRegisterUiController::slot_logIn_mail_logIn_click() {
	QString mail = ui_mail_LogIn.lineEdit_Mail->text();
	QString pwd = ui_mail_LogIn.lineEdit_Passwd->text();
	if (checkLogInMailOK(mail.toStdString(), pwd.toStdString())) {
		emit signal_LogInByMail(mail.toStdString(), pwd.toStdString());
	}
	else {
		QMessageBox::warning(0, "error", "mail or pwd is not correct, check your mail or passwd");
	}
}
void LogInRegisterUiController::slot_logIn_mail_register_click() {
	// TODO:切换界面
	setPageMailRegister();
}
void LogInRegisterUiController::slot_logIn_mail_forgetPw_click() {
	// TODO: 忘记密码
	QMessageBox::warning(0, "info", "being programmed");
}
void LogInRegisterUiController::slot_logIn_mail_quit_click() {
	exit(0);
}
void LogInRegisterUiController::slot_logIn_mail_phone_logIn() {
	// TODO: 切换到电话界面
	QMessageBox::warning(0, "info", "phone log in hasn't been supported");
}
/**********************************************************
* end of mail log in
*/

/***********************************************************
* mail register 界面
*/
void LogInRegisterUiController::setPageMailRegister() {
	for (auto i = children().begin(); i < children().end(); i++) {
		delete (*i);
	}
	ui_mail_register.setupUi(this);
	for (auto i = children().begin(); i < children().end(); i++) {
		qobject_cast<QWidget*>(*i)->show();
	}
	
	connect(ui_mail_register.pushButton_LogIn, &QPushButton::clicked, 
		this, &LogInRegisterUiController::slot_register_mail_logIn_click);
	connect(ui_mail_register.pushButton_Quit, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_register_mail_quit_click);
	connect(ui_mail_register.pushButton_phoneLogIn, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_register_mail_phone_logIn);
	connect(ui_mail_register.pushButton_Register, &QPushButton::clicked,
		this, &LogInRegisterUiController::slot_register_mail_register_click);
}

void LogInRegisterUiController::slot_register_mail_logIn_click() {
	setPageMailLogIn();
}
void LogInRegisterUiController::slot_register_mail_register_click() {
	// 邮箱注册
	QString mail = ui_mail_register.lineEdit_Mail->text();
	QString pwd = ui_mail_register.lineEdit_Passwd->text();
	QString confirmPwd = ui_mail_register.lineEdit_Passwd_Confirm->text();
	if (checkRegisterMailOK(mail.toStdString(), pwd.toStdString(), confirmPwd.toStdString())) {
		emit signal_RegisterByMail(mail.toStdString(), pwd.toStdString());
	}
	else {
		QMessageBox::warning(0, "info", "mail or passwd is not correct or passwd is not coincident");
	}
}

void LogInRegisterUiController::slot_register_mail_quit_click() {
	exit(0);
}
void LogInRegisterUiController::slot_register_mail_phone_logIn() {
	QMessageBox::warning(0, "info", "phone log in hasn't been supported");
}

/****************************************************************
* end of mail register
*/


/*****************************************************************
* 
*/
void LogInRegisterUiController::setPagePhoneLogIn() {

}

void LogInRegisterUiController::slot_logIn_phone_logIn_click() {
	// 登录
}
void LogInRegisterUiController::slot_logIn_phone_register_click() {
	// 切换页面
	setPageMailRegister();
}
void LogInRegisterUiController::slot_logIn_phone_forgetPw_click() {

}
void LogInRegisterUiController::slot_logIn_phone_quit_click() {
	exit(0);
}
void LogInRegisterUiController::slot_logIn_phone_mail_logIn() {
	setPageMailLogIn();
}

/****************************************************************
*
*/


/*****************************************************************
*
*/
void LogInRegisterUiController::setPagePhoneRegister() {

}

void LogInRegisterUiController::slot_register_phone_logIn_click() {

}
void LogInRegisterUiController::slot_register_phone_register_click() {

}
void LogInRegisterUiController::slot_register_phone_forgetPw_click() {

}
void LogInRegisterUiController::slot_register_phone_quit_click() {

}
void LogInRegisterUiController::slot_register_phone_phone_logIn() {

}
/*******************************************************************
*
*/