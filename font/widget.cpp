#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label = new QLabel(this);
    label->setText("这是另一端文字内容");

    // 创建字体对象
    std::shared_ptr<QFont> font = std::make_shared<QFont>();
    font->setFamily("仿宋");
    font->setPixelSize(30);
    font->setBold(true);
    font->setItalic(true);
    font->setUnderline(true);
    font->setStrikeOut(true);

    label->setFont(*font);
}

Widget::~Widget()
{
    delete ui;
}
