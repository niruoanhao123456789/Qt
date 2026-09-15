#include "widget.h"
#include "ui_widget.h"
#include <QTimer>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置初始值
    ui->lcdNumber->display(10);

    timer = new QTimer(this);
    connect(timer,&QTimer::timeout,this,&Widget::handle);
    timer->start(1000);
}

void Widget::handle()
{
    int val = ui->lcdNumber->intValue();
    if(val<=0)
    {
        timer->stop();
        return;
    }
    else
        ui->lcdNumber->display(val-1);
}

Widget::~Widget()
{
    delete ui;
}
