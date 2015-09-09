//
//  TCPEchoServer.h
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 09/09/15.
//
//

#ifndef ____TCPEchoServer__
#define ____TCPEchoServer__

#include <stdio.h>      /* printf and fprintf */
#include <stdlib.h>     /* atoi */
#include <sys/socket.h> /* socket, bind, connect */
#include <string.h>     /* memset */
#include <arpa/inet.h>  /* sockaddr_in, inet_ntoa */
#include <unistd.h>     /* close */

#define MAXPENDING 5

void DieWithError(char *errorMessage);
void HandleTCPClient(int clntSocket);


#endif /* defined(____TCPEchoServer__) */
