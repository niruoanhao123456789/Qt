#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->listWidget->addItem("C++");
    ui->listWidget->addItem("Java");
    ui->listWidget->addItem("CoLang");
    ui->listWidget->addItem("Python");


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous)
{
    if(current)
        qDebug()<<"当前选中的元素："<<current->text();
    if(previous)
        qDebug()<<"上一个选中的元素："<<previous->text();

}


void Widget::on_pushButton_add_clicked()
{
    const QString& text = ui->lineEdit->text();
    ui->listWidget->addItem(text);
}


void Widget::on_pushButton_take_clicked()
{
    int row = ui->listWidget->currentRow();
    if(row<0)
        return;
    ui->listWidget->takeItem(row);
}

