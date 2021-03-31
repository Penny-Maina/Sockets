#include <stdio.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/socket.h>

#include <netinet/in.h>

int main () {
    //create a socket
    int networkSocket;      //contains info about the socket
    networkSocket = socket(AF_INET, SOCK_STREAM, 0);        //SOCK_STREAM is the type of socket, 0 specifies the protocol
    
    //specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9002); //Endpoint Port Number
    server_address.sin_addr.s_addr = INADDR_ANY;       //Endpoint Address

    //Connecting to server
    int connectionStatus = connect(networkSocket, (struct sockaddr *) &server_address, sizeof(server_address));    //returns an integer to show if the connection is successful or not. 0 is ok

    //check for error with the connection
    if(connectionStatus == -1) {
        printf("There was an error making a connection to the remote socket \n\n");
    }
    //receive data from the socket
    char serverResponse[256];
    recv(networkSocket, &serverResponse, sizeof(serverResponse), 0);

    //print out the server's response
    printf("The server sent the data: %s\n", serverResponse);

    //close the socket
    pclose(networkSocket);
    return 0;

}