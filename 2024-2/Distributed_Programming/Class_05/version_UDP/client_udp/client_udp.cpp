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
    SOCKET sock;
    struct sockaddr_in servAddr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return -1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return -1;
    }

    servAddr.sin_family = AF_INET;
    servAddr.sin_port = htons(PORT);

    // Convert IPv4 address from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &servAddr.sin_addr) <= 0) {
        cerr << "Invalid address/ Address not supported" << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    string message;

    // Loop to send messages until "exit" is typed
    while (true) {
        cout << "Enter message to send (type 'exit' to quit): ";
        getline(cin, message);

        // Check if the user wants to exit
        if (message == "exit") {
            break;
        }

        // Send message to server
        sendto(sock, message.c_str(), message.length(), 0, (struct sockaddr*)&servAddr, sizeof(servAddr));

        char buffer[BUFFER_SIZE] = { 0 };
        int addrLen = sizeof(servAddr);

        // Receive response from server
        int bytesReceived = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&servAddr, &addrLen);

        if (bytesReceived > 0) {
            buffer[bytesReceived] = '\0'; // Null-terminate the received string
            cout << "Response from server: " << buffer << endl;
        }
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}
