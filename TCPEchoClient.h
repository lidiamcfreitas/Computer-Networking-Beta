//
//  TCPEchoClient.h
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 09/09/15.
//
//

#ifndef ____TCPEchoClient__
#define ____TCPEchoClient__

#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <stdlib.h>
#include <string.h> 
#include <unistd.h> 

#define RCVBUFSIZE 32

void DieWithError(char *errorMessage);

#endif /* defined(____TCPEchoClient__) */
