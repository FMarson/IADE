#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <thread>  // For using threads

#pragma comment(lib, "ws2_32.lib")  // Link the Winsock library

#define PORT 8080

using namespace std; // Using the namespace

// Function to handle each client
void handleClient(SOCKET clientSocket, int clientID) {
    char buffer[1024] = { 0 };

    // Send the client ID
    string idMessage = "Your client ID is: " + to_string(clientID);
    send(clientSocket, idMessage.c_str(), idMessage.length(), 0);

    // Read data from the client
    recv(clientSocket, buffer, sizeof(buffer), 0);
    cout << "Message received from client [" << clientID << "]: " << buffer << endl;

    // Send response to the client
    const char* response = "Hello from the server!";
    send(clientSocket, response, strlen(response), 0);

    closesocket(clientSocket);  // Close the client socket
}

int main() {
    WSADATA wsaData;
    SOCKET serverSocket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    int clientIDCounter = 0; // Client ID counter

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return -1;
    }

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return -1;
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY; // Listen on all available interfaces
    address.sin_port = htons(PORT);

    // Bind the socket to the address
    if (bind(serverSocket, (struct sockaddr*)&address, sizeof(address)) == SOCKET_ERROR) {
        cerr << "Failed to bind the socket" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    // Listen for connections
    if (listen(serverSocket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "Failed to listen" << endl;
        closesocket(serverSocket);
        WSACleanup();
        return -1;
    }

    cout << "Waiting for connections..." << endl;

    while (true) {
        SOCKET newSocket = accept(serverSocket, (struct sockaddr*)&address, &addrlen);
        if (newSocket == INVALID_SOCKET) {
            cerr << "Failed to accept connection" << endl;
            continue;  // Continue accepting more clients
        }

        clientIDCounter++; // Increment the ID counter
        thread clientThread(handleClient, newSocket, clientIDCounter); // Create a new thread for each client
        clientThread.detach();  // Detach the thread to allow it to run independently
    }

    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
