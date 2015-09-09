CC=gcc
CFLAGS=-c -Wall

all: TCPEchoClient Server

TCPEchoClient: TCPEchoClient.o DieWithError.o
	$(CC) TCPEchoClient.o DieWithError.o -o TCPEchoClient

Server: Server.o
	$(CC) Server.o -o Server

TCPEchoClient.o: TCPEchoClient.c
	$(CC) $(CFLAGS) TCPEchoClient.c

DieWithError.o: DieWithError.c
	$(CC) $(CFLAGS) DieWithError.c

Server.o: Server.c
	$(CC) $(CFLAGS) Server.c
clean:
	rm *.o
