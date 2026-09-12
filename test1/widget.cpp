#include "widget.h"
#include "ui_widget.h"

#include<QLabel>
#include<QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    QLineEdit* edit = new QLineEdit(this);

    label->setText("hello world");
    edit->setText("hello qt");
}

Widget::~Widget()
{
    delete ui;
}
