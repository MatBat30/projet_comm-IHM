#ifndef PROJET_COMM_GESTION_H
#define PROJET_COMM_GESTION_H

#include "structureDonnee.h"
#include "comm.h"
#include "donnee.h"


class gestion {

private:
    donnee donnees;
    comm com;
    vector<parametresImage> image;
    vector<parametresAnimation> animation;
    parametresDictionaire dictionnaire;
    bool execution;
    string filePath;
    string imagePath;
    int numberScreen;

public:
    gestion(vector<parametresImage>, vector<parametresAnimation>, parametresDictionaire dictionnaire, string, string,
            int);

    vector<parametresImage> getImage() const;

    vector<parametresAnimation> getAnimation() const;

    parametresDictionaire getDictionaire() const;

    void run(string extension_);

};

#endif //PROJET_COMM_GESTION_H

