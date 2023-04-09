#include "donnee.h"
#include "comm.h"

#pragma comment(lib, "ws2_32.lib")

int main() {
    comm c;
    donnee d;
    std:: string monImage = "projet_comm.ilk";
    std::vector<char> contenuImage = d.getdata(monImage);
    c.init();
    c.connectToServer();
    c.sendSize(contenuImage);
    c.sendMessage(contenuImage);
    c.closeConnection();
    return 0;
}