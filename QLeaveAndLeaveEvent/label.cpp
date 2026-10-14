#include "label.h"


Label::Label(QWidget* parent) : QLabel(parent)
{

}

void Label::enterEvent(QEnterEvent*)
{
    qDebug() << "enterEvent";
}

void Label::leaveEvent(QEvent*)
{
    qDebug() << "leaveEvent";
}
