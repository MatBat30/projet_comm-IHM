#include <iostream>
#include "header/gestion.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Variables pour stocker les noms de fichiers et leur contenu

    std::string monImage;
    std::string monFichier;
    int numberScreen = 4;
    // Extensions des fichiers à envoyer
    const char *extensionJson = "jsn";
    const char *extensionJpg = "jpg";
    const char *extensionEXxe = "exe";

    //create 2 structure de données a copié dans la classe gestion
    parametresImage image1= {01, 1000, 100, 1080, 1920};
    parametresAnimation animation1 = {"NULL", "NULL", "NULL", "1", "1"};

    parametresImage image2= {02, 2000, 200, 2080, 2920};
    parametresAnimation animation2 = {"2", "2", "2", "NULL", "NULL"};

    parametresImage image3 = { 3, 3000, 300, 3080, 3920 };
    parametresAnimation animation3 = { "3", "3", "3", "3", "3" };

    parametresImage image4 = { 4, 4000, 400, 4080, 4920 };
    parametresAnimation animation4 = { "NULL", "NULL", "NULL", "4", "4" };

    std::vector<parametresImage> image = {image1, image2, image3, image4};
    std::vector<parametresAnimation> animation = {animation1, animation2, animation3, animation4};

    monImage = "../sources/other/Toto.jpg";
    monFichier = "../cmake-build-debug/projet_comm.exe";

    gestion g(image, animation, monImage, monFichier, numberScreen);

    try {
        g.run(const_cast<char *>(extensionJson));
    } catch ( const std::exception &e) {
        std::cerr <<"error: "<< e.what() << std::endl;
    }
//    try {
//        g.run(const_cast<char *>(extensionJpg));
//    } catch ( const std::exception &e) {
//        std::cerr <<"error: "<< e.what() << std::endl;
//    }
//    try {
//        g.run(const_cast<char *>(extensionEXxe));
//    } catch ( const std::exception &e) {
//        std::cerr <<"error: "<< e.what() << std::endl;
//    }


    return 0;
}