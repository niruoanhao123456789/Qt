#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QVBoxLayout>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    QPushButton* button3 = new QPushButton("按钮3");

    // 每个Widget中只能有一个布局管理器
    // 创建布局管理器
    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(button1);
    layout->addWidget(button2);
    layout->addWidget(button3);

    // 把布局管理器添加到窗口中
    this->setLayout(layout);
}

Widget::~Widget()
{
    delete ui;
}
