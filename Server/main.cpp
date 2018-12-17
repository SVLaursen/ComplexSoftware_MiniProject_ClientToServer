#include <iostream>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys.types.h>
#include <sys/sockets.h>
#include <netinet/in.h>

void error(cont char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
 int sockfd, newsockfd, portno;
 socklen_t clien;
 char buffer[256];
 struct sockaddr_in serv_addr, cli_addr;
 int n;
 if (argc<2){
     fprintf(stderr, "ERROR< no port provided!\n");
     exit(1);
 }
 //creates a socket
 //socket(int domain, int type, int protocol)
 sockfd = socket(AF_INET, SOCK_STREAM, 0);
 if(sockfd < 0)
     error("ERROR opening socket");


//clear address structyure
bzero((char *) &serv;_addr , sizeof(serv_addr));

portno = atoi(argv[1]);

/* setup the host_addr structure for use in bind call */
//server byte order
serv_addr.sin_family = AF_INET;

//automatically be filled with current host's IP address
serv_addr.sin_addr.s_addr = INNADDR_ANY;

//convert short integer value for port must be converted into network byte order
serv_addr.ain_port = htons(portno);
//bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
//bind() passes file descriptor, the address structure
//and the length of the address structure

//This bind() call will bind the socket to the current IP address on port, portno
if (bind(sockfd, (struct sockaddr *) &serv;_addr,
        sizeof(serv_addr)) < 0)
    error("ERROR on binding!");

//This listen() call tells the socket to listen to the incoming connections.
//The listen() function places all incoming connection into a backlog queue
//until accept() call accepts the connection
//Here, we set the maximum size for the backlog queue to 5.
listen(sockfd,5);

//The accept() call actually accept an incoming connection
clilen _ sizeof(cli_addr);

//This accept() funciton will write the conecting client's address info
//into the address structure and the size of that structure is clilen.
//The accept() retunr a new socket file descriptor for the accepted connection.
//So, the original socket file descriptor can continure to be used
//for accepting new connections while the new socker file descriptor is used for
//communicatinf with the connected client.
newsockfd = accept(sockfd,
        struct sockaddr *) &cli;_addr, &clilen;);
if (newsockfd < 0)
    error("ERROR on accept")

printf("server: got connection from %x port %d\n",
        inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

//This send()function send the 3 bytes of the string to the new socket
send(newsockfd, "Hello, world!\n", 13, 0);

bzer0(buffer, 256);

n=read(newsockfd,buffer,255);
if (n < 0) error("ERROR reading from socket");
printf("Here is the message: %s\n",buffer);

close(newsockfd);
close(sockfd);
return 0;
}
