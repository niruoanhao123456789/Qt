#include "widget.h"
#include "ui_widget.h"
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QPushButton* pbuttton = new QPushButton(this);
    pbuttton->setText("按钮");
    pbuttton->move(100,100);

    connect(pbuttton,&QPushButton::clicked,this,&Widget::handleClicked);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClicked()
{
    // 按下按钮, 修改一下窗口标题.
    this->setWindowTitle("按钮已经按下!");
}
