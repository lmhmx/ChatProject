#include "LogInRegisterUiController.h"
LogInRegisterUiController::LogInRegisterUiController(QWidget* parent):QWidget(parent) {
	setPageMailLogIn();
}

bool LogInRegisterUiController::checkLogInMailOK(string mail, string pwd) {
	return 1;
}
bool LogInRegisterUiController::checkLogInPhoneOK(string phone, string pwd) {
	return 1;
}
bool LogInRegisterUiController::checkRegisterMailOK(string mail, string pwd, string confirmPwd) {
	return 1;
}
bool LogInRegisterUiController::checkRegisterPhoneOK(string phone, string pwd, string confirmPwd) {
	return 1;
}

void LogInRegisterUiController::slot_logIn_mail_logIn_click() {
	QString mail = ui_mail_LogIn.lineEdit_Mail->text();
	QString pwd = ui_mail_LogIn.lineEdit_Passwd->text();
	if (checkLogInMailOK(mail.toStdString(), pwd.toStdString())) {
		emit signal_LogInByMail(mail.toStdString(), pwd.toStdString());
	}
	else {
		QMessageBox::warning(0, "error", "mail or pwd is not correct");
	}
}
void LogInRegisterUiController::slot_logIn_mail_register_click() {
	// TODO:切换界面
	ui_mail_register.setupUi(this);
}
void LogInRegisterUiController::slot_logIn_mail_forgetPw_click() {
	// TODO: 忘记密码
	QMessageBox::warning(0, "info", "being programmed");
}
void LogInRegisterUiController::slot_logIn_mail_quit_click() {
	exit(0);
}
void LogInRegisterUiController::slot_logIn_mail_phone_logIn() {
	// TODO: 切换界面
}

void LogInRegisterUiController::slot_logIn_phone_logIn_click() {

}
void LogInRegisterUiController::slot_logIn_phone_register_click() {

}
void LogInRegisterUiController::slot_logIn_phone_forgetPw_click() {

}
void LogInRegisterUiController::slot_logIn_phone_quit_click() {

}
void LogInRegisterUiController::slot_logIn_phone_mail_logIn() {

}

void LogInRegisterUiController::slot_register_mail_logIn_click() {

}
void LogInRegisterUiController::slot_register_mail_register_click() {

}
void LogInRegisterUiController::slot_register_mail_forgetPw_click() {

}
void LogInRegisterUiController::slot_register_mail_quit_click() {

}
void LogInRegisterUiController::slot_register_mail_phone_logIn() {

}

void LogInRegisterUiController::slot_register_mail_logIn_click() {

}
void LogInRegisterUiController::slot_register_mail_register_click() {

}
void LogInRegisterUiController::slot_register_mail_forgetPw_click() {

}
void LogInRegisterUiController::slot_register_mail_quit_click() {

}
void LogInRegisterUiController::slot_register_mail_phone_logIn() {

}
void LogInRegisterUiController::setPageMailLogIn() {
	
	ui_mail_LogIn.setupUi(this);
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
void LogInRegisterUiController::setPageMailRegister() {

}
void LogInRegisterUiController::setPagePhoneLogIn() {

}
void LogInRegisterUiController::setPagePhoneRegister() {

}