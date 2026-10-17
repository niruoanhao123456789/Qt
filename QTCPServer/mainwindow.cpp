#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("服务器");

    tcpServer = new QTcpServer(this);

    connect(tcpServer,&QTcpServer::newConnection,this,&MainWindow::ConnectionHandle);

    bool ret = tcpServer->listen(QHostAddress::AnyIPv4,8080);
    if(!ret)
    {
        QMessageBox::critical(this,"服务器启动失败",tcpServer->errorString());
        exit(1);
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

QString MainWindow::handle(const QString req)
{
    return req;
}

void MainWindow::ConnectionHandle()
{
    // 通过tcpServer获取一个socket对象，通过这个对象和客户端进行通信
    QTcpSocket* clientSocket = tcpServer->nextPendingConnection();
    QString message = "[" + clientSocket->peerAddress().toString() + ":" +QString::number(clientSocket->peerPort()) + "] 客户端上线！";
    ui->listWidget->addItem(message);

    // 通过信号槽来处理客户端发来的请求
    connect(clientSocket,&QTcpSocket::readyRead,this,[=](){
        // 读取出请求数据. 此处 readAll 返回的是 QByteArray, 通过赋值转成 QString
        QString request = clientSocket->readAll();
        // 根据请求处理响应
        const QString& response = handle(request);
        // 把响应写到客户端
        clientSocket->write(response.toUtf8());
        // 打印日志消息
        QString message = "[" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "]"
                          + "req: " + request + ", resp: " + response;
        ui->listWidget->addItem(message);
    });

    // 通过信号槽，来处理客户端断开链接的情况
    connect(clientSocket,&QTcpSocket::disconnected,this,[=](){
       // 将断开链接的消息通过日志显示出来
        QString message = "[" + clientSocket->peerAddress().toString() + ":" + QString::number(clientSocket->peerPort()) + "] 客户端下线!";
        ui->listWidget->addItem(message);

        // 手动释放 clientSocket. 直接使用 delete 是下策, 使用 deleteLater 更加合适的.
        // delete clientSocket;
        clientSocket->deleteLater();
    });

}
