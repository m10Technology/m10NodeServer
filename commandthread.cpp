#include "commandthread.h"
#include <stdlib.h>
#include <iostream>



CommandThread::CommandThread(Server &s)
{

}



void CommandThread::run()
{
    update();
    std::string myCommand;

    while(true){

        std::getline(std::cin,myCommand);
        QString myCommandString = QString::fromStdString(myCommand);

        QString args[128];
        for(int i=0; i<128;i++){
            args[i] = myCommandString.section(" ", i, i, QString::SectionSkipEmpty);
        }

        if(args[0] == "exit" || args[0] == "quit"){
            exit(0);
        }
        else if(args[0] == "viewSlaveNodes"){
            server.viewSlaveNodes();
        }
        else if(args[0] == "disconnect"){
            int i = args[1].toInt();
            server.removeClient(i);
        }
        else if(args[0] == "exec"){
         int i = args[1].toInt();
         std::string command = "";
         for(int i=2; i<128;i++){
             command = command+args[i].toStdString() + " ";
         }
         server.execCommand(command);
        }
        update();
    }
}

void CommandThread::update()
{
    std::cout << "m10NodeServer$ ";
}

