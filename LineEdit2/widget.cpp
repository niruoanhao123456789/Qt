#include "widget.h"
#include "ui_widget.h"
#include <QRegularExpressionValidator>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 正则表达式来验证输入格式
    QRegularExpression regexp("^1\\d{10}$");
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regexp));
    ui->lineEdit->setPlaceholderText("请输入10位数字");
    ui->lineEdit->setClearButtonEnabled(true);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_lineEdit_textEdited(const QString &arg1)
{
    QString arg = arg1;
    int pos = 0;
    if(ui->lineEdit->validator()->validate(arg,pos)== QRegularExpressionValidator::Acceptable)
        ui->pushButton->setEnabled(true);
    else
        ui->pushButton->setEnabled(false);
}

