#include "widget.h"
#include "ui_widget.h"
#include <QCursor>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // cursor(Qt::WaitCursor);
    // this->setCursor(cursor);
    QPixmap pixmap(":/LangChain.png");
    // 对原有图片进行缩放，但具体是通过对拷贝的对象进行操作
    pixmap = pixmap.scaled(100,100);
    QCursor cursor(pixmap,10,10);
    this->setCursor(cursor);
}

Widget::~Widget()
{
    delete ui;
}
