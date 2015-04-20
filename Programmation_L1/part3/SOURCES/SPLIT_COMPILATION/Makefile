all : main


main : main.cpp toto.o tata.o
	g++ main.cpp toto.o tata.o -o main

toto.o : toto.cpp toto.h
	g++ -c toto.cpp -o toto.o

tata.o : tata.cpp tata.h
	g++ -c tata.cpp -o tata.o

clean :
	rm -f main toto.o tata.o *~


