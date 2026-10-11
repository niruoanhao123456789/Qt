#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

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
    // 弹出一个用ui自定义的对话框
    Dialog* dialog = new Dialog(this);
    // 用于关闭对话框时，要求析构对话框对象，避免内存泄漏
    dialog->setAttribute(Qt::WA_DeleteOnClose);

    // 非模态对话框，即打开对话框后，仍能对父类窗口进行操作
    // dialog->show();

    // 模态对话框
    dialog->exec();
}

