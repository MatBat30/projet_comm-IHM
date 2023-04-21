#ifndef PROJET_COMM_DONNEE_H
#define PROJET_COMM_DONNEE_H

#include <stdio.h>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct parametresImage {
    int posX;
    int posY;
    int heightImage;
    int widthImage;
    int ratio;
    int numberPixel;
};


struct parametresAnimation {
    string rotationSpeed;
    string rotationDirection;
    string rotationAxis;
    string translationSpeed;
    string translationDirection;
};


class donnee {

private :

    vector<int> paramImage;
    vector<string> paramAnimation;
    vector<char> message;
    parametresImage Image{};
    parametresAnimation animation{};
    int widthWall;
    int heightWall;
    string nomVariable;
    std::string nom;
    std::string numeroecr;
public :

    vector<char> getdata(const string&);

    string createImageBlock( int, const string &, const string &, const string &, const string &,
                       const string &, const string &posY,
                       const string &,const string &, const string &,
                       const string &, const string &);

    void writeData(int numberScreen);

    void setdata(int, int , int , int , int , int , int , int ,int ,string rotationSpeed_ = "NULL", string rotationDirection_ = "NULL" , string rotationAxis_ = "NULL" ,string translationSpeed_= "NULL", string translationDirection_ = "NULL");
};


#endif //PROJET_COMM_DONNEE_H
