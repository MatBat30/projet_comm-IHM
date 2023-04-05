

#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct ParamImg {
    int nbPixel;
    int posX;
    int posY;
    int height;
    int width;
    int ratio;
};


class donnee {
private :
    std::string data;
    int numberScreen;
    int widthMur, heightMur;
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
    //void test();
    //void writefirstdata();
    //void clearjson();
    void test(string);

    void recover();
};


#endif //PROJET_COMM_DONNEE_H
