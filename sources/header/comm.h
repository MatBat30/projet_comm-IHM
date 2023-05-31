// Le fichier d'en-tête définit la classe "comm" qui gère la communication avec le serveur.
#ifndef PROJET_COMM_COMM_H
#define PROJET_COMM_COMM_H

// Inclusion des bibliothèques nécessaires
#include "gestion.h"

#include <iostream>
#include <WinSock2.h>
#include <string>
#include <fstream>
#include <vector>

// Utilisation de l'espace de noms standard
using namespace std;

// Déclaration de la classe "comm"
class comm {
public:
    // Fonction d'initialisation des paramètres de communication
    int init();

    // Fonction de connexion au serveur
    int connectToServer();

    // Fonction pour envoyer un message (nom de fichier) au serveur
    void sendMessage(vector<char> nomFichier);

    // Fonction pour envoyer l'extension du fichier au serveur
    void sendExtension(char *extension);

    // Fonction pour fermer la connexion avec le serveur
    void closeConnection();

    // Fonction pour recevoir un message du serveur
    void receiveMessage();

    // Fonction pour envoyer la taille du fichier (image) au serveur
    unsigned int sendSize(vector<char>);

private:
    // Variables membres privées
    int imageSize; // Taille de l'image
    int fileSize; // Taille du fichier
    // char * adrIP; // Adresse IP du serveur (commentée)

    int port; // Numéro de port pour la connexion

    // Structure contenant les informations sur l'adresse du serveur
    struct sockaddr_in serverAddress;

    // Socket pour la connexion avec le serveur
    SOCKET clientSocket;
};

#endif //PROJET_COMM_COMM_H
