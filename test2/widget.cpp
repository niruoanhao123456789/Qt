#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    connect(ui->MyButton, &QPushButton::clicked, this, &Widget::handleClick);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::handleClick()
{
    // 当按钮被点击之后, 就把按钮中的文本, 进行切换.
    if (ui->MyButton->text() == QString("hello world")) {
        ui->MyButton->setText("hello qt");
    } else {
        ui->MyButton->setText("hello world");
    }
}
