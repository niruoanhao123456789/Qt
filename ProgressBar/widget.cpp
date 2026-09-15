#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::handle);
    // 在connect后要启动计时器
    timer->start(100);

}

void Widget::handle()
{
    int val = ui->progressBar->value();
    if(val>=100)
    {
        timer->stop();
        return;
    }
    else
        ui->progressBar->setValue(val+1);
}

Widget::~Widget()
{
    delete ui;
}
