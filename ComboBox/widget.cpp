#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->comboBox->addItem("汉堡1");
    ui->comboBox->addItem("汉堡2");
    ui->comboBox->addItem("汉堡3");

    ui->comboBox_2->addItem("炸鸡1");
    ui->comboBox_2->addItem("炸鸡2");
    ui->comboBox_2->addItem("炸鸡3");

    ui->comboBox_3->addItem("饮料1");
    ui->comboBox_3->addItem("饮料2");
    ui->comboBox_3->addItem("饮料3");
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<ui->comboBox->currentText()<<" "<<ui->comboBox_2->currentText()<<" "<<ui->comboBox_3->currentText();
}

