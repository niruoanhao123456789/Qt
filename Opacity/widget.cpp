#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

// 窗口透明度修改
void Widget::on_pushButton_inc_clicked()
{
    float opcity = this->windowOpacity();
    if(opcity>=1)
        return;
    opcity += 0.1;
    qDebug()<<"opcity: "<<opcity;
    this->setWindowOpacity(opcity);
}


void Widget::on_pushButton_des_clicked()
{
    float opcity = this->windowOpacity();
    if(opcity<=0)
        return;
    opcity -= 0.1;
    qDebug()<<"opcity: "<<opcity;
    this->setWindowOpacity(opcity);

}