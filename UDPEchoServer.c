//
//  UDPEchoServer.c
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 14/09/15.
//
//

#include "UDPEchoServer.h"

int main(int argc, char *argv[]){
    
    int sock;
    struct sockaddr_in echoServAddr;
    struct sockaddr_in echoClntAddr;
    unsigned int cliAddrLen;
    char echoBuffer[ECHOMAX];
    unsigned short echoServPort;
    int recvMsgSize;
    
    if (argc!=2) {
        fprintf(stderr, "Usage: %s <UDP SERVER PORT>\n", argv[0]);
        exit(1);
    }
    
    echoServPort = atoi(argv[1]);
    
    if ((sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP))<0))
        DieWithError("socket() failed");
    
    memset(&echoServAddr, 0, sizeof(echoServAddr));
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    echoServPort.sin_port = htons(echoServPort);
    
    if (bind(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr))<0)
        DieWithError("bind() failed");
    
    for (;;) {
        cliAddrLen = sizeof(echoClntAddr);
        
        if ((recvMsgSize = recvfrom(sock, echoBuffer, ECHOMAX, 0, (struct sockaddr*) &echoClntAddr, &cliAddrLen))<0)
            DieWithError("recvfrom() failed");
        
        printf("Handling Client %s\n", inet_ntoa(echoClntAddr.sin_addr));
        
        if (sendto(sock, echoBuffer, recvMsgSize, 0, (struct sockaddr*) &echoClntAddr, sizeof(echoClntAddr))!= recvMsgSize)
            DieWithError("sendto() sent a different number of bytes than expected");
        
    }
    
}