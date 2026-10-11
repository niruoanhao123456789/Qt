#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDockWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 给主窗口添加一个子窗口
    QDockWidget* dockWidget = new QDockWidget();
    // 将浮动窗口添加到子窗口中
    this->addDockWidget(Qt::LeftDockWidgetArea, dockWidget);\

    // 浮动窗口也可设置标题的
    dockWidget->setWindowTitle("这是浮动窗口");

    // 也能为浮动窗口内部添加一些组件
    // 但不能直接给浮动窗口添加子控件，而需要单独地创造出一个单独的QWidget，把需要添加的控件加入到QWidget中
    // 然后再将这个QWidget设置到dockWidget中
    QWidget* container = new QWidget();
    dockWidget->setWidget(container);

    // 创建布局管理器，把布局管理设置到Qwidget中
    QVBoxLayout* layout = new QVBoxLayout();
    container->setLayout(layout);

    // 创建其他控件添加到layout中
    QLabel* label = new QLabel("这是一个 QLabel");
    QPushButton* button = new QPushButton("这只是一个按钮");
    layout->addWidget(label);
    layout->addWidget(button);

    // 设置浮动窗口允许停靠的位置
    dockWidget->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);

}

MainWindow::~MainWindow()
{
    delete ui;
}
