#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QNetworkReply>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("客户端");
    manager = new QNetworkAccessManager(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    // 获取输入框中的 url
    QUrl url(ui->lineEdit->text());

    // 构造HTTP请求对象
    QNetworkRequest request(url);

    // 发送请求
    QNetworkReply* response = manager->get(request);

    // 通过信号槽来处理响应

    connect(response,&QNetworkReply::finished,this,[=](){
        if(response->error() == QNetworkReply::NoError)
        {
            // 获取到正确响应
            QString html = response->readAll();
            ui->plainTextEdit->setPlainText(html);
        }
        else
        {
            ui->plainTextEdit->setPlainText(response->errorString());
        }

        response->deleteLater();
    });
}

