#include "header/donnee.h"
#include "header/comm.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    comm c;
    donnee d;
    std:: string monImage = "../other/Toto.jpg";
    std::vector<char> contenuImage = d.getdata(monImage);
    const char *extensionJson = "json";
    const char *extensionJpg = "jpg";
    const char *extensionIni = "ini";
    c.init();
    c.connectToServer();
    //c.sendSize(contenuImage);
    c.sendExtension(const_cast<char *>(extensionJpg));
    c.sendMessage(contenuImage);
    c.closeConnection();
    return 0;
}