#include "ChatClientApp.h"
#include <QtWidgets/QApplication>
# include "Share.h"
int main(int argc, char *argv[])
{
    ////char buffer[256]{ '\0' };
    //time_t t = time(0);
    //// strftime(buffer, 256, "%Y-%d", localtime(&t));
    //char* buffer = new char[256] {'\0'};

    //strftime(buffer, 256, " %Y-%m-%d %H:%M:%S", localtime(&t));
    //cout << buffer;
    //Message m0;
    //m0.m_MessageType = MessageType::MessageType::REGISTER;
    //m0.m_MessageReceiver = "asd";
    //m0.m_MessageSender = "da";
    //m0.m_MessageTime = strftime("%Y-%m-%d %H:%M:%S", time(0));
    //m0.m_MessageContent.m_MessageContentType = 
    //    MessageContentType::MessageContentType::REGISTER_request;
    //m0.m_MessageContent.m_Content["MAIL"] = "123";
    //m0.m_MessageContent.m_Content["PAS"] = "ppp";
    //Message m1;
    //string s0;
    //s0 = m0.to_String();
    //qDebug()<<QString::fromStdString(s0);
    //
    //m1 = m0;
    //m1 = m1.to_Message(s0);

    QApplication a(argc, argv);
    ChatClientApp w;
    w.show();
    return a.exec();
}
