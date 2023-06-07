#include "../header/gestion.h"
//#define test
gestion::gestion(vector<parametresImage> image_, vector<parametresAnimation> animation_,
                 parametresDictionaire dictonary_, string imagePath_, string filePath_, int numberScreen_) {

    // Copie des données
    image = image_;
    animation = animation_;
    dictionnaire = dictonary_;
    filePath = filePath_;
    imagePath = imagePath_;
    numberScreen = numberScreen_;


#ifdef test
    cout << "filePath at gestion() state : " << filePath << endl;
    cout << "imagePath at gestion() state : " << imagePath << endl;
    cout << "numberScreen at gestion() state : " << numberScreen << endl;
    cout <<" data of image at gestion() state : " << endl;

    for (int i = 0; i < image.size(); i++) {
        cout << "image[" << i << "] : " << endl;
        cout << "posX: " << image[i].posX << " ";
        cout << "posY: " << image[i].posY << " ";
        cout << "heightImage: " << image[i].heightImage << " ";
        cout << "widthImage: " << image[i].widthImage << " ";
        cout << "numberPixel: " << image[i].numberPixel << " ";
        cout << "dateDebut: " << image[i].timeStart << " ";
        cout << "dateFin: " << image[i].timeEnd << " ";
        cout << endl;
    }
    cout <<" data of animation at gestion() state : " << endl;

    for (int i = 0; i < animation.size(); i++) {
        cout << "animation[" << i << "] : " << endl;
        cout << "rotationSpeed: " << animation[i].rotationSpeed << " ";
        cout << "rotationDirection: " << animation[i].rotationDirection << " ";
        cout << "rotationAxis: " << animation[i].rotationAxis << " ";
        cout << "translationSpeed: " << animation[i].translationSpeed << " ";
        cout << "translationDirection: " << animation[i].translationDirection << " ";
        cout << endl;
    }
#endif
}

vector<parametresImage> gestion::getImage() const {
    return image;
}

vector<parametresAnimation> gestion::getAnimation() const {
    return animation;
}

parametresDictionaire gestion::getDictionaire() const {
    return dictionnaire;
}

void gestion::run(string filePath_) {
    std::vector<char> contenuMessage;
    string jsonPath = "../cmake-build-debug/output.json";

    string extension  = donnee::getFileExtension(filePath_).c_str();
    char *cstr = new char[extension.length() + 1];
    std::strcpy(cstr, extension.c_str());
    cout << "extension at run() : " << extension << endl;
    donnees.setData(image, animation, dictionnaire);
    donnees.writeData(numberScreen);
#ifdef test
    cout << "run() avec l'extention : " << extension << endl;
    cout << "filePath at run() state : " << filePath << endl;
#endif
    if (extension == "jsn") {
        cout << "we are in run jpg"<< endl;
        contenuMessage = donnees.getJsonData();
        com.init();
        com.connectToServer();
        //Envoi de l'image
        com.sendExtension(cstr);
        //Envoi de l'extension
        com.sendMessage(contenuMessage);
        //Fermeture de la connexion
        com.closeConnection();
    } else if (extension == "jpg") {
        cout << "we are in run jpg"<< endl;
        contenuMessage = donnees.getData(imagePath);
        com.init();
        com.connectToServer();
        // Envoi de l'extension
        com.sendExtension(cstr);
        // Envoie de du fichier au format binaire
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
        try {
            gestion::run(jsonPath);
        } catch (const std::exception &e) {
            std::cerr << "error at run() JSON: " << e.what() << std::endl;
        }
    } else if (extension == "exe") {
        cout << "we are in run jpg"<< endl;
        contenuMessage = donnees.getData(filePath);
        com.init();
        com.connectToServer();
        // Envoi de l'extension
        com.sendExtension(cstr);
        // Envoie de du fichier au format binaire
        com.sendMessage(contenuMessage);
        // Fermeture de la connexion
        com.closeConnection();
        try {
            gestion::run(jsonPath);
        } catch (const std::exception &e) {
            std::cerr << "error at run() JSON: " << e.what() << std::endl;
        }
    } else {
        std::cout << "Erreur: extension non reconnue , extension :" << extension << std::endl;
    }
}
