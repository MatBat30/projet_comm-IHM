#ifndef PROJET_COMM_STRUCTUREDONNEE_H
#define PROJET_COMM_STRUCTUREDONNEE_H

#include <string>
using namespace std;

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
#endif //PROJET_COMM_STRUCTUREDONNEE_H
