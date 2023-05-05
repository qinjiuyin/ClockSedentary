#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    // w.show();

    while(1)
    {
        QThread::sleep(30*60);
        QMessageBox::information(nullptr, "标题", "30 minutes have passed, and I need to rest and walk around for 10 minutes!", QMessageBox::Ok);
        QThread::sleep(10*60);
        QMessageBox::information(nullptr, "标题", "10 minutes have passed, and I need to rest and walk around for 10 minutes!", QMessageBox::Ok);
    }

    return a.exec();
}
