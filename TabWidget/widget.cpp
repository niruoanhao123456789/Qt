#include "widget.h"
#include "ui_widget.h"
#include <QLabel>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QLabel* label1 = new QLabel(ui->tab);
    label1->setText("标签页1");
    label1->resize(100,50);

    QLabel* label2 = new QLabel(ui->tab);
    label2->setText("标签页2");
    label2->resize(100,50);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_clicked()
{
    int count = ui->tabWidget->count();
    QWidget* widget = new QWidget();
    ui->tabWidget->addTab(widget,QString("Tab ")+QString::number(count+1));

    QLabel* label = new QLabel(widget);
    label->setText("标签页 "+QString::number(count+1));
    label->resize(100,50);

    ui->tabWidget->setCurrentIndex(count);
}


void Widget::on_pushButton_2_clicked()
{
    int index = ui->tabWidget->currentIndex();
    ui->tabWidget->removeTab(index);
}

