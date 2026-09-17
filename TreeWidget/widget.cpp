#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    ui->treeWidget->setHeaderLabel("动物");

    // 无法持久化
    // 新增顶层节点
    QTreeWidgetItem* item1 = new QTreeWidgetItem();
    item1->setText(0,"猫");
    ui->treeWidget->addTopLevelItem(item1);

    QTreeWidgetItem* item2 = new QTreeWidgetItem();
    item2->setText(0,"狗");
    ui->treeWidget->addTopLevelItem(item2);

    QTreeWidgetItem* item3 = new QTreeWidgetItem();
    item3->setText(0,"鸟");
    ui->treeWidget->addTopLevelItem(item3);

    // 添加子节点
    QTreeWidgetItem* citem1 = new QTreeWidgetItem();
    citem1->setText(0,"中华田园猫");
    item1->addChild(citem1);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_pushButton_addtop_clicked()
{
    const QString& text = ui->lineEdit->text();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0,text);
    ui->treeWidget->addTopLevelItem(item);
}


void Widget::on_pushButton_addcur_clicked()
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(!currentItem)
        return;
    const QString& text = ui->lineEdit->text();
    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setText(0,text);
    currentItem->addChild(item);
}


void Widget::on_pushButton_removecur_clicked()
{
    QTreeWidgetItem* currentItem = ui->treeWidget->currentItem();
    if(!currentItem)
        return;
    // 要删除选中的元素要先获取他的父节点，通过父节点来删除。
    QTreeWidgetItem* parent = currentItem->parent();
    if(!parent)
    {
        int index = ui->treeWidget->indexOfTopLevelItem(currentItem);
        ui->treeWidget->takeTopLevelItem(index);
    }
    else
    {
        parent->removeChild(currentItem);
    }
}

