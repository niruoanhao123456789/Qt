#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QMenuBar* menubar = new QMenuBar();
    this->setMenuBar(menubar);

    QMenu* menuParent = new QMenu("父菜单");
    QMenu* menuChild = new QMenu("子菜单1");

    menubar->addMenu(menuParent);
    menuParent->addMenu(menuChild);

    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");
    menuChild->addAction(action1);
    menuChild->addAction(action2);

    QMenu* menuChild2 = new QMenu("子菜单2");
    menuChild->addMenu(menuChild2);

}

MainWindow::~MainWindow()
{
    delete ui;
}
