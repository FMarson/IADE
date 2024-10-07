#include <iostream>
#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#pragma comment(lib, "ws2_32.lib")  // Link the Winsock library

#define PORT 8080

using namespace std; // Using the namespace

int main() {
    WSADATA wsaData;
    SOCKET sock;
    struct sockaddr_in serv_addr;

    // Initialize Winsock
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        cerr << "Failed to initialize Winsock" << endl;
        return -1;
    }

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) {
        cerr << "Failed to create socket" << endl;
        WSACleanup();
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0) {
        cerr << "Invalid address/ Address not supported" << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    // Connect to the server
    if (connect(sock, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == SOCKET_ERROR) {
        cerr << "Connection failed" << endl;
        closesocket(sock);
        WSACleanup();
        return -1;
    }

    char idBuffer[1024] = { 0 };

    // Receive client ID
    recv(sock, idBuffer, sizeof(idBuffer), 0);
    cout << idBuffer << endl; // Display the received client ID

    string message;

    // Loop to send messages until "exit" is typed
    while (true) {
        cout << "Enter message to send (type 'exit' to quit): ";
        getline(cin, message);

        // Check if the user wants to exit
        if (message == "exit") {
            break;
        }

        // Send the message to the server
        send(sock, message.c_str(), message.length(), 0);

        char buffer[1024] = { 0 };
        recv(sock, buffer, sizeof(buffer), 0);

        cout << "Response from server: " << buffer << endl;
    }

    closesocket(sock);
    WSACleanup();

    return 0;
}
