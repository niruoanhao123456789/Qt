#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(this, &Widget::mySignal, this, &Widget::handleMySignal);
    connect(this, &Widget::mySignal1, this, &Widget::handleMySignal1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleMySignal()
{
    this->setWindowTitle("哈哈哈");
}

void Widget::handleMySignal1(const QString& text)
{
    this->setWindowTitle(text);
}

void Widget::on_pushButton_clicked()
{
    // 发送出自定义的信号
    // 发送信号的操作, 也可以在任意合适的代码中. 不一定非得在构造函数里.

    // 此时就是点击按钮的时候, 发送自定义信号了.
    mySignal();

    // 信号的参数要和其定应的槽的参数一致，或多余它，但槽有的参数，信号一定要有
    // 这样的设计是为了处理可能存在的信号与槽之间：一对一、一对多、多对多的关系
}


void Widget::on_pushButton_2_clicked()
{
    mySignal1("哈喽");
}

