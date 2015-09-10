//
//  TCPEchoServer.c
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 09/09/15.
//
//

#include "TCPEchoServer.h"

int main(int argc, char* argv[])
{
    int servSock, clntSock;
    struct sockaddr_in echoServAddr, echoClntAddr;
    unsigned short echoServPort;
    unsigned int clntLen;
    
    if (argc!=2) {
        fprintf(stderr, "Usage: %s <Server Port>\n", argv[0]);
        exit(1);
    }
    
    echoServPort = atoi(argv[1]);
    
    if ((servSock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP))<0)
        DieWithError("socket() failed");
    
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = INADDR_ANY;
    echoServAddr.sin_port = htons(echoServPort);
    
    if (bind(servSock, (struct sockaddr*) &echoServAddr, sizeof(echoServAddr))<0) {
        DieWithError("bind() failed");
    }
    
    if (listen(servSock, MAXPENDING)<0) {
        DieWithError("listen() failed");
    }
    
    for(;;)
    {
        clntLen = sizeof(echoClntAddr);
        if ((clntSock = accept(servSock, (struct sockaddr*) &echoClntAddr, &clntLen))<0) {
            DieWithError("accept() failed");
        }
        
        printf("Handling client %s\n", inet_ntoa(echoClntAddr.sin_addr));
        
        HandleTCPClient(clntSock);
    }
    
}
