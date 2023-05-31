#include "header/gestion.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Variables pour stocker les noms de fichiers et leur contenu

    std::string monImage;
    std::string monFichier;
    // Extensions des fichiers à envoyer
    const char *extensionJson = "jsn";
    const char *extensionJpg = "jpg";
    const char *extensionCpp = "pso";

    //create 2 structure de données a copié dans la classe gestion
    parametresImage image1= {1, 1000, 100, 1080, 1920};
    parametresAnimation animation1 = {"NULL", "NULL", "NULL", "2", "2"};

    monImage = "../sources/other/Toto.jpg";
    monFichier = "../cmake-build-debug/projet_comm.exe";

    gestion g(image1, animation1, monImage, monFichier, 2);
    try {
        g.run(const_cast<char *>(extensionJson));
    } catch ( const std::exception &e) {
        std::cerr <<"error: "<< e.what() << std::endl;
    }
    try {
        g.run(const_cast<char *>(extensionJpg));
    } catch ( const std::exception &e) {
        std::cerr <<"error: "<< e.what() << std::endl;
    }
    try {
        g.run(const_cast<char *>(extensionCpp));
    } catch ( const std::exception &e) {
        std::cerr <<"error: "<< e.what() << std::endl;
    }


    return 0;
}