#include "Widget_ChatItem_Controller.h"
Widget_ChatItem_Controller::Widget_ChatItem_Controller(QWidget* parent):QWidget(parent){
	ui.setupUi(this);
	setContent(0, QPixmap(32,32), "", "", "", false);
}
void Widget_ChatItem_Controller::setContent(int newMessageNum,
	QPixmap pic, string name, string message, string time, bool mute) {
	ui.label_Head->setPixmap(pic);
	ui.label_Name->setText(name.c_str());
	ui.label_Message->setText(message.c_str());
	ui.label_Time->setText(time.c_str());
	ui.label_Mute->setText(mute ? "silent" : "sound");
}
