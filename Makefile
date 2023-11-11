OSFLAG 				:=
ifeq ($(OS),Windows_NT)
	OSFLAG += WINDOWS
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Linux)
		OSFLAG += LINUX
	endif
endif

all: client server

client: client.cpp konsole.h konsole.cpp chess.h chess.cpp
	g++ client.cpp konsole.cpp chess.cpp -o Client

server: server.cpp konsole.h konsole.cpp chess.h chess.cpp
	g++ server.cpp konsole.cpp chess.cpp -o Server

clean:
ifeq ($(OSFLAG),WINDOWS)
	del Client.exe
	del Server.exe
else ifeq ($(OSFLAG),LINUX)
	rm Client.exe
	rm Server.exe
endif