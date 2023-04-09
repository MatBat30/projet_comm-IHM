#ifndef PROJET_COMM_COMM_H
#define PROJET_COMM_COMM_H

#include <iostream>
#include <winsock2.h>
#include <string>
#include <fstream>
#include <vector>



class comm {
    public:
    int init();

    int connectToServer();

    void sendMessage(std::vector<char> nomFichier);

    void closeConnection();

    void receiveMessage();
    void sendSize(std::vector<char>);
    private:
    int imageSize;
    //char * adrIP;

    int port;

    struct sockaddr_in serverAddress;

    SOCKET clientSocket;



};


#endif //PROJET_COMM_COMM_H
