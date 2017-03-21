all: program

program: plik.o main.o 
			g++ plik.o main.o  -o program

plik.o:  plik.cpp plik.h 
			g++ -c -Wall plik.cpp

program.o: main.cpp
			g++ -c -Wall main.cpp

clean: 
	rm -rf *o prog
