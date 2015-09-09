#include <stdio.h>      /* for printf() and fprintf() */
#include <sys/socket.h> /* for socket(), connect(), send(), and recv() */
#include <arpa/inet.h>  /* for sockaddr_in and inet_addr() */
#include <stdlib.h>     /* for atoi() and exit() */
#include <string.h>     /* for memset() */
#include <unistd.h>     /* for close() */

#define PORT 7

int server_sock (int port) {
    struct sockaddr_in Me;
    int sock;
    if ((sock=socket(PF_INET, SOCK_STREAM, 0))<3) perror("socket");
    Me.sin_family=AF_INET;
    Me.sin_port=htons(port);
    Me.sin_addr.s_addr=INADDR_ANY;
    memset(&(Me.sin_zero), '\0', 8);
    if (bind(sock,(struct sockaddr*)&Me,sizeof(struct sockaddr))==-1) perror("bind");
    if (listen(sock,2)!=0) perror("listen");
    return sock;
}

int main() {
    char buffer[256];
    struct sockaddr_in info;
    socklen_t size=sizeof(struct sockaddr_in);
    int self = server_sock(PORT),
    other = accept(self,(struct sockaddr*)&info,&size);
    
    recv(other,buffer,255,0);
    send(other,buffer,strlen(buffer),0);
    close(other);
    close(self);
    
    return 0;
}