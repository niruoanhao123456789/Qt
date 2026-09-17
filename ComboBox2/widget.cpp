#include "widget.h"
#include "ui_widget.h"
#include <fstream>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    std::ifstream file("D:/code/Qt/ComboBox2/1.txt");
    if(!file.is_open())
        return;
    std::string line;
    while(std::getline(file,line))
    {
        ui->comboBox->addItem(QString::fromStdString(line));
    }
    file.close();

}

Widget::~Widget()
{
    delete ui;
}
