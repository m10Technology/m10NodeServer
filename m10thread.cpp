#include "m10thread.h"


bool m10Thread::getIsConnected()
{
    if(this->isConnected){
        return true;
    }
    else{
        return false;
    }
}

QString m10Thread::getSystemName()
{
    return QString("TEMP_CPU_NAME");\
}

int m10Thread::getm10ID()
{
    return socketDescriptor;
}

void m10Thread::setServer(Server *serverParent)
{
    mServer = serverParent;
}

m10Thread::m10Thread(int ID, QObject *parent) :
    QThread(parent)
{
    this->isConnected = true;
    this->socketDescriptor = ID;
}

void m10Thread::run()
{
    //thread starts here
    socket = new QTcpSocket();
    socket->moveToThread(QThread::currentThread());
    //qDebug() << "Socket is " << socket << endl;
    if(!socket->setSocketDescriptor(this->socketDescriptor))
    {
        emit error(socket->error());
        return;
    }

    connect(socket,SIGNAL(readyRead()),this,SLOT(readyRead()),Qt::DirectConnection);
    connect(socket,SIGNAL(disconnected()),this,SLOT(disconnected()),Qt::DirectConnection);

    qDebug() << " Client Connected with connection ID " << socketDescriptor;

    exec();
}

void m10Thread::readyRead()
{
    QByteArray Data = socket->readAll();
    qDebug() << "Data in " << Data;

}

void m10Thread::disconnected()
{
    qDebug() << socketDescriptor << " Disconnected";
    mServer->removeClient(socketDescriptor);
    socket->deleteLater();
}


void m10Thread::populateThreadInfo()
{
    writeData(new QByteArray("getSys"));

}


void m10Thread::getIP()
{
    QByteArray *d = new QByteArray("getIP");
    writeData(d);
    delete d;
}

bool m10Thread::writeData(QByteArray *data)
{
    if(socket->state() == QAbstractSocket::ConnectedState)
       {
           socket->write(*data); //write the data itself
           return socket->waitForBytesWritten();
       }
       else
           return false;
}

