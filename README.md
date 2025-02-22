# TCPServer

This is a simple single-threaded TCP server written in C++ using the Winsock2 API for Windows. The server accepts connections from clients, receives text input, converts it to uppercase, and sends it back. It supports basic error handling, command-line port specification, and optional Cyrillic (Russian) character support.

## Features
- Accepts TCP connections on a specified port (default: 8080).
- Converts incoming text to uppercase and echoes it back to the client.
- Supports command-line argument `--port` to specify the server port.
- Includes error handling for socket operations.
- Optional support for Cyrillic characters (Windows-1251 or UTF-8).

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
