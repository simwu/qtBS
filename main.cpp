#include "view.h"
#include "controller.h"
#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication application(argc, argv);

    QFile styleFile(":/resources/css/styles.qss");
    if(styleFile.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        application.setStyleSheet(styleFile.readAll());
        styleFile.close();
    }

    Controller controller;
    View view(controller);
    view.showMaximized();

    return application.exec();
}
