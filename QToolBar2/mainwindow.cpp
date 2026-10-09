#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建菜单栏
    QMenuBar* menubar = this->menuBar();
    this->setMenuBar(menubar);

    // 创建菜单
    QMenu* menu = new QMenu("文件");
    menubar->addMenu(menu);

    // 创建工具栏
    QToolBar* toolbar = new QToolBar();
    this->addToolBar(toolbar);

    // 创建菜单项
    QAction* action1 = new QAction("保存");
    QAction* action2 = new QAction("打开");

    action1->setToolTip("点击此处保存文件");

    // 可将菜单项放到菜单中
    menu->addAction(action1);
    menu->addAction(action2);

    // 可将菜单项放到工具栏中
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
