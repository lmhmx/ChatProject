#include "ChatClientApp.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatClientApp w;
    w.show();
    return a.exec();
}
