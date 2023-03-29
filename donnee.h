//
// Created by m.batailler on 29/03/2023.
//

#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ParamImg {
    int nbpixel;
    int posXimg;
    int posYimg;
    int dimHimg;
    int dimLimg;
    int posXimg2;
};


class donnee {
private :
    int num_ecre;
    int dimHmur, dimLmur;
    int state_vec;
    std::vector<int> vec;

    ParamImg ParamVar{};
    std::string nom;
    std::string num;
    std::string temp_nom;

public :
    void getdata();
    void setdata(int, int, int, int, int, int, int, int);
    int writedata();
    void writefirstdata();
    //void clearjson();
};


#endif //PROJET_COMM_DONNEE_H
