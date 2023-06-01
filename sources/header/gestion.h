#ifndef PROJET_COMM_GESTION_H
#define PROJET_COMM_GESTION_H

#include "structureDonnee.h"
#include "comm.h"
#include "donnee.h"

class gestion {

private:
    donnee donnees;
    comm com;
    vector <parametresImage> image;
    vector <parametresAnimation> animation;

    string filePath;
    string imagePath;
    const char * extension;
    int numberScreen;

public:
    gestion( vector<parametresImage> , vector<parametresAnimation>, string, string, int);
    vector<parametresImage> getImage() const;
    vector<parametresAnimation> getAnimation() const;
    void run(char * extension);

};

#endif //PROJET_COMM_GESTION_H
