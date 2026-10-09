#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 工具栏需手动创建，其自身不会被自动创建
    QToolBar* toolbar = new QToolBar();
    this->addToolBar(toolbar);

    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");

    action1->setIcon(QIcon(":/doucument.png"));
    action2->setIcon(QIcon(":/doucument.png"));

    toolbar->addAction(action1);
    toolbar->addAction(action2);

    connect(action1,&QAction::triggered,this,&MainWindow::handle1);
    connect(action2,&QAction::triggered,this,&MainWindow::handle2);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "action1";
}

void MainWindow::handle2()
{
    qDebug() << "action2";
}
