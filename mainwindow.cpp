#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Clock = 1800000; //30分钟
    state = 0; //0在计数30分钟
    value = 0;
    QMessageBox::information(nullptr, "标题", "Start Work Sitting Posture!", QMessageBox::Ok);
    connect(&tim,SIGNAL(timeout()),this,SLOT(onTimeOut()));
    tim.setInterval(1);
    tim.start();
    connect(&timUI,SIGNAL(timeout()),this,SLOT(onTimeOutUI()));
    timUI.start(10);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onTimeOut()
{
    value++;
    if(value>=Clock)
    {
        if(state)
        {
            //到了30分钟
            value = 0;
            Clock = 1800000;
            state = 0;
            QMessageBox::information(nullptr, "标题", "10 minutes have passed, and I need to rest and walk around for 10 minutes!", QMessageBox::Ok);
        }
        else
        {
            //到了10分钟
            value = 0;
            Clock = 600000;
            state = 1;
            QMessageBox::information(nullptr, "标题", "30 minutes have passed, and I need to rest and walk around for 10 minutes!", QMessageBox::Ok);
        }
    }
}

void MainWindow::onTimeOutUI()
{
 int milliseconds =  (Clock - value); //剩余的时间
 int minutes, seconds, remaining_ms;
 minutes = milliseconds / (60 * 1000);
 remaining_ms = milliseconds % (60 * 1000);
 seconds = remaining_ms / 1000;
 remaining_ms = remaining_ms % 1000;
 //qDebug("%d allms = %d min %d sec %d ms\n", milliseconds, minutes, seconds, remaining_ms);
 QString display = QString::number(minutes) + "min " + QString::number(seconds) + "sec " +  QString::number(remaining_ms) + "ms";
 ui->label->setText(display);
}

