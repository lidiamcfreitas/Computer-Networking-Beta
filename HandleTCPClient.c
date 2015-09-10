//
//  HandleTCPClient.c
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 09/09/15.
//
//

#include <stdio.h>
#include <sys/socket.h>
#include <unistd.h>

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

void HandleTCPClient(int clntSocket)
{
    char echoBuffer[RCVBUFSIZE];
    int recvMsgSize;
    
    if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0))<0)
        DieWithError("recv() failed");
    
    while (recvMsgSize>0) {
        if (recvMsgSize != send(clntSocket, echoBuffer, recvMsgSize, 0))
            DieWithError("send() failed");
        
        if ((recvMsgSize = recv(clntSocket, echoBuffer, RCVBUFSIZE, 0))<0)
            DieWithError("recv() failed");
    }
    close(clntSocket);
    
}