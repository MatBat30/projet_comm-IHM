//
// Created by m.batailler on 29/03/2023.
//
#include <iostream>
#include "donnee.h"
#include "cmake-build-debug/json.hpp"
void donnee::getdata( )
{
    std::cout << "get\n";
}

void donnee::setdata(int nbpixele, int posXimge, int posYimge, int dimHecre, int posXimg2, int dimLecre, int num_ecre,int numtotecra)
{
    //dimHmur dimmesion du mur hauteur en cm, dimLmur dimmesion du mur largeur en cm, nbpixel nombre de pixel de l'ecrant en px ,
    //posXimg position de l'image sur l'axe X , posYimg position de l'image sur l'axe Y

    this->num_ecre = num_ecre;
    ParamVar.nbpixel = nbpixele;
    ParamVar.posXimg = posXimge ;
    ParamVar.posYimg = posYimge ;
    ParamVar.dimHimg = dimHecre ;
    ParamVar.dimLimg = dimLecre ;
    ParamVar.posXimg2 = posXimg2;


    dimHmur = dimHecre;
    dimLmur = dimLecre;


    nom = "image ";
    std::string numeroecr = std::to_string(num_ecre);
    num = numeroecr;

    temp_nom=nom.append(num);

    std::cout << "set" << num_ecre << endl;

    vec.push_back(numtotecra);
    vec.push_back(ParamVar.nbpixel);
    vec.push_back(ParamVar.posXimg);
    vec.push_back(ParamVar.posYimg);
    vec.push_back(ParamVar.dimHimg);
    vec.push_back(ParamVar.dimLimg);
    vec.push_back(ParamVar.posXimg2);


}

int donnee::writedata()
{

    nlohmann::json j ;
    std::ofstream file_id;
    std::string test;

    j[temp_nom]["nbpixel"] = vec.at(0);
    j[temp_nom]["posXimg"] = vec.at(1);
    j[temp_nom]["posYimg"] = vec.at(2);
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
/*
---------------------------------------------------------------------------------------------------

//supresion des caract�re en trop
void donnee::clearjson() {
std::string json_file_path = "dimmension.json";
std::ifstream json_file(json_file_path);
if (!json_file.is_open()) {

	std::cerr << "Erreur d'ouverture du fichier : " << json_file_path << std::endl;
}
std::string json_str((std::istreambuf_iterator<char>(json_file)), std::istreambuf_iterator<char>());
json_str.erase(170, 31);

json_file.close();

std::cout << json_str << "\n";

}*/




/*void donnee::writefirstdata() {

    Json::StyledWriter styledWriter;
    Json::Value event;

    std::ofstream file_id;

    event["dimmention"]["Largeur"]= dimHmur;
    event["dimmention"] ["Hauteur"] = dimLmur;

    file_id.open("dimmension.json", ios::in | ios::ate);
    file_id << styledWriter.write(event);
    file_id.close();

}*/

