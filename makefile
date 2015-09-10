CC=gcc
CFLAGS=-c -Wall

all: TCPEchoClient TCPEchoServer

TCPEchoClient: TCPEchoClient.o DieWithError.o
	$(CC) TCPEchoClient.o DieWithError.o -o TCPEchoClient

TCPEchoServer: TCPEchoServer.o HandleTCPClient.o DieWithError.o
	$(CC) TCPEchoServer.o HandleTCPClient.o DieWithError.o -o TCPEchoServer

TCPEchoClient.o: TCPEchoClient.c
	$(CC) $(CFLAGS) TCPEchoClient.c

DieWithError.o: DieWithError.c
	$(CC) $(CFLAGS) DieWithError.c

HandleTCPClient.o: HandleTCPClient.c
	$(CC) $(CFLAGS) HandleTCPClient.c

TCPEchoServer.o: TCPEchoServer.c
	$(CC) $(CFLAGS) TCPEchoServer.c
clean:
	rm *.o
