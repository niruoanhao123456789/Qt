#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Qt默认不会跟踪鼠标移动的事件，否则相关事件容易过多，只有用户显示调用的情况下才会跟踪
    // 把这个选项设置为 true, 才能够追踪鼠标的移动位置.
    this->setMouseTracking(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    qDebug() << event->position().x() << " " << event->position().y();
}
