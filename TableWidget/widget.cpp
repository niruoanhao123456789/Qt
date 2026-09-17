#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 创建三行
    ui->tableWidget->insertRow(0);
    ui->tableWidget->insertRow(1);
    ui->tableWidget->insertRow(2);

    // 创建三列
    ui->tableWidget->insertColumn(0);
    ui->tableWidget->insertColumn(1);
    ui->tableWidget->insertColumn(2);

    // 给3个列设置列名
    ui->tableWidget->setHorizontalHeaderItem(0,new QTableWidgetItem("学号"));
    ui->tableWidget->setHorizontalHeaderItem(1,new QTableWidgetItem("姓名"));
    ui->tableWidget->setHorizontalHeaderItem(2,new QTableWidgetItem("年龄"));

    // 给表中添加数据
    ui->tableWidget->setItem(0,0,new QTableWidgetItem("1001"));
    ui->tableWidget->setItem(0,1,new QTableWidgetItem("张三"));
    ui->tableWidget->setItem(0,2,new QTableWidgetItem("20"));

    ui->tableWidget->setItem(1,0,new QTableWidgetItem("1002"));
    ui->tableWidget->setItem(1,1,new QTableWidgetItem("李四"));
    ui->tableWidget->setItem(1,2,new QTableWidgetItem("19"));

    ui->tableWidget->setItem(2,0,new QTableWidgetItem("1003"));
    ui->tableWidget->setItem(2,1,new QTableWidgetItem("王五"));
    ui->tableWidget->setItem(2,2,new QTableWidgetItem("18"));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_inertrow_clicked()
{
    // 需要知道当前多少行
    int rowcnt = ui->tableWidget->rowCount();
    // 在最后一行新增新行
    // 此处填入的是新增的下标
    ui->tableWidget->insertRow(rowcnt);
}


void Widget::on_pushButton_insertcol_clicked()
{
    int col = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(col);
    const QString& text = ui->lineEdit->text();
    ui->tableWidget->setHorizontalHeaderItem(col,new QTableWidgetItem(text));
}


void Widget::on_pushButton_insertrow_clicked()
{
    int row = ui->tableWidget->currentRow();
    ui->tableWidget->removeRow(row);
}


void Widget::on_pushButton_insertcol_2_clicked()
{
    int col = ui->tableWidget->currentColumn();
    ui->tableWidget->removeColumn(col);
}

