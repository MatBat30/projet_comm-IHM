#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// Structure pour stocker les paramètres de l'image
struct parametresImage {
    int posX;
    int posY;
    int heightImage;
    int widthImage;
    int ratio;
    int numberPixel;
};

// Structure pour stocker les paramètres de l'animation
struct parametresAnimation {
    string rotationSpeed;
    string rotationDirection;
    string rotationAxis;
    string translationSpeed;
    string translationDirection;
};

class donnee {
private:
    // Vecteurs pour stocker les paramètres de l'image,adresse IP des raspberry et de l'animation
    vector<int> paramImage;
    vector<string> paramAnimation;
    vector<string> addresseMacRaspberry;
    string addresseMacIntermediaire;

    // Vecteur pour stocker le message
    vector<char> message;
    // Instances des structures pour stocker les paramètres
    parametresImage Image{};
    parametresAnimation animation{};
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
                            const string& ratio, const string& numberPixel,
                            const string& rotationSpeed, const string& rotationDirection,
                            const string& rotationAxis, const string& translationSpeed,
                            const string& translationDirection);

    // Fonction pour écrire les données dans un fichier
    void writeData(int numberScreen);
    void setAddresseIntermediaire(const string& addresseIntermediaire_);
    // Fonction pour définir les données avec des paramètres spécifiés
    void setData(int id, int posX, int posY, int heightImage, int widthImage, int ratio,
                 int numberPixel, int widthWall, int heightWall,
                 string rotationSpeed_ = "NULL", string rotationDirection_ = "NULL",
                 string rotationAxis_ = "NULL", string translationSpeed_ = "NULL",
                 string translationDirection_ = "NULL");

    void setMacAddress(const string &macAddress_);
};

#endif //PROJET_COMM_DONNEE_H
