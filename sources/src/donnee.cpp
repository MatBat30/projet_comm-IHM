#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "../header/donnee.h"
#include "../header/json.hpp"

nlohmann::json j;

// Fonction pour lire les données d'un fichier et les stocker dans un std::vector<char>
vector<char> donnee::getData(const std::string &nomFichier) {
    std::string fileName = nomFichier;

    // Ouvrir le fichier en mode binaire
    std::ifstream fichier(fileName, std::ios::binary);

    // Vérifier si le fichier est ouvert correctement
    if (!fichier.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier : " << fileName << std::endl;
        return std::vector<char>(); // Retourner un vecteur vide en cas d'erreur
    }

    // Lire le contenu du fichier dans un std::vector<char>
    std::vector<char> contenuFichier((std::istreambuf_iterator<char>(fichier)), std::istreambuf_iterator<char>());

    // Fermer le fichier
    fichier.close();

    return contenuFichier;
}

void donnee::setData(vector <parametresImage> inputImgParams, vector <parametresAnimation> inputAnimParams, int numberScreen_ ){

    imageSet = inputImgParams;
    animationSet = inputAnimParams;

}

void donnee::writeData(int numberOfScreens) {
    cout << "nombre d'ecrant: " << numberOfScreens<< endl;
    cout<< "imageSet.size(): " << imageSet.size() << endl;
    cout<< "animationSet.size(): " << animationSet.size() << endl;
    using json = nlohmann::json;

    json jsonData;

    json setting;
    int j = 0;
    for (int i = 1; i <= numberOfScreens; i++) {

        cout << "j: " << j << endl;
        json image;
        image["Height"] = imageSet.at(j).heightImage;
        image["Width"] = imageSet.at(j).widthImage;
        image["nbPixel"] = imageSet.at(j).numberPixel;
        image["posX"] = imageSet.at(j).posX;
        image["posY"] = imageSet.at(j).posY;

        json animation;
        animation["rotation"]["speed"] = animationSet.at(j).rotationSpeed;
        animation["rotation"]["direction"] = animationSet.at(j).rotationDirection;
        animation["rotation"]["rotation axis"] = animationSet.at(j).rotationAxis;
        animation["translation"]["speed"] = animationSet.at(j).translationSpeed;
        animation["translation"]["direction"] = animationSet.at(j).translationDirection;

        image["animation"] = animation;

        setting["image " + std::to_string(i)] = image;
        j++;
    }

    jsonData["setting"] = setting;

    json dictionary;
    dictionary["name"] = "translation";
    dictionary["type"] = ".exe";
    dictionary["executable"] = "translationCode";

    json param;
    param["number"] = 4;
    param["parm1"] = "newParam1";
    param["parm2"] = "newParam2";
    param["parm3"] = "newParam3";
    param["parm4"] = "newParam4";

    dictionary["param"] = param;

    jsonData["dictionary"] = dictionary;

    std::ofstream outputFile("output.json");
    outputFile << std::setw(4) << jsonData << std::endl;
    outputFile.close();

    std::cout << "JSON output saved to output.json" << std::endl;
}

