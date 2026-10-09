#include "widget.h"
#include "ui_widget.h"
#include <QPushButton>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 设置一个三行两列的表单
    QFormLayout* layout = new QFormLayout();
    this->setLayout(layout);

    // 第一列
    QLabel* label1 = new QLabel("姓名");
    QLabel* label2 = new QLabel("年龄");
    QLabel* label3 = new QLabel("电话");

    // 第二列
    QLineEdit* edit1 = new QLineEdit();
    QLineEdit* edit2 = new QLineEdit();
    QLineEdit* edit3 = new QLineEdit();

    layout->addRow(label1,edit1);
    layout->addRow(label2,edit2);
    layout->addRow(label3,edit3);

    // 新增提交按钮
    QPushButton* button = new QPushButton("提交");
    layout->addRow(nullptr,button);
}

Widget::~Widget()
{
    delete ui;
}
