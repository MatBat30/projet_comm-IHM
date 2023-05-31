#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "../header/donnee.h"
#include "../header/json.hpp"

nlohmann::json j;

// Fonction pour lire les données d'un fichier et les stocker dans un std::vector<char>
vector<char> donnee::getData(const std::string &nomFichier) {
    std::string fileName = nomFichier;

    // Ouvrir le fichier en mode binaire
    std::ifstream fichier(fileName, std::ios::binary);

    // Vérifier si le fichier est ouvert correctement
    if (!fichier.is_open()) {
        std::cout << "Erreur lors de l'ouverture du fichier : " << fileName << std::endl;
        return std::vector<char>(); // Retourner un vecteur vide en cas d'erreur
    }

    // Lire le contenu du fichier dans un std::vector<char>
    std::vector<char> contenuFichier((std::istreambuf_iterator<char>(fichier)), std::istreambuf_iterator<char>());

    // Fermer le fichier
    fichier.close();

    return contenuFichier;
}

void donnee::setData(vector <parametresImage> inputImgParams, vector <parametresAnimation> inputAnimParams, int numberScreen_ ){


    imageSet = inputImgParams;
    animationSet = inputAnimParams;

//    for (int i = 0; i < numberScreen_; ++i) {
//        paramImage.push_back(inputImgParams.at(i).numberPixel );
//        paramImage.push_back(inputImgParams.at(i).heightImage );
//        paramImage.push_back(inputImgParams.at(i).widthImage );
//        paramImage.push_back(inputImgParams.at(i).posX );
//        paramImage.push_back(inputImgParams.at(i).posY );
//    }
//
//    for (int i = 0; i < numberScreen_; ++i) {
//        paramAnimation.push_back(inputAnimParams.at(i).rotationSpeed );
//        paramAnimation.push_back(inputAnimParams.at(i).rotationDirection );
//        paramAnimation.push_back(inputAnimParams.at(i).rotationAxis );
//        paramAnimation.push_back(inputAnimParams.at(i).translationSpeed );
//        paramAnimation.push_back(inputAnimParams.at(i).translationDirection );
//
//    }

//    std::cout << "paramImage: " << std::endl;
//    for (int i = 0; i < paramImage.size(); ++i) {
//        cout << paramImage.at(i) << " ";
//    }
//    std::cout << endl << "paramAnimation: " << std::endl;
//    for (int i = 0; i < paramAnimation.size(); ++i) {
//        cout << paramAnimation.at(i) << " ";
//    }
//    std::cout << endl;




}
// Fonction qui écrit les données dans un fichier JSON
//void donnee::writeData(int numberScreen) {
//    int nombreEcrant = numberScreen ;
//    std::ostringstream json_output;
//    json_output << "{" << std::endl;
//    json_output << "  \"setting\": {" << std::endl;
//
//    try {
//        for (int i = 0; i <= nombreEcrant; ++i) {
//            std::string height = std::to_string(imageSet.at(i).heightImage); //certainement inaxesible
//            std::string width = std::to_string(imageSet.at(i).widthImage);
//            std::string nbPixel = std::to_string(imageSet.at(i).numberPixel);
//            std::string posX = std::to_string(imageSet.at(i).posX );
//            std::string posY = std::to_string(imageSet.at(i).posY);
//
//            std::string rotation_speed = (animationSet.at(i).rotationSpeed);
//            std::string rotation_direction = (animationSet.at(i).rotationDirection);
//            std::string rotation_axis = (animationSet.at(i).rotationAxis);
//            std::string translation_speed = (animationSet.at(i).translationSpeed);
//            std::string translation_direction = (animationSet.at(i).translationDirection);
//
//            json_output << createImageBlock(i, height, width, nbPixel, posX, posY,rotation_speed,
//                                            rotation_direction, rotation_axis,translation_speed, translation_direction);
//
//            if (i != nombreEcrant) {
//                json_output << "," << std::endl;
//            }
//        }
//    }
//    catch (const std::out_of_range &e) {
//        std::cout << "Erreur zone ecriture image : " << e.what() << std::endl;
//    }
//    // Crée et ajoute des blocs d'inputImgParams pour chaque écran dans le fichier JSON
//
//
//    json_output << std::endl << "  }," << std::endl;
//    json_output << "   \"dictionary \":{" << std::endl;
//    json_output << "      \"name\":\"translation\"," << std::endl;
//    json_output << "      \"type\":\".so\"," << std::endl;
//    json_output << "      \"executable\":\"translationCode\"," << std::endl;
//    json_output << "      \"param\":{" << std::endl;
//    json_output << "         \"number\":4," << std::endl;
//    json_output << "         \"parm1\":\"newParam\"," << std::endl;
//    json_output << "         \"parm2\":\"newParam\"," << std::endl;
//    json_output << "         \"parm3\":\"newParam\"," << std::endl;
//    json_output << "         \"parm4\":\"newParam\"" << std::endl;
//    json_output << "    }" << std::endl;
//    json_output << "  }" << std::endl;
//    json_output << "}";
//
//try {
//    // Écrit le contenu de json_output dans le fichier "output.json" et ferme le fichier
//    std::ofstream output_file("output.json");
//    output_file << std::setprecision(5) << json_output.str();
//    output_file.close();
//}
//catch (const std::out_of_range &e) {
//    std::cout << "Erreur : " << e.what() << std::endl;
//}
//    std::cout << "JSON output saved to output.json" << std::endl;
//}
//
//// Fonction qui crée un bloc d'inputImgParams en format JSON en utilisant les paramètres fournis
//std::string donnee::createImageBlock(int n, const std::string& height, const std::string& width,
//                                     const std::string& nbPixel, const std::string& posX, const std::string& posY,
//                                     const std::string& rotation_speed, const std::string& rotation_direction,
//                                     const std::string& rotation_axis, const std::string& translation_speed,
//                                     const std::string& translation_direction) {
//    // Crée un flux de sortie pour construire le bloc d'inputImgParams
//    std::ostringstream image_block;
//    image_block << "    \"inputImgParams " << n << "\": {" << std::endl;
//    image_block << "      \"Height\": " << height << "," << std::endl;
//    image_block << "      \"Width\": " << width << "," << std::endl;
//    image_block << "      \"nbPixel\": " << nbPixel << "," << std::endl;
//    image_block << "      \"posX\": " << posX << "," << std::endl;
//    image_block << "      \"posY\": " << posY << "," << std::endl;
//    image_block << "      \"animation\":{" << std::endl;
//    image_block << "        \"rotation\":{" << std::endl;
//    image_block << "          \"speed\": \"" << rotation_speed << "\"," << std::endl;
//    image_block << "          \"direction\":\"" << rotation_direction << "\"," << std::endl;
//    image_block << "          \"rotation axis\":\"" << rotation_axis << "\"" << std::endl;
//    image_block << "        } ," << std::endl;
//    image_block << "        \"translation\":{" << std::endl;
//    image_block << "          \"speed\":\"" << translation_speed << "\"," << std::endl;
//    image_block << "          \"direction\":\"" << translation_direction << "\"" << std::endl;
//    image_block << "        }" << std::endl;
//    image_block << "      }" << std::endl;
//    image_block << "    }";
//
//    // Retourne le bloc d'inputImgParams sous forme de chaîne de caractères
//    return image_block.str();
//}
void donnee::writeData(int numberOfScreens) {
    using json = nlohmann::json;
    json jsonData;

    json setting;

    for (int i = 1; i <= numberOfScreens; i++) {
        json image;
        image["Height"] = imageSet.at(i).heightImage;
        image["Width"] = (imageSet.at(i).widthImage);
        image["nbPixel"] = (imageSet.at(i).numberPixel);
        image["posX"] = (imageSet.at(i).posX);
        image["posY"] = (imageSet.at(i).posY);

        json animation;
        animation["rotation"]["speed"] = (animationSet.at(i).rotationSpeed);
        animation["rotation"]["direction"] = (animationSet.at(i).rotationDirection);
        animation["rotation"]["rotation axis"] = (animationSet.at(i).rotationAxis);
        animation["translation"]["speed"] = (animationSet.at(i).translationSpeed);
        animation["translation"]["direction"] = (animationSet.at(i).translationDirection);

        image["animation"] = animation;

        setting["image " + std::to_string(i)] = image;
    }

    jsonData["setting"] = setting;

    json dictionary;
    dictionary["name"] = "translation";
    dictionary["type"] = ".ini";
    dictionary["executable"] = "translationCode";

    json param;
    param["number"] = 4;
    param["parm1"] = "newParam";
    param["parm2"] = "newParam";
    param["parm3"] = "newParam";
    param["parm4"] = "newParam";

    dictionary["param"] = param;

    jsonData["dictionary"] = dictionary;

    std::ofstream outputFile("output.json");
    outputFile << std::setw(4) << jsonData << std::endl;
    outputFile.close();

    std::cout << "JSON output saved to output.json" << std::endl;
}

