#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    socket = new QUdpSocket(this);

    this->setWindowTitle("服务器");

    connect(socket,&QUdpSocket::readyRead,this,&MainWindow::processRequest);

    bool ret = socket->bind(QHostAddress::AnyIPv4,8080);
    if(!ret)
    {
        QMessageBox::critical(this,"服务器端口号绑定出错",socket->errorString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

// 请求处理
void MainWindow::processRequest()
{
    // 读取请求并解析
    const QNetworkDatagram& requestDatagram = socket->receiveDatagram();
    QString request = requestDatagram.data();
    // 根据请求计算响应.由于是回显服务器. 响应不需要计算, 就是请求本身
    const QString& response = process(request);
    // 将响应回写回客户端
    QNetworkDatagram responseDatagram(response.toUtf8(),requestDatagram.senderAddress(),requestDatagram.senderPort());
    socket->writeDatagram(responseDatagram);
    // 将此次交互信息显示到页面上
    QString log = "[" + requestDatagram.senderAddress().toString() + ":" +QString::number(requestDatagram.senderPort())
                  + "] req: " + request + ", resp: " + response;
    ui->listWidget->addItem(log);

}

QString MainWindow::process(const QString& req)
{
    // 由于当前是回显服务器, 响应就是和请求完全一样.
    // 对于一个成熟的商业服务器, 这里请求->响应的计算过程可能是非常复杂的. (业务逻辑).
    return req;
}