#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int ret = QInputDialog::getInt(this,"整形输入对话框","请输入一个整数:");
    qDebug() << ret;
}


void MainWindow::on_pushButton_2_clicked()
{
    double ret = QInputDialog::getDouble(this,"浮点数输入框","请输入一个浮点数:");
    qDebug() << ret;
}


void MainWindow::on_pushButton_3_clicked()
{
    QStringList items;
    items.push_back("111");
    items.push_back("222");
    items.push_back("333");
    items.push_back("999");
    QString ret = QInputDialog::getItem(this,"条目对话框","请输入条目:",items);
    qDebug() << ret;
}

