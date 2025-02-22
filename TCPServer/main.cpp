#include "main.h"
#include "utils.h"
#include "server.h"

int main(int argc, char* argv[]) {
    short sPort;

    if (argc > 2 && std::string(argv[1]) == "--port") {
        sPort = std::stoi(argv[2]);

        if (sPort < 0x1 || sPort > 0xFFFF) {
            std::cerr << "Invalid port number ( 1  - 65535 )." << std::endl;
            return 1;
        }
    }
    else {
        std::cerr << "Use: " << argv[0] << " --port PORT" << std::endl;
        return 1;
    }

    Server pServer(sPort);

    std::cout << "Server started on port " << sPort << std::endl;

    while (true) {
        
        sockaddr_in clientAddr;
        int clientLen = sizeof(clientAddr);
        SOCKET clientSocket = accept(pServer.GetSocket(), (sockaddr*)&clientAddr, &clientLen);

        if (clientSocket == INVALID_SOCKET) {
            std::cerr << "Accept failed. Details: " << WSAGetLastError() << std::endl;
            continue;
        }

        char clientIp[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &(clientAddr.sin_addr), clientIp, INET_ADDRSTRLEN);
        std::cout << "New connection from " << clientIp << std::endl;

        static const char* cCnnectionAcceptedMessage = "Connection accepted!\r\n";

        send(clientSocket, cCnnectionAcceptedMessage, strlen(cCnnectionAcceptedMessage), 0);
        
        std::string sReceivedData;
        char cBuffer[BUFFER_SIZE];

        while (true) {
            memset(cBuffer, 0, BUFFER_SIZE);
            int iBytesReceived = recv(clientSocket, cBuffer, BUFFER_SIZE - 1, 0);

            if (iBytesReceived == SOCKET_ERROR) {
                std::cerr << "Receive failed. Details: " << WSAGetLastError() << std::endl;
                break;
            }

            if (iBytesReceived == 0) {
                std::cout << "Client " << clientIp << " disconnected" << std::endl;
                break;
            }

            sReceivedData += cBuffer;

            if (sReceivedData.find('\n') != std::string::npos) {
                toUpperCase(sReceivedData);

                int iResult = send(clientSocket, sReceivedData.c_str(), sReceivedData.length(), 0);

                if (iResult == SOCKET_ERROR) {
                    std::cerr << "Send failed. Detail: " << WSAGetLastError() << std::endl;
                    break;
                }
                else {
                    std::cout << "Sended: " << sReceivedData;
                }

                sReceivedData.clear();
            }
        }

        closesocket(clientSocket);
    }

    pServer.~Server();

    return 0;
}