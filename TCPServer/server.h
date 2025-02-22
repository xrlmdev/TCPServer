#pragma once

class Server {
private:
	SOCKET serverSocket;
	WSADATA wsaData;
public:
	Server(short sPort = 8080);
	~Server();
	SOCKET GetSocket();
};