#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QToolBar* toolbar1 = new QToolBar();
    QToolBar* toolbar2 = new QToolBar();

    this->addToolBar(toolbar1);
    // 设置工具栏的初始位置，默认的参数是TopToolBarArea
    this->addToolBar(Qt::LeftToolBarArea,toolbar2);

    // 对工具栏停靠位置进行限制
    toolbar2->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);

    // 设置允许移动
    toolbar2->setMovable(true);

    // 设置允许浮动
    toolbar2->setFloatable(true);

    QAction* action1 = new QAction("动作1");
    QAction* action2 = new QAction("动作2");
    QAction* action3 = new QAction("动作3");
    QAction* action4 = new QAction("动作4");

    toolbar1->addAction(action1);
    toolbar1->addAction(action2);
    toolbar2->addAction(action3);
    toolbar2->addAction(action4);

}

MainWindow::~MainWindow()
{
    delete ui;
}
