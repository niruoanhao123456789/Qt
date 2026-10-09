#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 这种写法如果原本存在QMenuBar，会让原来的脱离Qt的对象树,造成内存泄漏
    // QMenuBar* menubar = new QMenuBar();

    // 这种写法，在QMenuBar存在的情况下则去获取原来的；不存在则创建新的
    QMenuBar* menubar = this->menuBar();
    this->setMenuBar(menubar);

    QMenu* menu = new QMenu("菜单");
    menubar->addMenu(menu);

    QAction* action1 = new QAction("菜单项1");
    QAction* action2 = new QAction("菜单项2");

    action1->setIcon(QIcon(":/doucument.png"));
    action2->setIcon(QIcon(":/doucument.png"));

    menu->addAction(action1);
    menu->addSeparator();
    menu->addAction(action2);
}

MainWindow::~MainWindow()
{
    delete ui;
}
