all: client server

client: client.cpp konsole.h konsole.cpp chess.h chess.cpp
	g++ client.cpp konsole.cpp chess.cpp -o Client

server: server.cpp konsole.h konsole.cpp chess.h chess.cpp
	g++ server.cpp konsole.cpp chess.cpp -o Server

clean:
	del Client.exe
	del Server.exe