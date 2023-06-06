#include <iostream>
#include "header/gestion.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Variables pour stocker les noms de fichiers et leur contenu

    std::string monImage;
    std::string monFichier;
    int numberScreen = 4;
    std::vector<parametresImage> image = {};
    std::vector<parametresAnimation> animation = {};
//    std::vector<parametresDictionaire> dictionnaire = {};

    //create 2 structure de données a copié dans la classe gestion
    parametresImage image1 = {01, 1000, 100, 1080, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation1 = {"NULL", "NULL", "NULL", "1", "1"};
    image.push_back(image1);
    animation.push_back(animation1);

    parametresImage image2 = {02, 2000, 200, 2080, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation2 = {"2", "2", "2", "NULL", "NULL"};
    image.push_back(image2);
    animation.push_back(animation2);

    parametresImage image3 = {3, 3000, 300, 3080, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation3 = {"3", "3", "3", "3", "3"};
    image.push_back(image3);
    animation.push_back(animation3);

    parametresImage image4 = {4, 4000, 400, 4080, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation4 = {"NULL", "NULL", "NULL", "4", "4"};
    image.push_back(image4);
    animation.push_back(animation4);

    vector<string> param = {"int", "string", "float", "double", "char", "char *"};

    parametresDictionaire dictionnaire = {"NULL", "NULL", "NULL", static_cast<int>(size(param)), param};
//     dictionnaire.push_back(dico);

    monImage = "../other/Toto.jpg";
    monFichier = "../other/rotation.cpp";

    gestion g(image, animation, dictionnaire, monImage, monFichier, numberScreen);

    try {
        cout << "------------debut premier run------------" << endl;
        g.run(monImage);
        cout << "------------fin premier run------------" << endl;
    } catch (const std::exception &e) {
        std::cerr << "error: run 1 " << e.what() << std::endl;
    }

    try {
        cout << "------------debut second run------------" << endl;
        g.run(monFichier);
        cout << "------------fin second run------------" << endl;
    } catch (const std::exception &e) {
        std::cerr << "error: run 2 " << e.what() << std::endl;
    }
//(づ｡◕‿‿◕｡)づ
    return 0;
}