
C=g++ -O2 -Wall
I=-I.


main : main.cpp Heap.o
	$(C) $(I) $^ -o $@

run : main
	./main

clean :
	rm -f *.o *~ main

Heap.o : Heap.cpp Heap.h
	$(C) -c $(I) $< -o $@

