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

void Widget::on_pushButton_clicked()
{
    QDateTime oldtime = ui->dateTimeEdit->dateTime();
    QDateTime newtime = ui->dateTimeEdit_2->dateTime();
    qDebug()<<"oldtime: "<<oldtime<<" newtime: "<<newtime;

    int days = oldtime.daysTo(newtime);
    int seconds = oldtime.secsTo(newtime);

    int hours = (seconds / 3600) % 24;

    ui->label->setText(QString("挣小钱钱已经持续了：")+QString::number(days)+"天 "+QString::number(hours)+QString("小时"));
}

