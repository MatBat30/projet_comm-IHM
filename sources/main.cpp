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

    //crée 2 structure de données a copié dans la classe gestion
    parametresImage image1 = {473, 165, 201, 221, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation1 = {"NULL", "NULL", "NULL", "NULL", "NULL"};
    image.push_back(image1);
    animation.push_back(animation1);

    parametresImage image2 = {698, 165, 201, 221, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation2 = {"NULL", "NULL", "NULL", "NULL", "NULL"};
    image.push_back(image2);
    animation.push_back(animation2);

    parametresImage image3 = {475, 371, 201, 221, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation3 = {"NULL", "NULL", "NULL", "NULL", "NULL"};
    image.push_back(image3);
    animation.push_back(animation3);

    parametresImage image4 = {700, 371, 201, 221, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation4 = {"NULL", "NULL", "NULL", "NULL", "NULL"};
    image.push_back(image4);
    animation.push_back(animation4);

    parametresImage image5 = {923, 371, 201, 221, "2023-06-02 15:27", "2023-06-02 15:32"};
    parametresAnimation animation5 = {"NULL", "NULL", "NULL", "NULL", "NULL"};
    image.push_back(image5);
    animation.push_back(animation5);

    numberScreen = image.size();
    cout << "numberScreen: " << numberScreen << endl;
    vector<string> param = {"int", "string", "float", "double", "char", "char *"};

    parametresDictionaire dictionnaire = {"./rotation", "rotation", "", static_cast<int>(size(param)), param};

    monImage = "../other/jk.jpg";
    monFichier = "../other/rotation.exe";/*rename forcee avec le .exe car le fichier n'as pas d'extension par defaut,
 *                                      pour l'identifiée plus facilement on force l'extension .exe qui sera enlevée
 *                                      a la reception cotée intermediaire   */

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