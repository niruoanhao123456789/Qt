#include "mainwindow.h"
#include "ui_mainwindow.h"

const QString& server_ip = "127.0.0.1";
const quint16 defalut_port = 8080;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);

    this->setWindowTitle("客户端");

    connect(socket,&QUdpSocket::readyRead,this,&MainWindow::processResponse);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // 获取输入框的内容
    const QString& text = ui->lineEdit->text();
    // 构造UDP的请求数据
    QNetworkDatagram requestDatagram(text.toUtf8(),QHostAddress(server_ip),defalut_port);
    // 发送请求数据
    socket->writeDatagram(requestDatagram);
    // 把发送的请求添加到列表框中
    ui->listWidget->addItem("Client says: "+text);
    // 将输入框内容清空
    ui->lineEdit->setText("");
}

void MainWindow::processResponse()
{
    // 读取到的响应数据
    const QNetworkDatagram& responseDatagram = socket->receiveDatagram();
    QString response = responseDatagram.data();

    // 将响应数据显示到界面上
    ui->listWidget->addItem("Server says: " + response);
}

