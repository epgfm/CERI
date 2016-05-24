S = src
O = obj
I = include

C = g++ -O2 -I $(I)/

OBJECTS = $(O)/othello.o $(O)/ia.o $(O)/stats.o $(O)/player.o $(O)/misc.o \
		  $(O)/client-jeu.o

HEADERS = $(I)/othello.h $(I)/stats.h $(I)/player.h $(I)/misc.h \
		  $(I)/client-jeu.h

all : main

main : main.cpp $(OBJECTS) $(HEADERS)
	$(C) $< $(OBJECTS) -o $@

$(O)/%.o : $(S)/%.cpp $(HEADERS)
	$(C) -c $< -o $@

clean :
	rm -f main $(O)/*.o *~ $(S)/*~ $(I)/*~
