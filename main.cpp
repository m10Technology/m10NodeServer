#include <QCoreApplication>
#include <server.h>
#include <QList>
#include <commandthread.h>
#include <client.h>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server mServe;
    mServe.StartServer();

    CommandThread *mThread = new CommandThread(mServe);
   // mServe.passThread(mThread);

    mThread->start();

    return a.exec();
}

