#include "header/donnee.h"
#include "header/comm.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    comm c;
    donnee d;
    std:: string monFichier;
    std::vector<char> contenuFichier;
    const char *extensionJson = "jsn";
    const char *extensionJpg = "jpg";
    const char *extensionCpp = "cpp";
    d.setdata(1, 200, 300, 1080, 1920, 1, 1, 1, 1, "1", "1", "1");
    d.setdata(2, 200, 300, 1080, 1920, 2, 2, 2, 2, "2", "2", "2", "2", "2");
//    c.init();
//    c.connectToServer();
//    d.writeData(1);
//    monFichier = "../cmake-build-debug/output.json";
//    contenuFichier = d.getdata(monFichier);
//    c.sendSize(contenuFichier);
//    c.sendExtension(const_cast<char *>(extensionJpg));
//    c.sendMessage(contenuFichier);
//    c.closeConnection();

    return 0;
}