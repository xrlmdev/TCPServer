# TCPServer

This is a simple single-threaded TCP server written in C++.

## Features
- Accepts TCP connections on a specified port.
- Converts incoming text to uppercase and echoes it back to the client.
- Supports command-line argument `--port` to specify the server port.
- Includes error handling for socket operations.

## Prerequisites
- **Operating System:** Windows (tested on Windows 10/11).
- **Compiler:** Microsoft C++ Compiler (MSVC) or compatible (e.g., Visual Studio).
- **Libraries:** 
  - Winsock2 (`Ws2_32.lib` included in Windows SDK).
- **Tools:**
  - Telnet, Netcat (nc) for testing.

## Installation
Clone this repository:
   ```cmd
   git clone https://github.com/xrlmdev/TCPServer.git
   cd TCPServer
   ```
## Server running
  ```cmd
  chcp 1251
  TCPServer.exe --port 8080
  ```
## Server testing using Telnet
  ```cmd
  chcp 1251
  telnet localhost 8080
  ```
