#include "widget.h"
#include "ui_widget.h"
#include <QButtonGroup>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->lineEdit_name->setPlaceholderText("请输入姓名");
    ui->lineEdit_name->setClearButtonEnabled(true);

    ui->lineEdit_password->setPlaceholderText("请输入姓名");
    ui->lineEdit_password->setClearButtonEnabled(true);
    ui->lineEdit_password->setEchoMode(QLineEdit::Password);

    QButtonGroup* group = new QButtonGroup(this);
    group->addButton(ui->radioButton_male);
    group->addButton(ui->radioButton_female);

    ui->lineEdit_phnoe->setPlaceholderText("请输入手机号码");
    ui->lineEdit_phnoe->setClearButtonEnabled(true);
    ui->lineEdit_phnoe->setInputMask("000-0000-0000");

}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_submit_clicked()
{
    QString gender;
    if(ui->radioButton_male->isChecked())
        gender = "男";
    else if(ui->radioButton_female->isChecked())
        gender = "女";
    else
        gender = "";
    qDebug()<<"姓名："<<ui->lineEdit_name->text()<<"\n"
            <<"性别："<<gender<<"\n"
            <<"密码："<<ui->lineEdit_password->text()<<"\n"
            <<"电话："<<ui->lineEdit_phnoe->text();
}

