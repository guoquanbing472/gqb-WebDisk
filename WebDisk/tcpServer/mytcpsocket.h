#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H

#include <QTcpSocket>
#include "protocol.h"
#include "opedb.h"
#include <QDir>
#include <QFile>
#include <QTimer>

class MyTcpSocket : public QTcpSocket
{
    Q_OBJECT
public:
    MyTcpSocket();
    QString getName();
    //递归复制文件
    void copyDir(QString strSrcDir, QString strDestDir);

signals:
    //离线信号
    void offline(MyTcpSocket *mysocket);

public slots:
    void recvMsg();
    //处理客户端关闭，数据库更改在线标志为0
    void clientOffline();
    //向客户端发送文件
    void sendFileToClient();

private:
    QString m_strName;
    QFile m_file;
    qint64 m_iTotal;
    qint64 m_iReceived;
    bool m_bUpload;

    QTimer *m_pTimer;

};

#endif // MYTCPSOCKET_H
