#include "login.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    login loginWindow;
    loginWindow.show();

    return a.exec();
}
