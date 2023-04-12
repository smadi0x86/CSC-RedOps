/*
This code is meant to be executed in a linux machine.
*/

#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <stdlib.h>

int main()
{
    // Integer variable for creating the socket
    int server_socket;

    /*
    Creating the TCP socket: socket(domain, type, protocol)

    AF_INET: Means that we have to use the ipv4 address, if we use AF_INET6 it would be ipv6, etc.
    SOCK_STREAM: Means that we are going to use TCP protocol, if we use SOCK_DGRAM it would be UDP, etc.
    0: Means that we are going to use the default protocol which is TCP, if we use 1 it would be UDP, etc.

    Read more: https://www.geeksforgeeks.org/socket-programming-cc/
    */
    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    // Structure required for the connection to be accepted ( bind() )
    // A structure is a collection of variables of different types
    struct sockaddr_in server_address;

    /*
        IMPORTANT: These structure .sin_family, .sin_port, .sin_addr.s_addr are used to store the address of the client which came from the header <netinet/in.h>
    */

    // This is the structure that will be used to store the client address
    server_address.sin_family = AF_INET;

    // This is the port that will be used for the connection
    // htons() function is used to convert the port number to the correct format, 9002 is the port number, it can be any number
    server_address.sin_port = htons(1337);

    // This is the IP address that will be used for the connection
    // inet_addr() function is used to convert the IP address to the correct format
    server_address.sin_addr.s_addr = inet_addr("YOUR IP ADDRESS");

    // --------------------------------------------------------------------------------------------------------------

    /*
    Binding the socket to our specified IP and port: bind(socket, address, address_len)

    1. Pass the socket that we created before
    2. Pass a pointer to the structure that we created before, (struct server_address *) "*" is used to convert the structure to a pointer
    3. Pass the address of the structure that we created before ( &server_address ) "&" is used to get the address of the variable
    4. Pass the size of the structure, sizeof(server_address) is used to get the size of the variable

    Manual for bind(): https://man7.org/linux/man-pages/man2/bind.2.html
    */
    bind(server_socket, (struct server_address *)&server_address, sizeof(server_address));

    // --------------------------------------------------------------------------------------------------------------

    /*
    Listening for connections: listen(socket, backlog)

    1. Pass the socket that we created before
    2. Pass the backlog, 5 is used because it is the maximum number of connections that can be queued

    Manual for listen(): https://man7.org/linux/man-pages/man2/listen.2.html
    */
    listen(server_socket, 5);

    // --------------------------------------------------------------------------------------------------------------

    // Used for accepting the connection
    int client_socket;

    /*
     Accepting the connection: accept(socket, address, address_len)

     It takes 3 arguments, the socket, the address of the client and the size of the address
     NULL is used because we don't need the address of the client and the size of the address

     Manual for accept(): https://man7.org/linux/man-pages/man2/accept.2.html
    */
    client_socket = accept(server_socket, NULL, NULL);
    printf("Client connected! \n");

    // --------------------------------------------------------------------------------------------------------------

    // This server_message variable will be sent to the client when the connection is accepted
    char server_message[256] = "You have reached the server!";
    // This client_message variable will be sent to the server when the connection is accepted
    char client_message[256] = "You have reached the client!";

    /*
    Sending the message to the client: send(socket, message, message_len, flags)

    1. Pass the socket that we created before
    2. Pass the message that we want to send
    3. Pass the size of the message, sizeof(server_message) is used to get the size of the variable
    4. Pass the flags, 0 is used because we don't need any flags

    Manual for send(): https://man7.org/linux/man-pages/man2/send.2.html
    */
    send(client_socket, server_message, sizeof(server_message), 0);
    recv(client_socket, client_message, sizeof(client_message), 0);
    printf("Client sent: %s \n", client_message);

    // --------------------------------------------------------------------------------------------------------------

    // Closing the socket
    close(server_socket);

    return 0;
}
