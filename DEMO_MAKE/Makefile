C=g++

OBJ=libgeometry/obj
LIB=libgeometry/lib
SRC=libgeometry/src
INC=libgeometry/include

run : bin/tester.exe
	./bin/tester.exe

# Note: $< is a make shortcut for the first listed dependency.
# Note: $@ is a make shortcut for the target file.

bin/tester.exe : src/main.cpp $(LIB)/libgeometry.a
	$(C) -I $(INC) $< -lgeometry -L $(LIB) -o $@ # The order is important!
                                                 # $< (src/main.cpp) comes
                                                 # before the link to the
                                                 # library, because it depends
                                                 # on it.

$(LIB)/libgeometry.a : $(OBJ)/circle.o $(OBJ)/square.o
	ar rv $@ $(OBJ)/circle.o $(OBJ)/square.o

$(OBJ)/circle.o : $(SRC)/circle.cpp $(INC)/circle.h
	$(C) -c -I $(INC) $< -o $@

$(OBJ)/square.o : $(SRC)/square.cpp $(INC)/square.h
	$(C) -c -I $(INC) $< -o $@


clean :
	find . -type f -regextype posix-egrep -regex ".*\.?(exe|[ao~])$$" \
	               -exec rm -f '{}' \;
	rm -f dirmap

map :
	find . > dirmap ; grep --color / < dirmap









