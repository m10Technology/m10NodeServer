#ifndef SERVER_H
#define SERVER_H

#include <QTcpServer>
#include <QDebug>

class Server : public QTcpServer
{
    Q_OBJECT
public:

    void removeClient(int id);
    explicit Server(QObject *parent = 0);
    void StartServer();
    void execCommand(std::string data);
    void printIP(int mSocket, QString ip);
    void viewSlaveNodes();
signals:

public slots:

private:


protected:
    void incomingConnection(qintptr socketDescriptor);

};

#endif // SERVER_H
