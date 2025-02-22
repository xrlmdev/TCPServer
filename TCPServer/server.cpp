#include "main.h"
#include "server.h"

Server::Server(short sPort) {
    WSAStartup(MAKEWORD(2, 2), &wsaData);

    serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

    sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(sPort);

    bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr));
    listen(serverSocket, 5);
}

Server::~Server() {
    closesocket(serverSocket);
    WSACleanup();
}

SOCKET Server::GetSocket() {
    return serverSocket;
}