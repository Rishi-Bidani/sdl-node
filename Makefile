all:
	g++ -Isrc/Include -Lsrc/lib/x64 -o main main.cpp -lSDL2main -lSDL2