#include <iostream>
#include <sstream>
#include <iomanip>
#include <fstream>
#include "../header/donnee.h"
#include "../header/json.hpp"


nlohmann::json j;

vector<char> donnee::getdata(const std::string &nomFichier) {

    fileName = nomFichier;


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

//gestion du fichier a envoyer par socket
/*----------------------------------------------------------------------------------------------------------------------*/

void donnee::setdata(int nbpixele, int posXimge, int posYimge, int dimHecre, int posXimg2, int dimLecre, int num_ecre,
                     int numtotecra) {
    this->numberScreen = num_ecre;

    Param.nbPixel = nbpixele;
    Param.posX = posXimge;
    Param.posY = posYimge;
    Param.height = dimHecre;
    Param.width = dimLecre;
    Param.ratio = posXimg2;
    widthMur = dimHecre;
    heightMur = dimLecre;

    nom = "image ";
    std::string numeroecr = std::to_string(num_ecre);
    num = numeroecr;

    temp_nom = nom.append(num);

    vec.push_back(numtotecra);
    vec.push_back(Param.nbPixel);
    vec.push_back(Param.posX);
    vec.push_back(Param.posY);
    vec.push_back(Param.height);
    vec.push_back(Param.width);
    vec.push_back(Param.ratio);


    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec.at(i) << ";";
    }

    std::cout << "set" << num_ecre << endl;


}

int donnee::writedata() {


    std::ofstream file_id;
    std::string test;

    j[temp_nom]["nbPixel"] = vec.at(0);
    j[temp_nom]["posX"] = vec.at(1);
    j[temp_nom]["posY"] = vec.at(2);
    j[temp_nom]["dimHecr"] = vec.at(3);
    j[temp_nom]["dimLecr"] = vec.at(4);
    j[temp_nom]["dimHecr"] = vec.at(5);
    j[temp_nom]["dimLecr"] = vec.at(6);


    std::ofstream output_file("output.json");
    if (!output_file.is_open()) {
        std::cerr << "Erreur lors de l'ouverture du fichier pour l'écriture." << std::endl;
        return 1;
    }
    std::cout << j.dump(4) << std::endl;
    output_file.close();
    return 0;
}

void donnee::testJson() {

        int nombreEcrant = 14;

        std::ostringstream json_output;
        json_output << "{" << std::endl;
        json_output << "  \"setting\": {" << std::endl;

        for (int i = 1; i <= nombreEcrant; ++i) {
            json_output << create_image_block(i);
            if (i != nombreEcrant) {
                json_output << "," << std::endl;
            }
        }

        json_output << std::endl << "  }," << std::endl;
        json_output << "   \"dictionary \":{" << std::endl;
        json_output << "      \"name\":\"translation\"," << std::endl;
        json_output << "      \"type\":\".ini\"," << std::endl;
        json_output << "      \"executable\":\"translationCode\"," << std::endl;
        json_output << "      \"param\":{" << std::endl;
        json_output << "         \"number\":4," << std::endl;
        json_output << "         \"parm1\":\"newParam\"," << std::endl;
        json_output << "         \"parm2\":\"newParam\"," << std::endl;
        json_output << "         \"parm3\":\"newParam\"," << std::endl;
        json_output << "         \"parm4\":\"newParam\"" << std::endl;
        json_output << "    }" << std::endl;
        json_output << "  }" << std::endl;
        json_output << "}";

        std::ofstream output_file("output.json");
        output_file << std::setprecision(5) << json_output.str();
        output_file.close();

        std::cout << "JSON output saved to output.json" << std::endl;



}

    std::string donnee::create_image_block(int n) {
        std::ostringstream image_block;
        image_block << "    \"image " << n << "\": {" << std::endl;
        image_block << "      \"Height\": 200," << std::endl;
        image_block << "      \"Width\": 700," << std::endl;
        image_block << "      \"ratio\": 1.6," << std::endl;
        image_block << "      \"nbPixel\": 1920," << std::endl;
        image_block << "      \"posX\": 1920," << std::endl;
        image_block << "      \"posY\": 0," << std::endl;
        image_block << "      \"animation\":{" << std::endl;
        image_block << "        \"rotation\":{" << std::endl;
        image_block << "          \"speed\": \"fast\"," << std::endl;
        image_block << "          \"direction\":\"clockwise\"," << std::endl;
        image_block << "          \"rotation axis\":\"center\"" << std::endl;
        image_block << "        } ," << std::endl;
        image_block << "        \"translation\":{" << std::endl;
        image_block << "          \"speed\":\"medium\"," << std::endl;
        image_block << "          \"direction\":\"down\"" << std::endl;
        image_block << "        }" << std::endl;
        image_block << "      }" << std::endl;
        image_block << "    }";
        return image_block.str();
    };