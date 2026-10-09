#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏
    QMenuBar* menuBar = new QMenuBar();
    this->setMenuBar(menuBar);

    // 创建菜单
    QMenu* menu1 = new QMenu("文件 (&F)");
    QMenu* menu2 = new QMenu("编辑 (&E)");
    QMenu* menu3 = new QMenu("视图 (&V)");
    QMenu* menu4 = new QMenu("关于 (&A)");
    menuBar->addMenu(menu1);
    menuBar->addMenu(menu2);
    menuBar->addMenu(menu3);
    menuBar->addMenu(menu4);

    // 创建菜单项
    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");
    QAction* action3 = new QAction("菜单项3");
    QAction* action4 = new QAction("菜单项4");
    menu1->addAction(action1);
    menu2->addAction(action2);
    menu3->addAction(action3);
    menu4->addAction(action4);

    // 不绑定槽函数, 通过快捷键选中也没啥反应
    connect(action1,&QAction::triggered,this, &MainWindow::handle1);
    connect(action2, &QAction::triggered, this, &MainWindow::handle2);
    connect(action3, &QAction::triggered, this, &MainWindow::handle3);
    connect(action4, &QAction::triggered, this, &MainWindow::handle4);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handle1()
{
    qDebug() << "handle1";
}

void MainWindow::handle2()
{
    qDebug() << "handle2";
}

void MainWindow::handle3()
{
    qDebug() << "handle3";
}

void MainWindow::handle4()
{
    qDebug() << "handle4";
}
