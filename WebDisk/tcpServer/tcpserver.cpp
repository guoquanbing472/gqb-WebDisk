#include "tcpserver.h"
#include "ui_tcpserver.h"
#include <QByteArray>
#include <QDebug>
#include <QMessageBox>
#include <QHostAddress>
#include <QFile>
#include "mytcpserver.h"

tcpServer::tcpServer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::tcpServer)
{
    ui->setupUi(this);
    loadConfig();

    MyTcpServer::getInstance().listen(QHostAddress(m_strIP), m_usPort);
}

tcpServer::~tcpServer()
{
    delete ui;
}

void tcpServer::loadConfig()
{
    QFile file(":/server.config");
    if(file.open(QIODevice::ReadOnly))
    {
        QByteArray baData = file.readAll();//将整个文件的内容读取到 QByteArray 中，QByteArray 是一个用于存储字节数组的类
        QString strData = baData.toStdString().c_str();
        file.close();
        strData.replace("\r\n"," ");
        QStringList strList =  strData.split(" ");
        m_strIP = strList.at(0);
        m_usPort = strList.at(1).toUShort();
        qDebug() << "IP:" << m_strIP << "port:" << m_usPort;
    }
    else
    {
        QMessageBox::critical(this, "open config", "open config failed");
    }
}

