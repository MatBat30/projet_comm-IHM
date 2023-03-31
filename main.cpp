#include <iostream>
#include "donnee.h"

int main() {
    std::string root;
    std::string path;

    std::cout << "Hello, World!" << std::endl;

    cout << "Veuillez entrer le chemin d'acces de l'image : " << endl;
    cin >>path;
    root = "C:/Users/m.batailler/Documents/projet comm/";
    root.append(path);
    cout << root << endl;


    donnee d ;
//    d.setdata(500, 50, 100, 1400, 1400, 300, 1, 3);
//    d.setdata(500, 50, 100, 1400, 1400, 300, 2, 3);
//    d.setdata(500, 50, 100, 1400, 1400, 300, 3, 3);
//    d.writedata();
d.test(root);
d.recover();
    return 0;
}