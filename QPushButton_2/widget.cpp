#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->target->setIcon(QIcon(":/image/icon.png"));
    ui->target->setIconSize(QSize(50,50));

    ui->pushButton_up->setIcon(QIcon(":/image/arrow_up.png"));
    ui->pushButton_up->setIconSize(QSize(10,10));

    ui->pushButton_down->setIcon(QIcon(":/image/arrow_down.png"));
    ui->pushButton_down->setIconSize(QSize(10,10));

    ui->pushButton_left->setIcon(QIcon(":/image/arrow_left.png"));
    ui->pushButton_left->setIconSize(QSize(10,10));

    ui->pushButton_right->setIcon(QIcon(":/image/arrow_right.png"));
    ui->pushButton_right->setIconSize(QSize(10,10));

    // ui->pushButton_up->setShortcut(QKeySequence("w"));
    // ui->pushButton_down->setShortcut(QKeySequence("s"));
    // ui->pushButton_left->setShortcut(QKeySequence("a"));
    // ui->pushButton_right->setShortcut(QKeySequence("d"));

    ui->pushButton_up->setShortcut(QKeySequence(Qt::Key_W));
    ui->pushButton_down->setShortcut(QKeySequence(Qt::Key_S));
    ui->pushButton_left->setShortcut(QKeySequence(Qt::Key_A));
    ui->pushButton_right->setShortcut(QKeySequence(Qt::Key_D));
    ui->pushButton->setShortcut(QKeySequence(Qt::Key_Control+Qt::Key_S));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_left_clicked()
{
    QRect rect = ui->target->geometry();
    ui->target->setGeometry(rect.x()-5,rect.y(),rect.width(),rect.height());
}


void Widget::on_pushButton_right_clicked()
{
    QRect rect = ui->target->geometry();
    ui->target->setGeometry(rect.x()+5,rect.y(),rect.width(),rect.height());
}


void Widget::on_pushButton_up_clicked()
{
    QRect rect = ui->target->geometry();
    ui->target->setGeometry(rect.x(),rect.y()-5,rect.width(),rect.height());
}


void Widget::on_pushButton_down_clicked()
{
    QRect rect = ui->target->geometry();
    ui->target->setGeometry(rect.x(),rect.y()+5,rect.width(),rect.height());
}


void Widget::on_pushButton_clicked()
{
    ui->target->move(0,0);
}

