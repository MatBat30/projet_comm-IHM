#include <iostream>
#include "donnee.h"

int main() {
    std::cout << "Hello, World!" << std::endl;
    donnee d ;
    d.setdata(500, 50, 100, 1400, 1400, 300, 2, 1);
    d.setdata(500, 50, 100, 1400, 1400, 300, 2, 2);
    d.setdata(500, 50, 100, 1400, 1400, 300, 2, 3);
    d.writedata();
    return 0;
}
