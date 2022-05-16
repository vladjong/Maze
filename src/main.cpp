#include "view/mainwindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    srand(time(nullptr));
    QApplication a(argc, argv);
    s21::Facade facade;
    MainWindow w(&facade);
    w.show();
    return a.exec();
}
