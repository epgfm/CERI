all : main

main : main.cpp point.o
	g++ $< point.o -o $@

point.o : point.cpp point.h
	g++ -c $< -o $@

clean :
	rm -f main point.o *~

