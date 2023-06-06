#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include "structureDonnee.h"
#include "json.hpp"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class donnee {
private:
    vector<int> paramImage;
    vector<string> paramAnimation;
    parametresDictionaire paramDictionnaire;

    vector<parametresImage> imageSet;
    vector<parametresAnimation> animationSet;
    parametresDictionaire dictionarySet;

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
    vector<char> getData(const string &fileName);

    // Fonction pour écrire les données dans un fichier
    void writeData(int numberScreen);

    void setData(vector<parametresImage>, vector<parametresAnimation>, parametresDictionaire);

    static string getFileExtension(const string &filePath);

    vector<char> getJsonData();
};

#endif //PROJET_COMM_DONNEE_H
