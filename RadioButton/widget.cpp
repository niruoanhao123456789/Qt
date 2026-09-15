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

void Widget::on_radioButton_clicked(bool checked)
{
    qDebug()<<"checked state:"<<checked;
}

void Widget::on_radioButton_2_pressed()
{
    qDebug()<< "pressed";
}

void Widget::on_radioButton_3_released()
{
    qDebug()<<"released";
}

void Widget::on_radioButton_4_toggled(bool checked)
{
    qDebug()<<"checked state:"<<checked;
}

