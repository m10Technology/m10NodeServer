#include "server.h"
#include <iostream>
#include <m10thread.h>
#include <QList>
#include <QPointer>

Server::Server(QObject *parent) :
    QTcpServer(parent)
{
}

int currentThread =0;
QList<QPointer<m10Thread> > m10Threads;

void Server::StartServer()
{
    if(!this->listen(QHostAddress::Any,8085))
    {
        qDebug() << "Could not start server";
    }
    else
    {
        qDebug() << "Listening...";
    }

}


void Server::execCommand(std::string data)
{
    QByteArray myData = QByteArray::fromStdString(data);
    m10Threads.at(0).data()->writeData(&myData);
}

void Server::printIP(int mSocket, QString ip){

}

void Server::viewSlaveNodes()
{


    qDebug() << "You have " << m10Threads.length() <<  " slave nodes connected.";
    qDebug() << "---Connected m10Nodes----";

    for(int i=0;i<m10Threads.length();i++){
        qDebug() << m10Threads.at(i).data()->getm10ID() << "\t" << m10Threads.at(i).data()->getSystemName();
    }


}



void Server::removeClient(int id)
{
     for(int i=0; i<1024;i++){
        if(m10Threads.value(i).data()->getm10ID() == id){
            qDebug() << "Removing ID " << id << "at element " << i << endl;
            m10Threads.removeAt(i);
            return;
        }
    }

}


void Server::incomingConnection(qintptr socketDescriptor)
{

    qDebug() << socketDescriptor << " Connecting...";
    QPointer<m10Thread> p(new m10Thread(socketDescriptor,this));
    connect(p.data(), SIGNAL(finished()),p.data(), SLOT(deleteLater()));
    p.data()->setServer(this);
    p.data()->start();
    m10Threads.append(p);
}
