#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    srand(time(nullptr));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_accpet_clicked()
{
    ui->label->setText("请速速转账！谢谢惠顾~");
}


void Widget::on_pushButton_reject_clicked()
{
    int height = this->geometry().height();
    int width = this->geometry().width();

    int x = rand() % width;
    int y = rand() % height;

    ui->pushButton_reject->move(x,y);
}


void Widget::on_pushButton_reject_pressed()
{

    ui->label->setText("这样不行哦宝宝。:(");
}

