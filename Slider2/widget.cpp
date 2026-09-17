#include "widget.h"
#include "ui_widget.h"
#include <QShortcut>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QShortcut* sub = new QShortcut(this);
    sub->setKey(QKeySequence("-"));
    QShortcut* add = new QShortcut(this);
    add->setKey(QKeySequence("="));

    connect(sub,&QShortcut::activated,this,&Widget::sub_value);
    connect(add,&QShortcut::activated,this,&Widget::add_value);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_horizontalSlider_valueChanged(int value)
{
    ui->label->setText("当前值为："+QString::number(value));
}

void Widget::add_value()
{
    int val = ui->horizontalSlider->value();
    if(val>=ui->horizontalSlider->maximum())
        return;
    ui->horizontalSlider->setValue(val+5);
}

void Widget::sub_value()
{
    int val = ui->horizontalSlider->value();
    if(val<=ui->horizontalSlider->minimum())
        return;
    ui->horizontalSlider->setValue(val-5);
}

