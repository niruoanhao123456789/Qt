#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

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
    int ret = QMessageBox::information(this,"对话框标题","对话框内容",QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);
    if(ret == QMessageBox::Ok)
        qDebug()<< "ok";
    else if(ret == QMessageBox::Save)
        qDebug() << "save";
    else if(ret == QMessageBox::Cancel)
        qDebug() << "cancal";


}

