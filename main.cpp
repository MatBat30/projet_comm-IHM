#include "donnee.h"
#include "comm.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    comm c;
    donnee d;
    std:: string monImage = "img1.png";
    std::vector<char> contenuImage = d.getdata(monImage);
    c.init();
    c.connectToServer();
    c.sendSize(contenuImage);
    c.sendMessage(contenuImage);
    c.closeConnection();
    return 0;
}