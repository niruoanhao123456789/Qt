#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 通过信号槽来更新lcdNumber的页面
    connect(&_thread,&Thread::notify,this,&MainWindow::handle);

    // 启动线程
    _thread.start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle()
{
    // 接受到另一线程发来的信号后修改页面内容
    int value = ui->lcdNumber->intValue();
    ui->lcdNumber->display(--value);

}
