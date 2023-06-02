#include "../header/gestion.h"

gestion::gestion(vector<parametresImage> image_, vector<parametresAnimation> animation_, vector <parametresDictionaire> dictonary_ , string imagePath_, string filePath_, int numberScreen_) {

    // Copie des structures de données
    image  = image_;
    animation = animation_;
    dictionnaire = dictonary_;
    filePath = filePath_;
    imagePath = imagePath_;
    numberScreen = numberScreen_;


//    //afficher dans un cout les structure de données pour vérifier
//    std::cout << "image: " << std::endl;
//    std::cout << "posX: " << image.posX << " ";
//    std::cout << "posY: " << image.posY << " ";
//    std::cout << "heightImage: " << image.heightImage << " ";
//    std::cout << "widthImage: " << image.widthImage << " ";
//    std::cout << "numberPixel: " << image.numberPixel << " ";
//    std::cout << "animation: " << std::endl;
//    std::cout << "rotationSpeed: " << animation.rotationSpeed << " ";
//    std::cout << "rotationDirection: " << animation.rotationDirection << " ";
//    std::cout << "rotationAxis: " << animation.rotationAxis << " ";
//    std::cout << "translationSpeed: " << animation.translationSpeed << " ";
//    std::cout << "translationDirection: " << animation.translationDirection << " ";
//    std::cout << std::endl;
}

vector <parametresImage> gestion::getImage() const {
    return image;
}

vector <parametresAnimation> gestion::getAnimation() const {
    return animation;
}
vector <parametresDictionaire> gestion::getDictionaire() const {
    return dictionnaire;
}

void gestion::run(string filePath) {
    cout << "run extention : "<< donnee::getFileExtension(filePath) << endl;

    std::vector<char> contenuMessage;

    extension = donnee::getFileExtension(filePath).c_str();

    donnees.setData(image, animation, dictionnaire);

    // Écriture des données dans un fichier JSON

    donnees.writeData(numberScreen);

    if (strcmp(extension, "jsn") == 0) {
        contenuMessage = donnees.getData(imagePath);
        com.init();
        com.connectToServer();
        //Envoi de l'image
        com.sendExtension(const_cast<char *>(extension));
        //Envoi de l'extension
        com.sendMessage(contenuMessage);
        //Fermeture de la connexion
        com.closeConnection();
    }
    else if(strcmp(extension, "jpg") == 0) {
        contenuMessage = donnees.getData(filePath);
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendExtension(const_cast<char *>(extension));
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
        try {
            gestion::run("jsn");
        } catch ( const std::exception &e) {
            std::cerr <<"error: "<< e.what() << std::endl;
        }
    }
    else if (strcmp(extension, "cpp") == 0) {
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendExtension(const_cast<char *>(extension));
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
        try {
            gestion::run("jsn" );
        } catch ( const std::exception &e) {
            std::cerr <<"error: "<< e.what() << std::endl;
        }
    }
    else {
        std::cout << "Erreur: extension non reconnue" << std::endl;
    }
}
