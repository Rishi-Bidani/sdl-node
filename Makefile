output: cpp/main.o cpp/classes/Rect.o
	g++ -Isrc/Include -Lsrc/lib/x64 -Icpp/classes main.o Rect.o Clock.o -o output -lSDL2main -lSDL2

main.o: cpp/main.cpp
	g++ -c cpp/main.cpp

Rect.o: cpp/classes/Rect.cpp
	g++ -c cpp/classes/Rect.cpp

Clock.o: cpp/classes/Clock.cpp
	g++ -c cpp/classes/Clock.cpp

clean:
	rm *.o output

#all:
#	g++ -Isrc/Include -Lsrc/lib/x64 -Icpp/classes -o main ./cpp/main.cpp /cpp/classes/Rect.cpp -lSDL2main -lSDL2