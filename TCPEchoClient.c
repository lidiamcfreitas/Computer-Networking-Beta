//
//  TCPEchoClient.c
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 09/09/15.
//
//

#include "TCPEchoClient.h"

int main(int argc, char *argv[])
{
    int socket_fd;
    struct sockaddr_in echoServAddr;
    unsigned short echoServPort;
    char *servIP;
    char *echoString;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRcvd, totalBytesRcvd;
    
    if(argc <3 || argc >4)
    {
        fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
        exit(1);
    }
    
    servIP = argv[1];
    echoString = argv[2];
    
    if (argc==4)
        echoServPort = atoi(argv[3]);
    else
        echoServPort = 7; /* 7 is the port for the echo service */
    
    if((socket_fd = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
        DieWithError("socket() failed");
    
    /* construct server address structure */
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);
    
    if(connect(socket_fd, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr))<0)
        DieWithError("connect() failed");
    
    echoStringLen = strlen(echoString);
    
    if(send(socket_fd, echoString, echoStringLen, 0)!= echoStringLen)
        DieWithError("send() sent a different number of bytes than expected");
    
    totalBytesRcvd = 0;
    printf("Received:");
    while (totalBytesRcvd< echoStringLen) {
        
        if ((bytesRcvd = recv(socket_fd, echoBuffer, RCVBUFSIZE-1, 0))<=0)
            DieWithError("recv() failed or connection closed prematurely");
        totalBytesRcvd += bytesRcvd;
        echoBuffer[bytesRcvd]= '\0';
        printf(echoBuffer);
    }
    
    printf("\n");
    close(socket_fd);
    exit(0);
}