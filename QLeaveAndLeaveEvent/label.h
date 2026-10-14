#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QWidget>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget *parent = nullptr);

    void leaveEvent(QEvent*) ;
    void enterEvent(QEnterEvent* );
};

#endif // LABEL_H
