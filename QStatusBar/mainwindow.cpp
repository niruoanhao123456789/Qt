#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QLabel>
#include <QProgressBar>
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 状态栏的获取与创建
    QStatusBar* statusbar = this->statusBar();

    this->setStatusBar(statusbar);

    // 显示临时消息
    // statusBar->showMessage("这是一个临时消息");

    // 给状态栏添加子控件
    QLabel* label = new QLabel("这是一个label");
    statusbar->addWidget(label);

    QProgressBar* progressbar = new QProgressBar();
    progressbar->setRange(0,100);
    progressbar->setValue(50);
    statusbar->addWidget(progressbar);

    QPushButton* button = new QPushButton("按钮");
    statusbar->addPermanentWidget(button);

}

MainWindow::~MainWindow()
{
    delete ui;
}
