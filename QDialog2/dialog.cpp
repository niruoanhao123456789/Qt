#include "dialog.h"

Dialog::Dialog(QWidget* parent) : QDialog(parent)
{
    // 创建出一些控件来加入到Dialog中（以Dialog作为父窗口）

    QVBoxLayout* layout = new QVBoxLayout();
    this->setLayout(layout);

    QLabel* label = new QLabel("这是一个对话框",this);
    QPushButton* button = new QPushButton("这是一个按钮",this);
    layout->addWidget(label);
    layout->addWidget(button);

    connect(button,&QPushButton::clicked,this,&Dialog::handle);

}

void Dialog::handle()
{
    this->close();
}