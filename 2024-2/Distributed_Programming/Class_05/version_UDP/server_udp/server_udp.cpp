#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")  // Link the Winsock library

#define PORT 8080
#define BUFFER_SIZE 1024

using namespace std; // Using the namespace

int main() {
    WSADATA wsaData;
    SOCKET serverSocket;
    struct sockaddr_in serverAddr, clientAddr;
    int addrLen = sizeof(clientAddr);
    char buffer[BUFFER_SIZE];

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return -1;
    }

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return -1;
    }

    // Configure server address
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
    serverAddr.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        cerr << "Failed to bind the socket" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    cout << "Waiting for messages..." << endl;

    while (true) {
        int bytesReceived = recvfrom(serverSocket, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&clientAddr, &addrLen);
        if (bytesReceived == SOCKET_ERROR) {
            cerr << "Error receiving data" << endl;
            continue;
        }

        buffer[bytesReceived] = '\0'; // Null-terminate the received string
        cout << "Message received from client: " << buffer << endl;

        // Send response to client
        const char* response = "Hello from the server!";
        sendto(serverSocket, response, strlen(response), 0, (struct sockaddr*)&clientAddr, addrLen);
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
