#include "../header/comm.h"

int  comm::init() {
    WSAData wsaData;
    // Initialise Winsock

    int wsaResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (wsaResult != 0) {
        std::cerr << "WSAStartup failed with error: " << wsaResult << std::endl;
        return 1;
    }
    // Creation du socket
     clientSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (clientSocket == INVALID_SOCKET) {
        std::cerr << "Socket creation failed with error: " << WSAGetLastError() << std::endl;
        WSACleanup();
        return 1;
    }

    // mise en place de l address server et du port

    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(8080);
    serverAddress.sin_addr.s_addr = inet_addr("192.168.186.128 ");

}

int comm::connectToServer() {
    // Connect to the server
    int result = connect(clientSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress));
    if (result == SOCKET_ERROR) {
        std::cerr << "Connection failed with error: " << WSAGetLastError() << std::endl;
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }
    std::cout << "Connected to server" << std::endl;

}

void comm::sendSize(std::vector<char> nomFichier) {
    imageSize = static_cast<int>(nomFichier.size());
    std::cout << "Taille de l'image : " << imageSize <<" octets"<< std::endl;
    send(clientSocket, (const char*)&imageSize, sizeof(imageSize), 0);
    std::cout << "Taille du fichier envoyee : " << imageSize << " octets" << std::endl;

}

void comm::sendMessage(std::vector<char> contenuImage) {
    // Send a message to the server
    // convert string to const char *
    int bytesSent = send(clientSocket, contenuImage.data(), contenuImage.size(), 0);
    if (bytesSent == SOCKET_ERROR) {
        std::cerr << "Erreur lors de l'envoi de l'image : " << WSAGetLastError() << std::endl;
    } else {
        std::cout << "Image envoyee avec succes (" << bytesSent << " octets)." << std::endl;
    }
}

void comm::sendExtension(char* extension) {
    std::cout << "Taille de l'extention : " << strlen(extension) <<" octets"<< std::endl;
    int bytesSent = send(clientSocket, extension, strlen(extension), 0);
std::cout << "Taille de l'envoie : " << bytesSent <<" octets"<< std::endl;
    if (bytesSent < 0) {
        std::cerr << "Erreur lors de l'envoi de l'extention : " << WSAGetLastError() << std::endl;
    } else {
        std::cout << "extention envoyee avec succes (" << bytesSent << " octets)." << std::endl;
    }
}

void comm::receiveMessage() {
    // Receive a message from the server
    char buffer[512];
    int receivedBytes = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (receivedBytes > 0) {
        buffer[receivedBytes] = '\0';
        std::cout << "Received from server: " << buffer << std::endl;
    }
}

void comm::closeConnection() {
    closesocket(clientSocket);
    WSACleanup();
}


