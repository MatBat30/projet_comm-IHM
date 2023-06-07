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

void donnee::setData(const vector<parametresImage> inputImgParams, const vector<parametresAnimation> inputAnimParams,
                     const parametresDictionaire inputDictParams) {
    imageSet = inputImgParams;
    animationSet = inputAnimParams;
    dictionarySet = inputDictParams;
}

void donnee::writeData(int numberOfScreens) {

    using json = nlohmann::json;
    json jsonData;
    json setting;

    int j = 0;
    for (int i = 1; i <= numberOfScreens; i++) {
//  cout << "j: " << j << endl;
        j = i - 1;
        json image;
        image["Height"] = imageSet.at(j).heightImage;
        image["Width"] = imageSet.at(j).widthImage;
        image["posX"] = imageSet.at(j).posX;
        image["posY"] = imageSet.at(j).posY;
        image["timeStart"] = imageSet.at(j).timeStart;
        image["timeEnd"] = imageSet.at(j).timeEnd;

        json animation;

        if (animationSet.at(j).rotationSpeed != "NULL") {
            animation["rotation"]["speed"] = animationSet.at(j).rotationSpeed;
            animation["rotation"]["direction"] = animationSet.at(j).rotationDirection;
            animation["rotation"]["rotation axis"] = animationSet.at(j).rotationAxis;
        }

        if (animationSet.at(j).translationSpeed != "NULL") {
            animation["translation"]["speed"] = animationSet.at(j).translationSpeed;
            animation["translation"]["direction"] = animationSet.at(j).translationDirection;

        }

        image["animation"] = animation;

        setting["image " + std::to_string(i)] = image;

    }

    jsonData["setting"] = setting;

    json dictionary;

    dictionary["name"] = dictionarySet.name;
    dictionary["type"] = dictionarySet.type;
    dictionary["executable"] = dictionarySet.exectutable;

    json param;
    param["number"] = dictionarySet.numberParam;
    string str;
//    int x = 0;

    for (int i = 0; i < dictionarySet.numberParam; ++i) {
//        x++;
        str = "parm" + std::to_string(i + 1);
        param[str] = dictionarySet.prametresNewAnimation.at(i);

    }

    dictionary["param"] = param;

    jsonData["dictionary"] = dictionary;
    try {
        std::ofstream outputFile("output.json");
        outputFile << std::setw(4) << jsonData << std::endl;
        outputFile.close();
    } catch (std::exception &e) {
        std::cout << "Error at writeData(): " << e.what() << std::endl;
    }
    std::cout << "JSON output saved to output.json" << std::endl;
}

std::string donnee::getFileExtension(const std::string &filePath_) {
    // Trouver la position du dernier point dans le chemin du fichier
    string filePath = filePath_;
    size_t dotPos = filePath.find_last_of(".");
    cout << "file path at getFileExtension() state : " << filePath << endl;
    if (dotPos != std::string::npos) {
        // Extraire l'extension à partir de la position du dernier point
        std::string extension = filePath.substr(dotPos + 1);
        cout << "enxtension : " << extension << endl;
        if (extension == "json") {
            extension = "jsn";
            cout << "extension : " << extension << endl;
            return extension;
        } else if (extension == "jpg") {
            extension = "jpg";
            cout << "extension : " << extension << endl;
            return extension;
        } else if (extension == "exe") {
            extension = "exe";
            cout << "extension : " << extension << endl;
            return extension;
        } else {
            std::cout << "L'extension n'est pas reconnue" << std::endl;
        }
    }
    return "";
}

vector<char> donnee::getJsonData() {
    vector<char> contenuJson = getData("output.json");
    std::string str(contenuJson.begin(), contenuJson.end());
   // cout << "contenuJson: " << endl;
   // cout << str << endl;
    return contenuJson;
}
