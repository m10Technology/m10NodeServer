#ifndef M10THREAD_H
#define M10THREAD_H

#include <QThread>
#include <QTcpSocket>
#include <QDebug>
#include "server.h"

class m10Thread : public QThread
{
    Q_OBJECT
public:
    void discon();
    bool getIsConnected();
    QString getSystemName();
    int getm10ID();
    void setServer(Server *serverParent);
    explicit m10Thread(int ID, QObject *parent = 0);
    void run();
    bool writeData(QByteArray *data);
signals:
    void error(QTcpSocket::SocketError socketerror);

public slots:
    void readyRead();
    void disconnected();


public slots:

private:

    int uniqueID;
    int ipv4Address;
    int publicAddress;
    QString systemName;

    bool isConnected;
    void populateThreadInfo();
    void getIP();
    QTcpSocket *socket;
    int socketDescriptor;
    Server *mServer;
};

#endif // M10THREAD_H
