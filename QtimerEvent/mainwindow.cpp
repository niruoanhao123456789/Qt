#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 开启定时器事件.
    // 此处 timerId 是一个定时器的身份标识
    _timerId = static_cast<Qt::TimerId>(this->startTimer(1000));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    // 如果一个程序中存在多个定时器 (startTimer 创建的定时器), 此时每个定时器都会触发 timerEvent 函数.
    // 先判定一下这次触发是否是想要的定时器触发的.
    if(event->id() != this->_timerId)
    {
        // 如果不是我们的定时器触发的, 就直接忽略.
        // 当前程序中只有这一个定时器.
        return;
    }

    int value = ui->lcdNumber->intValue();
    if(value <= 0)
    {
        // 停止定时器
        this->killTimer((this->_timerId));
        return;
    }

    value = -1;
    ui->lcdNumber->display(value);
}