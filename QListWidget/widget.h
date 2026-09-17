#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget() override;

private slots:
    void on_listWidget_currentItemChanged(QListWidgetItem *current, QListWidgetItem *previous);

    void on_pushButton_add_clicked();

    void on_pushButton_take_clicked();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
