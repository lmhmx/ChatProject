# include "ChatCoreTask.h"
ChatCoreTask::ChatCoreTask() {
	init();
}

void ChatCoreTask::init() {

	
	
	
	m_UserManager = new UserManager();

	connect(m_UserManager, &UserManager::signalNewMessageFromUser, this, &ChatCoreTask::slotNewMessageFromUser);


}
void ChatCoreTask::slotNewMessageFromUser(User* sender, string& message) {

	qDebug() << QString::fromStdString(message);


}