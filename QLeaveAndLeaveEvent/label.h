#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QWidget>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr);

    void enterEvent(QEnterEvent* event) ;
    void leaveEvent(QEvent* event) ;
};

#endif // LABEL_H
