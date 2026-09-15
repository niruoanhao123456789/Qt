#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QButtonGroup* group1 = new QButtonGroup(this);
    QButtonGroup* group2 = new QButtonGroup(this);
    QButtonGroup* group3 = new QButtonGroup(this);

    group1->addButton(ui->radioButton_h1);
    group1->addButton(ui->radioButton_h2);
    group1->addButton(ui->radioButton_h3);

    group2->addButton(ui->radioButton_y1);
    group2->addButton(ui->radioButton_y2);
    group2->addButton(ui->radioButton_y3);

    group3->addButton(ui->radioButton_z1);
    group3->addButton(ui->radioButton_z2);
    group3->addButton(ui->radioButton_z3);

}

Widget::~Widget()
{
    delete ui;
}
