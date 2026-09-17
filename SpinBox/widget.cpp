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

    // 针对SpinBox
    ui->spinBox->setRange(1,10);
    ui->spinBox_2->setRange(1,10);
    ui->spinBox_3->setRange(1,10);

    ui->spinBox->setValue(1);
    ui->spinBox_2->setValue(2);
    ui->spinBox_3->setValue(3);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    qDebug()<<ui->comboBox->currentText()<<" "<<ui->spinBox->value()<<"\n"
            <<ui->comboBox_2->currentText()<<" "<<ui->spinBox_2->value()<<"\n"
            <<ui->comboBox_3->currentText()<<" "<<ui->spinBox_3->value()<<"\n";
}

