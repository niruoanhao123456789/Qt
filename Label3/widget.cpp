#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置文本对齐方式
    ui->label->setText("这是一段文本");
    ui->label->setAlignment(Qt::AlignRight | Qt::AlignVCenter);

    // 设置自动换行
    ui->label_2->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_2->setWordWrap(true);

    // 设置缩进，此处的缩进在换行后也会存在
    ui->label_3->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_3->setWordWrap(true);
    ui->label_3->setIndent(50);

    // 设置边距
    ui->label_4->setText("这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本这是一段文本");
    ui->label_4->setWordWrap(true);
    ui->label_4->setMargin(10);
}

Widget::~Widget()
{
    delete ui;
}
