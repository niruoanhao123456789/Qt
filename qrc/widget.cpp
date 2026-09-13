#include "widget.h"
#include "ui_widget.h"
#include <QIcon>
#include <QDir>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 利用qrc资源来设置图标
    QIcon icon(":/LangChain.png");
    this->setWindowIcon(icon);
}

Widget::~Widget()
{
    delete ui;
}
