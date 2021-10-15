#include "Widget_MessageSend_Controller.h"
Widget_MessageSend_Controller::Widget_MessageSend_Controller(QWidget* parent) :QWidget(parent) {
	ui.setupUi(this);
	connect(ui.pushButton_send, &QPushButton::clicked,
		this, &Widget_MessageSend_Controller::slot_SendMessage);
	
}
void Widget_MessageSend_Controller::keyPressEvent(QKeyEvent* ev) {
	if (ev->key() == Qt::Key_Enter) {
		slot_SendMessage();
	}
}
void Widget_MessageSend_Controller::slot_SendMessage() {
	if (ui.textEdit_message->toPlainText().size() == 0) {
		emit signal_SendMessage(ui.textEdit_message->toPlainText().toStdString());
	}
	else {
		QMessageBox::information(0, "info", "message should not be empty");
	}
}
