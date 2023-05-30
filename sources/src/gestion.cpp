//
// Created by m.batailler on 30/05/2023.
//

#include "../header/gestion.h"

gestion::gestion(parametresImage inputImgParams, parametresAnimation inputAnimParams, string filePath_, string imagePath_
                , int numberSreen_) {
    // Copie des structures de données
    image  = inputImgParams;
    animation = inputAnimParams;
    filePath = filePath_;
    imagePath = imagePath_;
    numberSreen = numberSreen_;

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
parametresImage gestion::getImage() const {
    return image;
}

parametresAnimation gestion::getAnimation() const {
    return animation;
}

void gestion::run(char *extension) {
    std::vector<char> contenuMessage;
    data.setData(image, animation);
    // Écriture des données dans un fichier JSON
    data.writeData(numberSreen);



    if (extension=="jpg") {
        contenuMessage = data.getData(imagePath);
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendSize(contenuMessage);
        com.sendExtension(const_cast<char *>(extension));
        com.sendMessage(contenuMessage);
    }
    else if(extension=="pso") {
        contenuMessage = data.getData(filePath);
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendSize(contenuMessage);
        com.sendExtension(const_cast<char *>(extension));
        com.sendMessage(contenuMessage);
    }
    else if (extension=="jsn") {
        contenuMessage = data.getData(filePath);
        com.init();
        com.connectToServer();
        // Envoi de l'image
        com.sendSize(contenuMessage);
        com.sendExtension(const_cast<char *>(extension));
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
    }
    else {
        std::cout << "Erreur: extension non reconnue" << std::endl;
    }




}
