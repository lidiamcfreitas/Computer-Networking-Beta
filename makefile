CC=gcc
CFLAGS=-c -Wall

all: TCP UDP

TCP: TCPEchoClient TCPEchoServer
UDP: UDPEchoClient

TCPEchoClient: TCPEchoClient.o DieWithError.o
	$(CC) TCPEchoClient.o DieWithError.o -o TCPEchoClient

TCPEchoServer: TCPEchoServer.o HandleTCPClient.o DieWithError.o
	$(CC) TCPEchoServer.o HandleTCPClient.o DieWithError.o -o TCPEchoServer

UDPEchoClient: UDPEchoClient.o DieWithError.o
	$(CC) UDPEchoClient.o DieWithError.o -o UDPEchoClient

TCPEchoClient.o: TCPEchoClient.c
	$(CC) $(CFLAGS) TCPEchoClient.c

TCPEchoServer.o: TCPEchoServer.c
	$(CC) $(CFLAGS) TCPEchoServer.c

UDPEchoClient.o: UDPEchoClient.c
	$(CC) $(CFLAGS) UDPEchoClient.c

DieWithError.o: DieWithError.c
	$(CC) $(CFLAGS) DieWithError.c

HandleTCPClient.o: HandleTCPClient.c
	$(CC) $(CFLAGS) HandleTCPClient.c

clean:
	rm *.o
