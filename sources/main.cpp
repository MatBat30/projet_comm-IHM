#include <iostream>
#include "header/gestion.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Variables pour stocker les noms de fichiers et leur contenu

    std::string monImage;
    std::string monFichier;
    int numberScreen = 0;
    std::vector<parametresImage> image = {};
    std::vector<parametresAnimation> animation = {};
//    std::vector<parametresDictionaire> dictionnaire = {};

    //create 2 structure de données a copié dans la classe gestion
    parametresImage image1 = {0, 0, 1050, 420, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation1 = {"NULL", "NULL", "NULL", "slow", "up"};
    image.push_back(image1);
    animation.push_back(animation1);

    parametresImage image2 = {420, 0, 1050, 420, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation2 = {"fast", "clockwise", "center", "NULL", "NULL"};
    image.push_back(image2);
    animation.push_back(animation2);

    parametresImage image3 = {840, 0, 1050, 420, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation3 = {"medium", "counter-clockwise", "bottom left", "slow", "right"};
    image.push_back(image3);
    animation.push_back(animation3);

    parametresImage image4 = {1260, 0, 1050, 420, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation4 = {"NULL", "NULL", "NULL", "fast", "left"};
    image.push_back(image4);
    animation.push_back(animation4);
    numberScreen = image.size();
    //kwnow the size of the vector image

    cout << "numberScreen: " << numberScreen << endl;
    vector<string> param = {"int", "string", "float", "double", "char", "char *"};

    parametresDictionaire dictionnaire = {"rotationfinal1", "rotationfinal1", "", static_cast<int>(size(param)), param};
//     dictionnaire.push_back(dico);

    monImage = "../other/Toto.jpg";
    monFichier = "../other/rotationfinale1.exe";

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