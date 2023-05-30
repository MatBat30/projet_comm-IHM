#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include "gestion.h"
#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;


class donnee {
private:
    // Vecteurs pour stocker les paramètres de l'image,adresse IP des raspberry et de l'animation
    vector<int> paramImage;
    vector<string> paramAnimation;

    // Vecteur pour stocker le message
    vector<char> message;

    // Variables pour stocker la largeur et la hauteur du mur
    int widthWall;
    int heightWall;
    // Variables pour stocker les noms de variables et autres informations
    string nomVariable;
    std::string nom;
    std::string numeroecr;

public:
    // Fonction pour récupérer les données à partir d'un fichier
    vector<char> getData(const string& fileName);
    // Fonction pour créer un bloc d'image avec des paramètres spécifiés
    string createImageBlock(int id, const string& posX, const string& posY,
                            const string& heightImage, const string& widthImage,
                            const string& numberPixel,
                            const string& rotationSpeed, const string& rotationDirection,
                            const string& rotationAxis, const string& translationSpeed,
                            const string& translationDirection);

    // Fonction pour écrire les données dans un fichier
    void writeData(int numberScreen);
    // Fonction pour définir les données avec des paramètres spécifiés
    void setData(parametresImage inputImgParams, parametresAnimation inputAnimParams);

};

#endif //PROJET_COMM_DONNEE_H
