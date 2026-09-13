#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置按钮的ToolTip
    ui->pushButton_no->setToolTip("This is a 'no'");
    ui->pushButton_no->setToolTipDuration(3000);
}

Widget::~Widget()
{
    delete ui;
}
