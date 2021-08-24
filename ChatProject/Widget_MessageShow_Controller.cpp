#include "Widget_MessageShow_Controller.h"
Widget_MessageShow_Controller::Widget_MessageShow_Controller(QWidget* parent):QWidget(parent) {
	ui.setupUi(this);
}
void Widget_MessageShow_Controller::addMessage(vector<Message> m) {
	for (auto i = m.begin(); i != m.end(); i++) {
		m_Message.push_back(*i);
		ui.textEdit_Show->append((*i).m_MessageContent.to_String().c_str());
	}
}

void Widget_MessageShow_Controller::setMessage(vector<Message> m) {
	m_Message = m;
	for (auto i = m.begin(); i != m.end(); i++) {
		ui.textEdit_Show->append((*i).m_MessageContent.to_String().c_str());
	}
}
