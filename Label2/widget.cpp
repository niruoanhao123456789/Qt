#include "widget.h"
#include "ui_widget.h"
#include <QResizeEvent>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QRect rect = this->geometry();
    ui->label->setGeometry(0,0,rect.width(),rect.height());

    QPixmap pixmap(":/icon.png");
    ui->label->setPixmap(pixmap);

    // 启动Lable的拉伸
    ui->label->setScaledContents(true);
}

void Widget::resizeEvent(QResizeEvent* event)
{
    qDebug()<<event->size();
    ui->label->setGeometry(0,0,event->size().width(),event->size().height());
}

Widget::~Widget()
{
    delete ui;
}
