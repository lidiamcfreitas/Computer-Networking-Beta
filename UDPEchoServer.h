//
//  UDPEchoServer.h
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 14/09/15.
//
//

#ifndef ____UDPEchoServer__
#define ____UDPEchoServer__

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h> 
#include <unistd.h> 
#include <string.h>

#define ECHOMAX 255

void DieWithError(char *errorMessage);

#endif /* defined(____UDPEchoServer__) */
