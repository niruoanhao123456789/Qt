#ifndef DIALOG_H
#define DIALOG_H


#include <QDialog>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

class Dialog : public QDialog
{
    Q_OBJECT
public:
    Dialog(QWidget* parent);

    void handle();
};

#endif // DIALOG_H
