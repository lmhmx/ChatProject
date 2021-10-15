#include "Widget_addFriendUiController.h"

Widget_addFriendUiController::Widget_addFriendUiController(QWidget* parent)
	:QWidget(parent) {
	ui.setupUi(this);
	connect(ui.pushButton_send, &QPushButton::clicked,
		[=]() {
			emit signal_addFriend(ui.lineEdit->text().toStdString(),
				ui.label_id->text().toStdString());
		});
}
void Widget_addFriendUiController::setInfomation(string yourName, string id, string name)
{
	ui.lineEdit->setText(yourName.c_str());
	ui.label_id->setText(id.c_str());
	ui.label_name->setText(name.c_str());
}