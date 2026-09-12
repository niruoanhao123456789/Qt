#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handle1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handle1()
{
    this->setWindowTitle("哈哈哈");
}

void Widget::handle2()
{
    this->setWindowTitle("hello");
}

void Widget::on_pushButton_2_clicked()
{
    disconnect(ui->pushButton,&QPushButton::clicked,this,&Widget::handle1);
    connect(ui->pushButton,&QPushButton::clicked,this,&Widget::handle2);
}