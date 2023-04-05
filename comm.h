//
// Created by m.batailler on 31/03/2023.
//

#ifndef PROJET_COMM_COMM_H
#define PROJET_COMM_COMM_H

#pragma once
#include <iostream>
#include <winsock2.h>
#include <string>
#include <fstream>

struct sockaddr_in infoClient;
struct hostent* hs;
struct in_addr adrIp;
struct sockaddr_in adr_serveur;
SOCKET IdSoket;

class comm {
private:
    char* ServeurName;
    int PortServeur;
    int PortSortie;
    int lg;
    char AddrIP[16];
    char AdrIP[16];

    void startComm();

public:
    comm(char *serveur, int numPort, int portSortie);

    void communication(char* , int);

    void InitComm();

    int endComm();

    int receive(void *message, int maxLenght);

    int sending(void *message, int taille);
};


#endif //PROJET_COMM_COMM_H
