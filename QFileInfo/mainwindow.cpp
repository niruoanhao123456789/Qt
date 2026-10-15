#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    // 弹出文件对话框，并获取到文件的属性信息
    QString path = QFileDialog::getOpenFileName(this);
    // 构造QFiltInfo对象
    QFileInfo fileinfo(path);

    // 打印相关属性
    qDebug() << fileinfo.fileName();
    qDebug() << fileinfo.suffix();
    qDebug() << fileinfo.path();
    qDebug() << fileinfo.size();
    qDebug() << fileinfo.isFile();
    qDebug() << fileinfo.isDir();
}

