#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main() {
    char serverMessage[256] = "You have reached the server!";

    //create the server socket
    int serverSocket;
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);

    //define the server address
    struct sockaddr_in serverAddress;
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(9002); //Endpoint Port Number
    serverAddress.sin_addr.s_addr = INADDR_ANY;     //Endpoint IP Address

    //bind the socket to our specified IP and port
    bind(serverSocket, (struct sockaddr*) &serverAddress, sizeof(serverAddress));

    listen(serverSocket, 5);

    //Connecting to the client socket
    int clientSocket;
    clientSocket = accept(serverSocket, NULL, NULL);

    //send the message to the client
    send(clientSocket, serverMessage, sizeof(serverMessage), 0);

    //close the socket
    pclose(serverSocket);
    return 0;
}