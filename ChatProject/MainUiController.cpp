#include "MainUiController.h"
MainUiController::MainUiController(QWidget* parent):QWidget(parent) {
	
	ui_main.setupUi(this);
	ui_ChatList.setupUi(ui_main.widget_ChatList);
	ui_MessageShow.setupUi(ui_main.widget_MessageShow);
	ui_send.setupUi(ui_main.widget_MessageSend);

}
bool MainUiController::newItemInsert(string id,int newMessageNum,
	QIcon pic, string name, string message, string time, bool mute) {
	QWidget* item_widget = new QWidget();
	ui_ChatItem.setupUi(item_widget);
	return true;
}
bool MainUiController::updateItem(string id, int newMessageNum,
	QIcon pic, string name, string message, string time, bool mute) {
	return true;
}
bool MainUiController::removeItem(string id) {
	return true;
}
void MainUiController::slot_SendMessageClick() {

}
void MainUiController::slot_SendMessageEnterClick() {

}
void MainUiController::slot_EmojiClick() {

}
void MainUiController::slot_FileClick() {

}
void MainUiController::slot_AddClick() {

}