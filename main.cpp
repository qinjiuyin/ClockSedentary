#include "mainwindow.h"
#include <QApplication>
#include <QThread>
#include <QWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMinimumSize(180, 60);
    w.setMaximumSize(180, 60);
    w.setWindowFlags(Qt::WindowStaysOnTopHint); //置顶 没找到定时器不休眠的办法
    w.setWindowFlags(w.windowFlags() & ~Qt::WindowMinimizeButtonHint);//关闭最小化防止点到最小化
    w.show();

    return a.exec();
}
