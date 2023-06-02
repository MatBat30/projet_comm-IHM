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
    vector <parametresDictionaire> dictionnaire;

    string filePath;
    string imagePath;
    const char * extension;
    int numberScreen;

public:
    gestion( vector<parametresImage>, vector<parametresAnimation>, vector <parametresDictionaire>, string, string, int);
    vector<parametresImage> getImage() const;
    vector<parametresAnimation> getAnimation() const;
    vector<parametresDictionaire> getDictionaire() const;
    void run(string extension_);

};

#endif //PROJET_COMM_GESTION_H
