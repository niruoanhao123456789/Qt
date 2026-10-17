#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    socket = new QTcpSocket(this);

    socket->connectToHost("127.0.0.1",8080);

    connect(socket,&QTcpSocket::readyRead,this,[=](){
        QString response = socket->readAll();
        ui->listWidget->addItem("Server says: " + response);
    });

    bool ret = socket->waitForConnected();
    if(!ret)
    {
        QMessageBox::critical(this,"连接服务器出错",socket->errorString());
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    const QString& text = ui->lineEdit->text();
    socket->write(text.toUtf8());
    ui->listWidget->addItem("Client says: " + text);
    ui->lineEdit->setText("");
}

