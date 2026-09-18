#include "widget.h"
#include "ui_widget.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QVBoxLayout* vlayout = new QVBoxLayout();
    this->setLayout(vlayout);

    QPushButton* button1 = new QPushButton("按钮1");
    QPushButton* button2 = new QPushButton("按钮2");
    vlayout->addWidget(button1);
    vlayout->addWidget(button2);

    QHBoxLayout* hlayout = new QHBoxLayout();
    this->setLayout(hlayout);

    QPushButton* button3 = new QPushButton("按钮3");
    QPushButton* button4 = new QPushButton("按钮4");
    hlayout->addWidget(button3);
    hlayout->addWidget(button4);

    // 把水平布局管理器添加到垂直布局管理器中
    vlayout->addLayout(hlayout);
}

Widget::~Widget()
{
    delete ui;
}
