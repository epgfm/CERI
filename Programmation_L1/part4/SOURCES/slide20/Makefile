all : main

main : main.cpp chaine.o
	g++ $< chaine.o -o $@

chaine.o : chaine.cpp chaine.h
	g++ -c $< -o $@

clean :
	rm -f main chaine.o *~


