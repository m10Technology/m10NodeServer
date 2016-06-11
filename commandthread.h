#ifndef COMMANDTHREAD_H
#define COMMANDTHREAD_H

#include <server.h>
#include <QThread>
#include <m10thread.h>

class CommandThread : public QThread
{
public:
    CommandThread(Server &s);
    void run();
    void update();
signals:
    void commandExecuted(std::string command);
public slots:

private:
    Server server;

};

#endif // COMMANDTHREAD_H
