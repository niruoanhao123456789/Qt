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

void Widget::on_dial_valueChanged(int value)
{
    ui->label->setText(QString::number(value));
    this->setWindowOpacity((double)value / 100 );
}

