#pragma once

#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <algorithm>

#pragma comment(lib, "Ws2_32.lib")

#define BUFFER_SIZE 1024