#include "label.h"


Label::Label(QWidget* parent) : QLabel(parent)
{

}

void Label::leaveEvent(QEvent*)
{
    qDebug() << "leaveEvent";
}

void Label::enterEvent(QEnterEvent* )
{
    qDebug() << "enterEvent";
}
