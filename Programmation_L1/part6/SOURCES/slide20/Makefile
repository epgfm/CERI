all : main

main : main.cpp test.o
	g++ $< test.o -o $@

test.o : test.cpp test.h
	g++ -c $< -o $@

clean :
	rm -f main test.o *~


