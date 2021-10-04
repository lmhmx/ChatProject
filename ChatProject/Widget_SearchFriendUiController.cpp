#include "Widget_SearchFriendUiController.h"

Widget_SearchFriendUiController::Widget_SearchFriendUiController(QWidget* parent) 
	:QWidget(parent) {
	ui.setupUi(this);
	ui.widget_result->hide();
	connect(ui.pushButton_search, &QPushButton::clicked,
		[=]() {
			emit signal_searchFriend(ui.lineEdit_userID->text().toStdString());
		});
	connect(ui.pushButton_add, &QPushButton::clicked,
		[=]() {
			emit signal_addFriend(ui.label_id->text().toStdString(),
				ui.label_name->text().toStdString());
		});
}
void Widget_SearchFriendUiController::slot_showFindFriend(
	string friend_id, string friend_name) {

	if (friend_id.size() != 0) {
		ui.widget_result->show();
		ui.label_id->setText(QString::fromStdString(friend_id));
		ui.label_name->setText(QString::fromStdString(friend_name));
		ui.pushButton_add->setEnabled(true);
	}
	else {
		ui.widget_result->show();
		ui.label_id->setText(QString::fromStdString(friend_id));
		ui.label_name->setText(QString::fromStdString("no such user"));
		ui.pushButton_add->setEnabled(false);
	}
}