#ifndef PROJET_COMM_GESTION_H
#define PROJET_COMM_GESTION_H

#include "donnee.h"
#include "comm.h"

// Structure pour stocker les paramètres de l'image
struct parametresImage {
    int posX;
    int posY;
    int heightImage;
    int widthImage;
    int numberPixel;
};

// Structure pour stocker les paramètres de l'animation
struct parametresAnimation {
    string rotationSpeed;
    string rotationDirection;
    string rotationAxis;
    string translationSpeed;
    string translationDirection;
};


class gestion {

private:
    donnee data;
    comm com;
    parametresImage image{};
    parametresAnimation animation{};
    string filePath;
    string imagePath;
    int numberSreen;

public:
    gestion(parametresImage, parametresAnimation, string, string, int);
    parametresImage getImage() const;
    parametresAnimation getAnimation() const;
    void run(char *extension);

};

#endif //PROJET_COMM_GESTION_H
