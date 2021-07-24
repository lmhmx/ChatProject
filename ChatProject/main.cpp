#include "ChatClientApp.h"
#include <QtWidgets/QApplication>
# include "Share.h"
int main(int argc, char *argv[])
{
    /*system("pause");
    Message message;
    system("pause");
    qDebug()<<QString::fromStdString(message.to_String());
    system("pause");*/
    QApplication a(argc, argv);
    ChatClientApp w;
    w.show();
    return a.exec();
}
