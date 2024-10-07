#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")  // Link the Winsock library

#define PORT 8080

int main() {
    WSADATA wsaData;
    SOCKET server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[1024] = { 0 };

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cerr << "Failed to initialize Winsock" << std::endl;
        return -1;
    }

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        std::cerr << "Failed to create socket" << std::endl;
        WSACleanup();
        return -1;
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        std::cerr << "Failed to bind the socket" << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    // Listen for connections
    if (listen(server_fd, 3) == SOCKET_ERROR) {
        std::cerr << "Failed to listen" << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    std::cout << "Waiting for connection..." << std::endl;

    // Accept a connection
    if ((new_socket = accept(server_fd, (struct sockaddr*)&address, &addrlen)) == INVALID_SOCKET) {
        std::cerr << "Failed to accept connection" << std::endl;
        closesocket(server_fd);
        WSACleanup();
        return -1;
    }

    // Read data from client
    recv(new_socket, buffer, sizeof(buffer), 0);
    std::cout << "Message received: " << buffer << std::endl;

    // Send response to client
    const char* hello = "Hello from the server!";
    send(new_socket, hello, strlen(hello), 0);

    closesocket(new_socket);
    closesocket(server_fd);
    WSACleanup();

    return 0;
}
