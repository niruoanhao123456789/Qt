#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建两个线程对象
    Thread t1;
    Thread t2;
    t1.start();
    t2.start();

    t1.wait();
    t2.wait();

    qDebug() << Thread::num;
}

MainWindow::~MainWindow()
{
    delete ui;
}
