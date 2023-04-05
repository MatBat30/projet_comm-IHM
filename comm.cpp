//
// Created by m.batailler on 31/03/2023.
//

#include <cstring>
#include "comm.h"
#pragma comment(lib, "ws2_32.lib")

comm::comm(char* serveur, int numPort, int portSortie) {
    ServeurName = new char[strlen(serveur) + 1];
    strcpy(ServeurName, serveur);
    PortServeur = numPort;
    PortSortie = portSortie;
    InitComm();
}

void comm::InitComm() {

    WSADATA wsaData;

    lg = sizeof (adr_serveur);

    WSAStartup(MAKEWORD(2,0), &wsaData);

    IdSoket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    if (IdSoket == INVALID_SOCKET) {
        printf("le socket a echoué avec l'erreur : %d\n", WSAGetLastError());
        WSACleanup();
    }else
    {
        printf("socket initialiser \n");
    }
    infoClient.sin_family = AF_INET;
    infoClient.sin_port = htons(PortSortie);
    infoClient.sin_addr.s_addr = INADDR_ANY;

    bind (IdSoket, (sockaddr*)&infoClient , sizeof ( infoClient));

    if ((hs = gethostbyname(ServeurName)) == NULL)
    {
        if((hs=gethostbyaddr(ServeurName,4,2))==NULL)
        {
            exit(4);
        }
    }

    delete[] ServeurName;
    ServeurName = new char[strlen(hs->h_name)];
    strcpy(ServeurName, hs->h_name);

    memcpy(&adrIp,hs->h_addr, hs->h_length);
    strcpy(AddrIP, inet_ntoa(adrIp));

    adr_serveur.sin_family = AF_INET;
    adr_serveur.sin_port = htons(PortServeur);
    adr_serveur.sin_addr.s_addr = inet_addr(AdrIP);

    startComm();

}

void comm::startComm() {
    if (connect(IdSoket, (struct sockaddr*)&adr_serveur, sizeof (adr_serveur)) == SOCKET_ERROR) {
        printf("la connexion a echoué avec l'erreur : %d\n", WSAGetLastError());
        closesocket(IdSoket);
        WSACleanup();
    }else
    {
        printf("message envoyer \n");
    }

}

int comm::sending(void* message, int taille) {
    int NbOctetsEcrits;
    NbOctetsEcrits = send(IdSoket, (char*) message, taille, 0);
    if (NbOctetsEcrits == SOCKET_ERROR) {
        printf("l'envoie a echoué avec l'erreur: %d\n", WSAGetLastError());
        endComm();
        return 1;
    } else
    {
        printf("message envoyer \n");
    }

    return 0;
}

int comm::receive(void* message,int maxLenght) {
    int NbOctetsLus;
    NbOctetsLus= recv(IdSoket, (char*)message, maxLenght, 0);

    if (NbOctetsLus == SOCKET_ERROR) {
        printf("la reception a echoué avec l'erreur: %d\n", WSAGetLastError());
        endComm();
        return 1;
    }
    else
    {
        printf("message reçu \n");
    }
    return 0;
}


int comm::endComm() {
    closesocket(IdSoket);
    WSACleanup();
    std::cout<<"Communication fermée"<<std::endl;
    return 0;
}