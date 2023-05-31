#include "../header/gestion.h"

gestion::gestion(vector<parametresImage> image_, vector<parametresAnimation> animation_,  string imagePath_, string filePath_, int numberScreen_) {

    // Copie des structures de données
    image  = image_;
    animation = animation_;
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

void gestion::run(char *extension) {
    std::vector<char> contenuMessage;
    donnees.setData(image, animation,numberScreen);
    // Écriture des données dans un fichier JSON

    donnees.writeData(numberScreen);

    if (extension=="jpg") {
        contenuMessage = donnees.getData(imagePath);
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendSize(contenuMessage);
        com.sendExtension(const_cast<char *>(extension));
        //j'ai un gros zgueg
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
    }
//    else if(extension=="pso") {
//        contenuMessage = donnees.getData(filePath);
//        com.init();
//        com.connectToServer();
//        // Envoi de l'image
//        com.sendSize(contenuMessage);
//        com.sendExtension(const_cast<char *>(extension));
//        com.sendMessage(contenuMessage);
//        // Fermeture de la connexion
//        com.closeConnection();
//    }
//    else if (extension=="jsn") {
//
//        com.init();
//        com.connectToServer();
//        // Envoi de l'image
//        com.sendSize(contenuMessage);
//        com.sendExtension(const_cast<char *>(extension));
//        com.sendMessage(contenuMessage);
//        // Fermeture de la connexion
//        com.closeConnection();
//    }
    else {
        std::cout << "Erreur: extension non reconnue" << std::endl;
    }
}
