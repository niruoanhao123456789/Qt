#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    std::shared_ptr<QIcon> icon = std::make_shared<QIcon>(":/icon.png");
    ui->pushButton->setIcon(*icon);
    ui->pushButton->setIconSize(QSize(50,50));

}

Widget::~Widget()
{
    delete ui;
}
