#ifndef CLIENT_H
#define CLIENT_H
#include <QString>

class Client
{
public:
   Client(QString name,QString address,QString id);

private:
    QString mName;
    QString mAddress;
    QString mID;
};

#endif // CLIENT_H
