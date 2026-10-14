#ifndef LABEL_H
#define LABEL_H

#include <QLabel>
#include <QWidget>
#include <QMouseEvent>

class Label : public QLabel
{
    Q_OBJECT
public:
    Label(QWidget* parent);

    void mousePressEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    void mouseDoubleClickEvent(QMouseEvent* event);

};

#endif // LABEL_H
