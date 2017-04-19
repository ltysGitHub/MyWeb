#ifndef MTCPSOCKET_H
#define MTCPSOCKET_H
#include<QtNetwork/QTcpSocket>
#include<QRegExp>
#include<QStringList>
#include<qdebug.h>
#define ATTR_GET 0
#define ATTR_CONNECTION 1
#define ATTR_ACCEPT 2
#define ATTR_REFERER 3
class MTcpSocket:public QTcpSocket{
    Q_OBJECT
public:
    int threadId;
    MTcpSocket(qintptr socketDescriptor,int threadId);
    QStringList* GetUrlFrom(QString HttpHeader);
    bool CheckUrl(QString Url);
//    QString DecodeHttp(QString httpCon);
public slots:
    void response();
    void sendmDis();
signals:
    void mDisconnect(int);  //tcp链接已断开时发送此信号，在主线程中接收，传递当前连接的子线程在线程池中的编号，以便回收线程资源。
};

#endif // MTCPSOCKET_H
