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
    // 创建 QMessageBox
    QMessageBox* messagebox = new QMessageBox();
    messagebox->setWindowTitle("这是对话框标题");
    messagebox->setText("这是对话框文本");
    messagebox->setIcon(QMessageBox::Warning);
    // 标准按钮无法进行信号槽的链接. (这些按钮是QMessageBox自己生成的)
    messagebox->setStandardButtons(QMessageBox::Ok | QMessageBox::Save | QMessageBox::Cancel);

    // 也可以自定义QPushButtton, 并实现槽函数与connect

    // QMessageBox 使用场景更多的是模态的.
    // 弹出模态对话框, 当对话框处于弹出状态的时候, 代码就会在 exec 这里阻塞. 一直到对话框被关闭.
    // 用户点击按钮, 使对话框关闭之后, 此时就能通过 exec 的返回值, 来知道用户点击的是哪个按钮, 从而执行一些对应的逻辑了.
    int ret = messagebox->exec();
    if(ret == QMessageBox::Ok)
        qDebug() << "ok";
    else if(ret == QMessageBox::Save)
        qDebug() << "save";
    else if(ret == QMessageBox::Cancel)
        qDebug() << "cancel";

    // delete messageBox;
    messagebox->setAttribute(Qt::WA_DeleteOnClose);
}

