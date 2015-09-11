//
//  UDPEchoClient.h
//  
//
//  Created by Lídia Maria Carvalho de Freitas on 11/09/15.
//
//

#ifndef ____UDPEchoClient__
#define ____UDPEchoClient__

#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <string.h> 

#define ECHOMAX 255

void DieWithError(char *errorMessage);

#endif /* defined(____UDPEchoClient__) */
