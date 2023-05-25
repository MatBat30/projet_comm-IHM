#include "header/donnee.h"
#include "header/comm.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    // Création d'objets de communication et de données
    comm com;
    donnee data;

    // Variables pour stocker les noms de fichiers et leur contenu
    std::string monImage;
    std::vector<char> contenuMessage;

    // Extensions des fichiers à envoyer
    const char *extensionJson = "jsn";
    const char *extensionJpg = "jpg";
    const char *extensionCpp = "pso";

    // Configuration des données pour les images et animations
    data.setData(1, 1000, 100, 1080, 1920, 1, 10, 10, "1", "1", "1" , "NULL", "NULL");
    data.setData(2, 2000, 200, 2080, 2920, 2, 20, 20, "NULL", "NULL", "NULL", "2", "2");
    // Initialisation de la communication et connexion au serveur
    //com.init();
    //com.connectToServer();

    // Écriture des données dans un fichier JSON
      data.writeData(2);
//    monImage = "../sources/other/Toto.jpg";

    // Récupération du contenu du fichier JSON
//    contenuMessage = data.getData(monFichier);

    // Envoi de la taille du fichier, de l'extension et du contenu du fichier au serveur
    //com.sendSize(contenuMessage);
    //com.sendExtension(const_cast<char *>(extensionJpg));
    //com.sendMessage(contenuMessage);

    // Fermeture de la connexion
   // com.closeConnection();

    return 0;
}