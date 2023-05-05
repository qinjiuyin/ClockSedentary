#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qtimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QTimer tim;
    QTimer timUI;
    int Clock;
    int state;
    int value;
public slots:
    void onTimeOut();
    void onTimeOutUI();
};

#endif // MAINWINDOW_H
